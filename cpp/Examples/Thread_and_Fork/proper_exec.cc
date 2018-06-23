#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
//Notice that this forked process is unrelated to the parent, and exec does not cause the parent to close.
int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
    		// we are the child
    		execlp("/bin/ls", "ls", NULL);
	}
	else
		while(1);
	return 0;
}
