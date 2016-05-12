#include <stdio.h>
#include <string.h>

/* Partner with Fan Yi Kung (Eva)
student number:998137573
cdf: c2kungfa 
*/

int main(void){

    char input[81]; // including \0 & newline
    char output[81];
  
  
    int shift, i, numDifference,maxLetters; //value to shift, and number to iterate 
    printf("Enter message to be encrypted : \n");
    fgets(input, sizeof(input), stdin);

    printf("Enter shift amount (1-25) : \n");
    scanf("%d", &shift);
    maxLetters=26;//letters in range 0-25 inclusive because of the alphabet
    for (i=0; input[i] != 0; i++){

        if((input[i]>='a' && input[i]<='z')){ //lower case ascii range is  97-112 (a-z)
		numDifference = (input[i] - 'a'); //how much left over to shift after wrapping if it exceeds
		output[i] = (numDifference + shift) % maxLetters + 'a';


	}else if (input[i]>='A' && input[i]<='Z'){ //upper case ascii range is 65-90
		numDifference = (input[i] - 'A');
		output[i] = (numDifference + shift) % maxLetters + 'A';

	}else if(input[i] == ' '){    //spaces remain unchanged
		output[i] = input[i];

	}else {                       //if it is a symbol (not upper/lower letters), then symbol remains unchanged
		output[i] = input[i]; //everything remains the same
	}


    }

    printf("%s", output); //no need for \n for output due to the input message that includes the \n ASCII value


    return 0;
}


