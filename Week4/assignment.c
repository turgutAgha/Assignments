#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);
   
    return 0;
}


int solveMaze(char **maze, const int HT, const int WD, int y, int x){
    
    // solve recursively
    // however you might want to mark wrong paths with some other character
    // your functions should be able to solve other such mazes
    // pay attention to the bounds of the arrays
    // make sure you don't enter an infinite recursion
    if(x < 0 || y < 0 || x >= HT || y >= WD)
        return 0;
    if(maze[x][y] == '#' || maze[x][y] == '.')
        return 0;
    if(maze[x][y] == '*')
        return 1;

    maze[x][y] = '.';
    if(solveMaze(maze, HT, WD, y, x+1))
        return 1;
    if(solveMaze(maze, HT, WD, y, x-1))
        return 1;
    if(solveMaze(maze, HT, WD, y+1, x))
        return 1;
    if(solveMaze(maze, HT, WD, y-1, x))
        return 1;
        
    maze[x][y] = ' ';
    return 0;
}


void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
        for(int j=0; j<WD-1; j++)
	        printf("%c",maze[i][j]);
        printf("%c\n",maze[i][WD-1]);
    }
}
