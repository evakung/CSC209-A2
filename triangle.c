#include <stdio.h>
#include <string.h>
#include <math.h>

/* Partner with Fan Yi Kung (Eva)
student number:998137573
cdf: c2kungfa 
*/

int main(void){
    int input, lastRow;

    printf("Enter the number of rows in the triangle:");
    scanf("%d", &input);

    lastRow = 2*input - 1;

    int row, i, first, second;

    for (row = 1; row <= input; row ++){  //loop for the triangle itself

        first = ((lastRow/2)-(row-1)); //should be ceil(lastRow/2) but the math.h did not compile on cdf
        second = ((lastRow/2)+(row-1));

        for (i = 1; i <= lastRow; i ++){ //loop for row and stars
            if(row==1 && i-1 == first){  //for first row
                printf("*");
            }
            else if (row == input){ //last row
                printf("*");
            }else{		//conditions for 2 *'s in row
                if (i-1 == first){
                    printf("*");
                }else if (i-1 == second){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
