#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t countm;
int count;

void *print_message(void*)
{
    cout << "Threading" << endl;

    pthread_mutex_lock(&countm);
    count++;
    cout << "count: " << count << endl;
    pthread_mutex_unlock(&countm);
}

int main() 
{
    count = 0;
    pthread_t t1;
    pthread_t t2;
    
    pthread_create(&t1, NULL, &print_message, NULL);
    pthread_create(&t2, NULL, &print_message, NULL);
        
    return 0;
}
