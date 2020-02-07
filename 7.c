/*Program 7: Structure to keep track of words and no. of occurrences of words in a paragraph*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

struct paragraph
{
	char words[15]; 		// to store words in a paragraph
	int occ;				// no. of occurrences of that words
}p[50];						// structure to store a details of 50 words

void main()
{
	int i=0, j=0, k=0, flag =0;
	char w[15], ch = 0;		// w - words, 	ch - character
	
	strcpy(w," ");				// initialize w
	
	printf("Enter a paragraph : \n");
	
	while(ch!='\n')				// accepts paragraph until enter key is pressed
	{
		flag = 0;				// to keep track of words to be printed
		strcpy(p[j].words,"");	// initialize word in the structure
		p[j].occ = 1;			// initialize its occurrence in the structure
		ch = getchar(); 		// accept a letter
		w[i] = tolower(ch);		// convert it to lower case
		i++;					// increment the count of letter
		
		if(!(isalpha(ch)))		//check if the letter entered is special character
        {
			w[i-1] = '\0';		// if special character, removing it so that it doesn't get printed along with the word
			
			for(k=0;k<=j;k++)	// to check the no. of occurrences of a word, k - index of words in structure, j -  count of words entered
				if(strcmp(p[k].words,w) == 0)	// compares the words stored in structure with the new word entered ie., w
				{
					p[k].occ++;	// increment the no. of occurrences of a word in the structure
					flag = 1;	// increment flag to avoid duplicates in the list of words in structure
				}
				
			if(flag == 0)		// check if no duplicates
			{
					strcpy(p[j].words, w);	// add it to the list of words in the structure
					j++;					// increment the no. of words in the structure
			}	
			strcpy(w, ""); 					// initialize w to store new word
			i=0;							// initilize i to store characters of new word
		}
		
	}
	
	printf("\nWords and No. of occurence\n");
	printf("\n-----------------------------------------\n");
	for(i=0;i<j;i++)						// print words and it's occurences
		printf("%s - %d\n",p[i].words, p[i].occ);
	
	getch();
}