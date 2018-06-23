#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *print_message(void*)
{
	cout << "Threading\n";
}



int main() 
{
    pthread_t t1;

    pthread_create(&t1, NULL, &print_message, NULL);
    cout << "Hello\n";
    while(1);
}
