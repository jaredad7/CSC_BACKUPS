/*******
 *
 *This C program will parse a string and then tokenize it 
 *using spaces as a delimiter.
 *
 *This program will be implemented to run in the end of 
 *quarter project 'Tech Shell', which is a custom shell
 *
 *The old parsing program I had can parse based on multiple
 *delimiters if they are specified within the code itself.
 *This one can only parse woth one delimiter, but it uses
 *a function I wrote myself.
 *
 *The old parsing program can also loop and exit when 'exit' is typed.
 *Boy, those string.h functions sure were useful!
 *
 *@author <Jared Dembrun>
 *@date <1/28/14>
 *
*******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 128

const char *ex = "exit";
void getInput();
void tokenize(char[MAX_TOKEN_SIZE]);

int main()
{
	printf("Welcome to Tech Shell!\nRight now, she doesn't do much, but she's going places!\n\n");
	getInput();
	return 0;
}

void getInput()
{
	char input[MAX_TOKEN_SIZE];
	printf("Enter a string to tokenize: ");
	scanf("%[^\n]", input);//read a char array of MAX_TOKEN_SIZE from stdin
	tokenize(input);
	printf("\n");
}

void tokenize(char input[MAX_TOKEN_SIZE])
{
	char *p_str;
	p_str = input;
	int i = 1;

	printf("Token %d: ", i);
	while((*p_str) != '\0')
	{
		if((*p_str) != ' ')
		{
			printf("%c", *p_str);
			*p_str = NULL;
		}
		else
		{
			i++;
			printf("\nToken %d: ", i);
		}
		p_str++;
	}

}
