#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define VACANT 46 //ASCII value of "."

/* Partner with Fan Yi Kung (Eva)
student number:998137573
cdf: c2kungfa 
*/

void print_array(char a[][N], int );


/* prints the elements of an array */
void print_array(char a[][N], int n){
    
	int col, row;
	for (row=0; row<n; row++){
		for (col=0; col<n; col++){
			printf("%c ", a[row][col]);
		}
		printf("\n");
	}printf("\n");
}



int main(){

	char board[N][N];  //initialize board
	int row, col;

	for (row=0; row<N; row++){
		for (col=0; col<N; col++){
			board[row][col]= '.';
		}
	}

	char current[1] = "A"; //initializing with starting value A
   
	int x, y, direction, moved, running, occupied;

	srand(time(NULL)); //need to be out of loop

	//start of the program
	x=0;
	y=0; 
	running = 1;

	board[x][y] = current[0]; //Starting board at (0,0) with value A


	/*Program will run until current is Z or until current has no more valid spots to move to*/

	while (running != 0){
		moved = 0;
		current[0] += 1;

		if (current[0] == 91){ //ASCII value of "Z"
			break;
		}

		/*occupied variable to check if valid spots is empty or not, if so, 
		will go to condition where it checks for all available spots 
		around its current position*/

		occupied=0;

		/*Loops until value has moved, unless it goes to the condition where it has no more spots to move to(END OF GAME).
		Moved is initially 0(not moved) until moved is 1(moved).
		*/

		while (moved != 1){ 
			direction = rand()%4;
			if (direction == 0 && y > 0 && y <= 9 ){ //North
				if(((board[y-1][x])-VACANT) == 0){ //VACANT spot since "." - "." = 0
					y -= 1;
					board[y][x] = current[0];
					moved = 1;
				}else{occupied = 1;}
			}else if(direction == 1 && x >= 0 && x < 9){ //East
				if(((board[y][x+1])-VACANT) == 0){
					x += 1;
					board[y][x] = current[0];
					moved = 1;
				}else{occupied =1;}
			}else if (direction == 2 && y >= 0 && y < 9){ //South
				if(((board[y+1][x])-VACANT) == 0){
					y += 1;
					board[y][x] = current[0];
					moved = 1;
				}else{occupied =1;}
			}else if(direction == 3 && x > 0 && x <= 9){ //West
				if(((board[y][x-1])-VACANT) == 0){
					x -= 1;
					board[y][x] = current[0];
					moved = 1;
				}else{occupied =1;}
			}
	
			/*if the direction it wanted to go is occupied,
			it will be forced check for all valid spots around the current position */
			if (occupied ==1){	
				for(direction=0; direction<4; direction++){ //Loop to check all 4 conditions
					if (direction == 0 && y > 0 && y <= 9){ //North
						if(((board[y-1][x])-VACANT) == 0){
							y -= 1;
							board[y][x] = current[0];
							moved = 1;
						}
					}else if(direction == 1 && x >= 0 && x < 9){ //East
						if(((board[y][x+1])-VACANT) == 0){
							x += 1;
							board[y][x] = current[0];
							moved = 1;
						}
					}else if (direction == 2 && y >= 0 && y < 9){ //South
						if(((board[y+1][x])-VACANT) == 0){
							y += 1;
							board[y][x] = current[0];
							moved = 1;
						}
					}else if(direction == 3 && x > 0 && x <= 9){ //West
						if(((board[y][x-1])-VACANT) == 0){
							x -= 1;
							board[y][x] = current[0];
							moved = 1;
						}
					}if (moved==1){ 	//For loop breaks after it finds a spot (there is a valid spot!)
						break;
					}
				}
				if(direction == 4 && moved == 0){ //Terminates the whole program after all 4 sides are occupied
					running=0;
					moved=1;
				}
			}
		}
	}
	print_array(board, N);	
	return 0;
}
