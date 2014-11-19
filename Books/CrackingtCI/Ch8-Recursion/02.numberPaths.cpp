/*Imagine a robot sitting on the upper left hand corner of an NxN grid.
The robot can only move in two directions: right and down How many possible 
paths are there for the robot?
FOLLOW UP
Imagine certain squares are “off limits”, such that the robot can not step on 
them Design an algorithm to get all possible paths for the robot*/

#include <iostream>
#include <list>
using namespace std;

//Objective not clear. If it is to get on the other corner...
int numberPaths(int dimH, int dimV){
	if(dimV==0 && dimH==0){ 
		return 1;
	}
	int lR=(dimH!=0)? numberPaths(dimH-1, dimV): 0; 
	int lD=(dimV!=0)? numberPaths(dimH, dimV-1): 0;
	return( lR+ lD);
}

//follow up..

typedef struct bannedCell
{
	int h;
	int v;
} bannedCell;

list<bannedCell> bannedList;

bool banned(int dimH, int dimV){
	for (list<bannedCell>::iterator it = bannedList.begin(); it != bannedList.end(); it++){
		if(it->h==dimH && it->v==dimV)
			return true;
	}
	return false;
}

int numberPathsWithBanned(int dimH, int dimV){
	if(banned(dimH, dimV)){ 
		return 0;
	}
	if(dimV==0 && dimH==0){ 
		return 1;
	}
	int lR=(dimH!=0)? numberPaths(dimH-1, dimV): 0; 
	int lD=(dimV!=0)? numberPaths(dimH, dimV-1): 0;
	return( lR+ lD);
}
