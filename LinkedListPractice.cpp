//  main.cpp
//  CppTesting
//
//  Created on 2/9/16.
//  Copyright (c) 2016 Jared Adamson. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    
    int i;
    
    node *next;
    
    
};

int main(int argc, const char * argv[]) {
   
    node *rootNode;
    
    node *location;
    
    rootNode = new node;
    
    rootNode -> next = 0;
    
    rootNode -> i = 15;
    
    location = rootNode;
    
    if(location != 0){
        
        while(location -> next != 0){
            
            cout << location -> i << endl;
            
            location = location -> next;
            
        }
        
        cout << location -> i << endl;
        
        location -> next = new node;
        
        location = location -> next;
        
        location -> next = 0;
        
        location -> i = 25;
        
        cout << location -> i << endl;
        
        
    }
    
    cout << "DONE" << endl;
    
    getchar();
    
    return 0;
}
