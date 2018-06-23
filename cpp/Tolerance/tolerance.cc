/*******
 *
 *This is the tolerance program.
 *Using a person object, the tolerance program will
 *run a simulation of people who would or would not 
 *tolerate people with opposing beliefs. These people
 *will exist on a (WIDTH-2)x(HEIGHT-2) (defined below) square 
 *and interact via their influence, beliefs, and tolerance 
 *levels.
 *
 *A non-tolerant person will influence the violence
 *of those who share his beliefs positively if they are
 *non-tolerant. A tolerant person will influence
 *the violence of those who share his beliefs negatively.
 *If violence is exceeded for a non-tolerant person, then
 *all of the people who do not share his belief adjacent
 *to him will be killed.
 *
 *Each turn, the game is updated, and a statistical
 *analysis is printed out, containing the number of
 *tolerants and intolerants, as well the percentage of 
 *tolerants who believe true and the percentage of 
 *non-tolerants who believe true.
 *People may also repopulate if they are adjacent to
 *a person with the same belief. Children spawn
 *only if there is enough room and they must spawn
 *adjacent to one of their parents.
 *
 *@author<Jared Dembrun>
 *@date<2/4/14>
********/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "person.h"

using namespace std;

#define WIDTH 102//People exist on 1 through WIDTH-1, creating a buffer of NULL spaces
#define HEIGHT 102//Same as WIDTH, but vertically
#define PROB_ON_CREATE 2//Probability of person spawning on creation is 1/PROB
#define PROB_REPOP 5//Probability of person spawing in repopulate is 1/PROB
#define PROB_TOL 10//Probability of a person being born tolerant is 1/PROB
#define PROB_TRU 10//Probabilitty of a person who believes true is 1/PROB

void populate(Person* (world)[WIDTH][HEIGHT]);
void update(Person* (world)[WIDTH][HEIGHT], int loop);
	void killall(Person* (world)[WIDTH][HEIGHT]);//kills those who need to die (wow, harsh!)
	void cleanup(Person* (world)[WIDTH][HEIGHT]);//remove dead people from the world
	void repopulate(Person* (world)[WIDTH][HEIGHT]);//New people are born everyday, after all
	void printout(Person* (world)[WIDTH][HEIGHT], int loop);

int main()
{
	srand(time(0));//seed the random number generator
	Person *world[WIDTH][HEIGHT];//create the world

	for(int col = 0; col < WIDTH; col++)
		for(int row = 0; row < HEIGHT; row++)
			world[col][row] = NULL;//empty bad adresses contained in memory

	populate(world);//populate the world
	
	//determine how long to run the world, input -1 for theoretically infinity
	int times = 0;
	cout << "Please specify a number of turns: ";
	cin >> times;
	cout << endl << endl;
	int i = 0;

	//observe what happens in the world
	while(i != times)
	{
		i++;
		update(world, i);
	}

	cout << "Game complete!!!" << endl;
	return 0;	
}

//
void populate(Person* (world)[WIDTH][HEIGHT])
{
	cout << "populating" << endl;
	for(int col = 1; col < (WIDTH-1); col++)
		for(int row = 1; row < (HEIGHT-1); row++)
		{
			if((rand()%PROB_ON_CREATE == 0))
			{
				world[col][row] = new Person((rand()%PROB_TOL == 0), (rand()%PROB_TRU == 0), ((rand()%MAX_INF)+1)); 
			}
			else
				world[col][row] = NULL;
		}
}

//A driver for the things which change the world
void update(Person* (world)[WIDTH][HEIGHT], int loop)
{
	killall(world);
	printout(world, loop);
	cleanup(world);
	repopulate(world);
}

//caluculates a person's violence and then decides whether or not to kill the adjacent people
//as the longest and most complex function, most errors are likely to occur here
void killall(Person* (world)[WIDTH][HEIGHT])
{
	for(int col = 1; col < (WIDTH-1); col++)
		for(int row = 1; row < (HEIGHT-1); row++)
		{
			int v = 0;//initial violence value
			//top left person
			if(world[(col-1)][(row-1)] != NULL && world[col][row] != NULL)
			{
				if((world[(col-1)][(row-1)]->getBelief() == world[col][row]->getBelief()) && (world[(col-1)][(row-1)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col-1)][(row-1)]->getInf();
				else if((!(world[(col-1)][(row-1)]->getTol())) || (world[(col-1)][(row-1)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col-1)][(row-1)]->getInf();
			}
			//top person
			if(world[(col)][(row-1)] != NULL && world[col][row] != NULL)
			{
				if((world[(col)][(row-1)]->getBelief() == world[col][row]->getBelief()) && (world[(col)][(row-1)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col)][(row-1)]->getInf();
				else if((!(world[(col)][(row-1)]->getTol())) || (world[(col)][(row-1)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col)][(row-1)]->getInf();
			}
			//top right person
			if(world[(col+1)][(row-1)] != NULL && world[col][row] != NULL)
			{
				if((world[(col+1)][(row-1)]->getBelief() == world[col][row]->getBelief()) && (world[(col+1)][(row-1)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col+1)][(row-1)]->getInf();
				else if((!(world[(col+1)][(row-1)]->getTol())) || (world[(col+1)][(row-1)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col+1)][(row-1)]->getInf();
			}
			//left person
			if(world[(col-1)][(row)] != NULL && world[col][row] != NULL)
			{
				if((world[(col-1)][(row)]->getBelief() == world[col][row]->getBelief()) && (world[(col-1)][(row)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col-1)][(row)]->getInf();
				else if((!(world[(col-1)][(row)]->getTol())) || (world[(col-1)][(row)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col-1)][(row)]->getInf();
			}
			//right person
			if(world[(col+1)][(row)] != NULL && world[col][row] != NULL)
			{
				if((world[(col+1)][(row)]->getBelief() == world[col][row]->getBelief()) && (world[(col+1)][(row)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col+1)][(row)]->getInf();
				else if((!(world[(col+1)][(row)]->getTol())) || (world[(col+1)][(row)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col+1)][(row)]->getInf();
			}
			//bottom left person
			if(world[(col-1)][(row+1)] != NULL && world[col][row] != NULL)
			{
				if((world[(col-1)][(row+1)]->getBelief() == world[col][row]->getBelief()) && (world[(col-1)][(row+1)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col-1)][(row+1)]->getInf();
				else if((!(world[(col-1)][(row+1)]->getTol())) || (world[(col-1)][(row+1)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col-1)][(row+1)]->getInf();
			}
			//bottom person
			if(world[(col)][(row+1)] != NULL && world[col][row] != NULL)
			{
				if((world[(col)][(row+1)]->getBelief() == world[col][row]->getBelief()) && (world[(col)][(row+1)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col)][(row+1)]->getInf();
				else if((!(world[(col)][(row+1)]->getTol())) || (world[(col)][(row+1)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col)][(row+1)]->getInf();
			}
			//bottom right person
			if(world[(col+1)][(row+1)] != NULL && world[col][row] != NULL)
			{
				if((world[(col+1)][(row+1)]->getBelief() == world[col][row]->getBelief()) && (world[(col+1)][(row+1)]->getTol()))//if this person shares belief and is tolerant
					v -= world[(col+1)][(row+1)]->getInf();
				else if((!(world[(col+1)][(row+1)]->getTol())) || (world[(col+1)][(row+1)]->getBelief() != world[col][row]->getBelief()))//else, if this person is intolerant or against the current person
					v += world[(col+1)][(row+1)]->getInf();
			}

			//kill if necessary
			if(world[col][row] != NULL && world[col][row]->doesKill(v))//if the person is intolerant and violence is high enough
			{
				//top left person
				if((world[(col-1)][(row-1)] != NULL) && world[col][row]->getBelief() != world[(col-1)][(row-1)]->getBelief())
					world[(col-1)][(row-1)]->kill();
				//top
				if((world[(col)][(row-1)] != NULL) && world[col][row]->getBelief() != world[(col)][(row-1)]->getBelief())
					world[(col)][(row-1)]->kill();

				//top right
				if((world[(col+1)][(row-1)] != NULL) && world[col][row]->getBelief() != world[(col+1)][(row-1)]->getBelief())
					world[(col+1)][(row-1)]->kill();

				//left
				if((world[(col-1)][(row)] != NULL) && world[col][row]->getBelief() != world[(col-1)][(row)]->getBelief())
					world[(col-1)][(row)]->kill();

				//right
				if((world[(col+1)][(row)] != NULL) && world[col][row]->getBelief() != world[(col+1)][(row)]->getBelief())
					world[(col+1)][(row)]->kill();

				//bottom left
				if((world[(col-1)][(row+1)] != NULL) && world[col][row]->getBelief() != world[(col-1)][(row+1)]->getBelief())
					world[(col-1)][(row+1)]->kill();

				//bottom
				if((world[(col)][(row+1)] != NULL) && world[col][row]->getBelief() != world[(col)][(row+1)]->getBelief())
					world[(col)][(row+1)]->kill();

				//bottom right
				if((world[(col+1)][(row+1)] != NULL) && world[col][row]->getBelief() != world[(col+1)][(row+1)]->getBelief())
					world[(col+1)][(row+1)]->kill();
			}
		}
}

//For all pointers to people, if person is dead, delete the person
void cleanup(Person* (world)[WIDTH][HEIGHT])
{
	for(int col = 1; col < WIDTH; col++)
		for(int row = 1; row < HEIGHT; row++)
			if(world[col][row] != NULL)
				if(!(world[col][row]->getAlive()))
				{
					delete world[col][row];
					world[col][row] = NULL;
				}
}

void repopulate(Person* (world)[WIDTH][HEIGHT])
{
	for(int col = 1; col < (WIDTH-1); col++)
		for(int row = 1; row < (HEIGHT-1); row++)
		{
			if((rand()%PROB_REPOP) == 0 && world[col][row] == NULL)//use PROB here to get the reverse of population probability
			{
				world[col][row] = new Person((rand()%PROB_TOL == 0), (rand()%PROB_TRU == 0), ((rand()%MAX_INF)+1)); 
			}
		}
}
void printout(Person* (world)[WIDTH][HEIGHT], int loop)
{
	int believe_true = 0;
	int believe_false = 0;
	int tolerant = 0;
	int intolerant = 0;
	int killed = 0;
	int total = 0;

	for(int col = 1; col < (WIDTH-1); col++)
		for(int row = 1; row < (HEIGHT-1); row++)
		{
			if(world[col][row] != NULL)
			{
				if(world[col][row]->getBelief())
					believe_true++;
				else
					believe_false++;
			
				if(world[col][row]->getTol())
					tolerant++;
				else
					intolerant++;

				if(world[col][row]->getAlive())
					total++;
				else
					killed++;
			}
		}

	cout << "On loop " << loop << ":" << endl;
	cout << "Number of people who believed true: " << believe_true << endl;
	cout << "Number of people who believed false: " << believe_false << endl;
	cout << "NUmber of tolerant people: " << tolerant << endl;
	cout << "Nuber of intolerant people: " << intolerant << endl;
	cout << "Number of people killed this turn: " << killed << endl;
	cout << "Total number of people living in the world: " << total << endl << endl;
	cout << "***************************************************************" << endl << endl;
}
