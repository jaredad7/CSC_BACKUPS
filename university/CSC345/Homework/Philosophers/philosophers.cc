/*
 *Dining Philosophers will compete for chopsticks
 *Try to avoid a deadlock situation with evens pick up right first, odds pick up left first
 *@author <Jared Dembrun>
 *@date<4.30.2014>
 */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdint.h>

#define MAX_ARRAY_SIZE 128

using namespace std;

//A philosopher with a number as his place at the table
extern "C" void * philosopher(void * data);

//A global array of dynamic size of pthread mutex objs called chopsticks
pthread_mutex_t chopsticks[MAX_ARRAY_SIZE];

//The number of philosophers is a global integer that will not be changed after program instantiation
//eats is in the same boat
int philo;
int eats;
//Counter counts down to zero to see when the philosophers are finished dining
int counter;
pthread_mutex_t countm;

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		cout << "Error, bad arguments." << endl;
		cout << "Please declare a only number of philosophers and a number of times to eat as respective program arguments." << endl;
		return 0;
	}
	else
	{
		philo = atoi(argv[1]);
		eats = atoi(argv[2]);
		counter = (philo*eats);

		if(philo > MAX_ARRAY_SIZE || eats > MAX_ARRAY_SIZE)
		{
			cout << "Error, too many philosophers or too many eating times.\nMax number: " << MAX_ARRAY_SIZE << endl;
			return 0;
		}
		if(philo <= 1)
		{
			cout << "Don't be silly, we can't have less than one philosopher, and one philosopher would only get one chopstick, with which it would be impossible for him to eat." << endl;
			return 0;
		}

		//Make an array of pthread objects to represent the philosophers, then intialize each in pthread_create
		pthread_t threads[philo];
		for(int i = 0; i < philo; i++)
			pthread_create(&threads[i],  NULL,  &philosopher,  (void*)i);
	}
	while(counter > 0);
	return 0;
}

void * philosopher(void* data)
{
	uintptr_t n = reinterpret_cast<uintptr_t>(data);

	//Get number of times to eat
	int e = eats;

	for(int i = 1; i <= eats; i++)
	{
		//if the philosopher is even-number, then he picks up first a right chopstick
		if(n%2 == 0)
		{
			//He could be at the end
			if(n >= (philo-1))
			{
				pthread_mutex_lock(&chopsticks[n]);
				pthread_mutex_lock(&chopsticks[0]);
				pthread_mutex_lock(&countm);
				cout << "Philosopher " << n << " is eating his " << i << " time" << endl;
				cout << "Philosopher " << n << " is finished eating." << endl;
				counter--;
				pthread_mutex_unlock(&chopsticks[n]);
				pthread_mutex_unlock(&chopsticks[0]);
				pthread_mutex_unlock(&countm);
			}
			else
			{
				//default behavior otherwise
				pthread_mutex_lock(&chopsticks[n]);
				pthread_mutex_lock(&chopsticks[(n+1)]);
				pthread_mutex_lock(&countm);
				cout << "Philosopher " << n << " is eating his " << i << " time" << endl;
				cout << "Philosopher " << n << " is finished eating." << endl;
				counter--;
				pthread_mutex_unlock(&chopsticks[n]);
				pthread_mutex_unlock(&chopsticks[(n+1)]);
				pthread_mutex_unlock(&countm);
			}
		}
		else
		{
			//Then he is odd, so he picks up the left one first

			//He could be at the end
			if(n >= (philo-1))
			{
				pthread_mutex_lock(&chopsticks[0]);
				pthread_mutex_lock(&chopsticks[n]);
				pthread_mutex_lock(&countm);
				cout << "Philosopher " << n << " is eating his " << i << " time" << endl;
				cout << "Philosopher " << n << " is finished eating." << endl;
				counter--;
				pthread_mutex_unlock(&chopsticks[0]);
				pthread_mutex_unlock(&chopsticks[n]);
				pthread_mutex_unlock(&countm);
			}
			else
			{
				//default behavior otherwise
				pthread_mutex_lock(&chopsticks[(n+1)]);
				pthread_mutex_lock(&chopsticks[n]);
				pthread_mutex_lock(&countm);
				cout << "Philosopher " << n << " is eating his " << i << " time" << endl;
				cout << "Philosopher " << n << " is finished eating." << endl;
				counter--;
				pthread_mutex_unlock(&chopsticks[(n+1)]);
				pthread_mutex_unlock(&chopsticks[n]);
				pthread_mutex_unlock(&countm);
			}
		}
	}
}
