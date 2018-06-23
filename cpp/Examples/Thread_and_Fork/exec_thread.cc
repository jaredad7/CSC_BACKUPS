#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *print_message(void*)
{
	execlp("/bin/ls", "ls", NULL);
}



int main() {

	pthread_t t1;

	pthread_create(&t1, NULL, &print_message, NULL);
  	while(1);

	return 0;
}
