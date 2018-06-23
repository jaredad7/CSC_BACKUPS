/*******
 *
 *This is the Tech shell
 *
 *This shell has the commands cd, pwd, and exit built in. It handles
 *other commands and redirection via system calls.
 *
 *@author <Jared Dembrun>
 *@date <1/28/14>
 *
*******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_TOKEN_SIZE 64
#define DIRSIZE 1024
#define MAX_ARGS 5

const char *ex = "exit";
const char *curdir = "cd";
const char *pids = "pwd";
const char red1 = '<';
const char red2 = '>';
void getInput();
void tokenize(char[MAX_TOKEN_SIZE]);
void go(char[MAX_TOKEN_SIZE]);
int redirect_handler(char *str);


int main()
{
	printf("Welcome to Tech Shell, the greatest shell at Tech!\n\n");
	getInput();
	return 0;
}

void getInput()
{
	while(1)
	{
		char input[MAX_TOKEN_SIZE];
		char cwdir[DIRSIZE];

		if(getcwd(cwdir, sizeof(cwdir)) != NULL)
			printf("%s & ", cwdir);
		else
		{
			perror("line: ");
			exit(1);
		}

		fgets(input, MAX_TOKEN_SIZE, stdin);//read a char array of MAX_TOKEN_SIZE from stdin
		char *str = input;
		if(redirect_handler(str) != 0)//if it is not redirected, do the normal routines
			tokenize(input);
	}
}

void tokenize(char input[MAX_TOKEN_SIZE])
{
	char *str = strtok(input, " ");
	while(str) 
	{
		if(str[0] == ex[0] && str[1] == ex[1] && str[2] == ex[2] && str[3] == ex[3])
		{
			exit(0);
		}
		else if(str[0] == curdir[0] && str[1] == curdir[1])
		{
			char *dir = strtok(NULL, "\n");
			if(dir == NULL)
				chdir("/home");
			else if(chdir(dir) != 0)
				perror("cd: ");
		}
		else if(str[0] == pids[0] && str[1] == pids[1] && str[2] == pids[2])
		{
			char pwdir[DIRSIZE];

		if(getcwd(pwdir, sizeof(pwdir)) != NULL)
			printf("%s\n", pwdir);
		else
		{
			perror("pwd: ");
			exit(1);
		}
		}
		else//The command is not built-in
			go(str);//this is a function in another file to handle commands which are not built-in
    		str = strtok(NULL, " ");
	}
}

void go(char *str)
{
	char *argv[MAX_ARGS];
	int i = 0;
	argv[0] = str;
	while(str && i < MAX_ARGS)
	{
		i++;
		str = strtok(NULL, " ");
		argv[i] = str;
	}
	argv[(i-1)] = strtok(argv[(i-1)], "\n");

	pid_t pid = fork();
	if (pid < 0)
	{
    		printf("\nfatal error, failed to fork\n");
		exit(0);
	} 
	else if (pid > 0)
	{
    		int status;
    		waitpid(pid, &status, 0);
	}
	else 
	{
    		// we are the child
    		execvp(argv[0], argv);
    		_exit(EXIT_FAILURE);
	}	
}

int redirect_handler(char *str)
{
	int i;
	for(i=0; i < sizeof(str); i++)
		if(str[i] == red1 || str[i] == red2)
		{
			system(str);
			return 0;
		}
	return -1;

}
