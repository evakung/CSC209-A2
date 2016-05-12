#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 256


/* Partner with Fan Yi Kung (Eva)
student number:998137573
cdf: c2kungfa 
*/

int check(char first[], char second[], int length);


/*
check returns either 0 (false) or 1(true) to verify the two temporary arrays if 
they have the same values for each letter. 

strings that only consist of space or symbols are NOT anagrams. Must have letters from the alphabet
to be considered as an anagram

*/

int check(char first[], char second[], int length){
    int i;
    int check = 0;

    for (i=0; i<26; i++){
	if(first[i] == second[i]){  //checking same amount in specific char of alphabet
	    check += first[i];
	}
	if (i == 25 && check == (length - 1)){  //minus 1 because of the \0 value from the char array
	    return 1;				//condition for last letter to verify if True or false
	}
    }
    return 0;
}


int main(void){

    char first[MAXLENGTH];
    char second[MAXLENGTH]; //INPUT char arrays

    char firstArray[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //For temp array to verify specific letters
    char secondArray[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int i, checkwords;

    printf("Enter first word: ");
    fgets(first, sizeof(first), stdin);
    printf("Enter second word: ");
    fgets(second, sizeof(second), stdin);

    //The input must all be the same length, otherwise they are not anagram since space is taken in as a symbol

    if (strlen(first) != strlen(second)){
	printf("The word are not anagrams\n");
    }else{
	int symbol1 = 0;
	int symbol2 = 0;
	int length;

	for (i=0; i<strlen(first); i++){ //Would use function but we have not learnt pointers yet
	    first[i]=tolower(first[i]);  //Since they are both the same length, no need for extra loop
	    second[i]=tolower(second[i]);

	    if(first[i] > 96 && first[i] < 123){ //a-z values
		firstArray[first[i]-97] += 1;	//Adding into firstArray for corresponding value ie. a will go to index 0 of the temp array 
	    }else{
		symbol1 += 1;
	    }
	    if(second[i] > 96 && second[i] < 123){
		secondArray[second[i]-97] += 1;
	    }else{
		symbol2 += 1;
	    }
	}
	if (symbol1 != symbol2){
	    printf("The words are not anagrams \n");
	}else{
	    length = strlen(first) - (symbol1 - 1); //symbol includes ASCII 10 (newline), hence -1
	    checkwords = check(firstArray, secondArray, length);
		if (checkwords == 0 || symbol1 == strlen(first) || symbol2 == strlen(second)){ //Checking for just symbols or empty string
		    printf("The words are not anagrams \n");
		}else{
		    printf("The words are anagrams \n");
		}
	}
    }
    return 0;
}
