
/*
   Name: Jared Adamson
   Description: Modifcation of prior Maze, this time using recursion to produce maze.
*/         




//INCLUDES
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h> 
#include "Console_Util.h"

//MACROS (VS)

#pragma warning(disable: 4996)

//MACROS (CONSTANTS)

#define LEVEL_WIDTH CONSOLE_WIDTH		//use entire width of console.
#define LEVEL_HEIGHT (CONSOLE_HEIGHT-1)	//minus one, so one line free for text at bottom.

//set of ASCII characters to use as icons
#define ICON_BLANK ' '
#define ICON_WALL '#'
#define ICON_GOAL 'G'
#define ICON_PLAYER '!'

//maximum length of strings (including terminator).
#define MAX_STR_LEN 1024

//save file
#define SAVE_TIMES "times.dat"

//STRUCTURES

//stores player's position.
struct Vector
{
	//in our coordinate system, the top left character is the origin at 0.0.
	//x increases to the right while y increases downward.
	int x;
	int y;
};

//stores player's best time.
struct PlayerTime {	
	char		name[MAX_STR_LEN];
	float		seconds;
	struct PlayerTime* next;
};

//GLOBAL VARIABLES
struct PlayerTime* list_head = NULL;


//FORWARD DECLARATIONS
void menu();
void menu_selection(char option);
void besttimes_view();
void besttimes_add(char name[MAX_STR_LEN], float seconds);
void besttimes_load();
void besttimes_save();
void besttimes_free(struct PlayerTime* node);
void play();
void generate_level(char level[LEVEL_HEIGHT][LEVEL_WIDTH]);
void draw_level(char level[LEVEL_HEIGHT][LEVEL_WIDTH]);
int is_walkable(char level[LEVEL_HEIGHT][LEVEL_WIDTH], int x, int y);
void move_player(struct Vector* player_position, int move_x, int move_y);
void make_maze(char level[LEVEL_HEIGHT][LEVEL_WIDTH], int new_width, int new_height);
void draw_walls(char level[LEVEL_HEIGHT][LEVEL_WIDTH]);

//entry point
void main()
{
	char input_buffer; 

	printf("\n\nWelcome to MAZE\n");

	//load best times
	besttimes_load();	

	//menu and input loop
	do
	{
		menu();

		input_buffer = tolower(getchar()); 
		dump_key_buffer();
		menu_selection(input_buffer);
	} 
	while (input_buffer != 'q');

	//save best times and free linked list
	besttimes_save();
	besttimes_free(list_head);
}

//displays a menu containing actions the user may choose.	
void menu()
{
	printf("\nMenu Options\n");
	printf("------------------------------------------------------\n");
	printf("p: Play\n");
	printf("v: View Best Times\n");
	printf("q: Quit\n");

	printf("\n\nPlease enter a choice ---> "); 
}

//takes a character representing an inputs menu choice and calls the appropriate
//function to fulfill that choice. Display an error message if the character is
//not recognized.
void menu_selection(char option)
{
	switch(option)
	{
	case 'p':
		play();
		break;

	case 'v':
		besttimes_view();
		break;

	case 'q':
		// main loop will take care of this.
		break;

	default:
		printf("\nError: Invalid Input.  Please try again..."); 
		break;
	}
}

void besttimes_view()
{
	struct PlayerTime* active_head = list_head;

	printf("---BEST TIMES---\n");

	if(active_head == NULL)
	{
		printf("No times yet!\n");	
	}
	else
	{
		while(active_head != NULL)
		{
			printf("%f : %s\n", active_head->seconds, active_head->name);	
			active_head = active_head->next;
		}
	}
}

void besttimes_add(char name[MAX_STR_LEN], float seconds)
{
	struct PlayerTime* active_head;
	struct PlayerTime* new_node;

	new_node = (struct PlayerTime*) malloc(sizeof(struct PlayerTime));

	if (new_node == NULL)
	{
		printf("Failed to allocate memory for new best time, skipping.");
		return;
	}
	
	strcpy(new_node->name, name);
	new_node->seconds = seconds;

	//need to insert at front if empty list or this is the smallested one
	if(list_head == NULL || new_node->seconds < list_head->seconds)
	{
		new_node->next = list_head;
		list_head = new_node;
	}
	//otherwise, need to insert somewhere in its tail.
	else 
	{
		//find sorted position
		active_head = list_head;
		while (active_head->next != NULL && new_node->seconds > active_head->next->seconds)
			active_head = active_head->next;

		new_node->next = active_head->next;
		active_head->next = new_node;
	}
}

void besttimes_load()
{
	FILE* file;
	char name[MAX_STR_LEN];
	float seconds;

	file = fopen(SAVE_TIMES, "r");

	if(file != NULL)
	{
		while(fread(name, MAX_STR_LEN, 1, file) == 1)
		{	
			fread(&seconds, sizeof(float), 1, file);

			//reuse add function so we don't have to deal with the list
			besttimes_add(name, seconds);
		}

		fclose(file);
	}
}

void besttimes_save()
{
	FILE* file;
	struct PlayerTime* active_head = list_head;

	file = fopen(SAVE_TIMES, "w");

	if(file != NULL)
	{
		while(active_head != NULL)
		{
			fwrite(active_head->name, MAX_STR_LEN, 1, file);
			fwrite(&active_head->seconds, sizeof(float), 1, file);

			active_head = active_head->next;
		}

		fclose(file);
	}
	else 
		printf ("ERROR: Could not open file for saving data!\n");
}


void besttimes_free(struct PlayerTime* node)
{
	if (node == NULL) 
	{
		return;
	}
	else
	{
		besttimes_free(node->next);
		free(node);
	}
}

void initalize_maze(char level[LEVEL_HEIGHT][LEVEL_WIDTH]){
	char walls[LEVEL_HEIGHT][LEVEL_WIDTH];
	int x,y;
	
	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			walls[y][x] = ' ';

	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			level[y][x] = walls[y][x];

}

void initalize_boundry(char level[LEVEL_HEIGHT][LEVEL_WIDTH]){
    char walls[LEVEL_HEIGHT][LEVEL_WIDTH];
	int x,y;

	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
	     walls[y][x] = level[y][x];

	for (x = 0; x < LEVEL_WIDTH; x++)
		walls[0][x] = '#';
	
	for (x = 0; x < LEVEL_WIDTH; x++)
		walls[LEVEL_HEIGHT - 1][x] = '#';

	for (y = 0; y < LEVEL_HEIGHT; y++)
		walls[y][0] = '#';

	for (y = 0; y < LEVEL_HEIGHT; y++)
		walls[y][LEVEL_WIDTH - 1] = '#';
	
	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			level[y][x] = walls[y][x];

}



void make_maze(char level[LEVEL_HEIGHT][LEVEL_WIDTH], int new_width, int new_height){
	
	int randomX = rand() % new_width ;
	int randomY = rand() % (new_height);
	int randdoorX =  rand() % (new_width/2) ;
	int randdoorY =  rand() % (new_height/2) ;
    int randdoorX2 =  rand() % (new_width/2) ;
	int randdoorY2 =  rand() % (new_height/2) ;
	int x,y;
	
	

	char walls[LEVEL_HEIGHT][LEVEL_WIDTH];
		
	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			walls[y][x] = level[y][x];

	
	for (x = 0; x < new_width; x++)
		walls[randomY][x] = '#';
	
	walls[randomY][randdoorX ] = ' ';
	walls[randomY][randdoorX2 + (new_width/2)] = ' ';
	
	for (y = 0; y < new_height; y++)
		walls[y][randomX] = '#';

	walls[randdoorY + 1][randomX] = ' ';
	walls[randdoorY2 + (new_height/2)][randomX] = ' ';


		for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			level[y][x] = walls[y][x];

		if(new_width > 3 && new_height > 3){
		new_width = new_width* 0.7;
		new_height = new_height * 0.7;
		make_maze(level, new_width, new_height);
			
	}	
	
}


void play()
{
	//define the main 2d array. it has a size that is constant at compile time.
	char level[LEVEL_HEIGHT][LEVEL_WIDTH];

	//pick the goal to be the very last position in the map.
	int goal_x = LEVEL_WIDTH-2;
	int goal_y = LEVEL_HEIGHT-2;

	//buffer for the key pressed. initialized to a dummy value so compiler doesn't complain.
	char key_pressed = ' ';
	
	//for loops
	int i;

	//time for player's start and end. and name. used for best times.
	struct timeb start, end;
	char name[MAX_STR_LEN];

	//holds player's position, defaulted to 1,1.
	struct Vector player_position;
	player_position.x = 1;
	player_position.y = 1;

	//create outer level in the level 2D array.
	//generate_level(level);
	
	//display the newly created level on the screen.
	console_activate();

	initalize_maze(level);

	make_maze(level, LEVEL_WIDTH , LEVEL_HEIGHT);

	initalize_boundry(level);
	
	draw_walls(level);

	//draw the player - this is the result of calling move_player with a movement of 0,0.
	move_player(&player_position, 0, 0);

	//start the timer
	ftime(&start);

	while(key_pressed != 'q')
	{
		//waits for the user to press one key and then returns it.
		key_pressed = get_input();

		//handles player movement.
		//for each case, we check if the position the player wants to move is walkable,
		//then we move the player if it is possible.
		switch(key_pressed)
		{
			case 'w':
				if(is_walkable(level, player_position.x + 0, player_position.y - 1))
					move_player(&player_position, 0, -1);

				break;

			case 'a':
				if(is_walkable(level, player_position.x - 1, player_position.y + 0))
					move_player(&player_position, -1, 0);
				break;

			case 's':
				if(is_walkable(level, player_position.x + 0, player_position.y + 1))
					move_player(&player_position, 0, 1);
				break;

			case 'd':
				if(is_walkable(level, player_position.x + 1, player_position.y + 0))
					move_player(&player_position, 1, 0);
				break;

			default:
				//don't need to do anything.
				break;
		}

		//check if the player is at the goal and react accordingly
		if (player_position.x == goal_x && player_position.y == goal_y)
		{
			break;
		}
	}

	ftime(&end);	

	//only add high score if player didn't force quit
	if(key_pressed != 'q')
	{
		for(i = 0; i < CONSOLE_HEIGHT; i++)
			print_string(0, i, "                                                                                ");

		print_string(0, 0, "COMPLETED! Enter name (name, no spaces, then press enter.): ");

		get_string(name);

		besttimes_add(name, (end.time - start.time) +  (end.millitm - start.millitm) / 1000.0f);
	}

	console_deactivate();

	//WARNING: it seems that on linux this doesn't show the name as its entered or restore the menu correctly.       
}

//generates a new level with a goal.
void generate_level(char level[LEVEL_HEIGHT][LEVEL_WIDTH])
{
	int x, y;
	char data[LEVEL_HEIGHT][LEVEL_WIDTH] = 	 
		{{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
	    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', '#'}, 
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			level[y][x] = data[y][x];
}

void draw_walls(char level[LEVEL_HEIGHT][LEVEL_WIDTH]){

	int x;
	int y;
	level[LEVEL_HEIGHT -2][LEVEL_WIDTH - 2] = 'G';

	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			print_char(x, y, (level[y][x]));

}

//draws the level in the console.
void draw_level(char level[LEVEL_HEIGHT][LEVEL_WIDTH])
{
	int y, x;

	for (y = 0; y < LEVEL_HEIGHT; y++) 
		for (x = 0; x < LEVEL_WIDTH; x++)
			print_char(x, y, level[y][x]);
}

//returns 1 if a location is walkable and 0 otherwise. this is a c-style boolean.
int is_walkable(char level[LEVEL_HEIGHT][LEVEL_WIDTH], int x, int y)
{
	if (level[y][x] == ICON_BLANK || level[y][x] == ICON_GOAL)	
		return 1;
	else
		return 0;	
}

//moves the player on the draw by erasing and redrawing them. adjusts the player's
//position after drawing.
void move_player(struct Vector* player_position, int move_x, int move_y)
{
	print_char(player_position->x, player_position->y, ICON_BLANK);

	player_position->x += move_x;
	player_position->y += move_y;

	print_char(player_position->x, player_position->y, ICON_PLAYER);

	//hack: move cursor out of the way
	print_char(CONSOLE_WIDTH-2, CONSOLE_HEIGHT-1, ' ');
}
