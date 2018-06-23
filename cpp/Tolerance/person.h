/*****************************
 *
 *A person is either tolerant or intolerant,
 *either believes or does not believe one certain thing,
 *and has a certain level of influence.
 *
 *@author<Jared Dembrun>
 *@date<12/23/13>
*****************************/

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

//Violence is the threshold which must be exceeded for someone to kill another person
//The influence of tolerant people lowers the number which is calculated and compared to violence
//This influence is only effective if a tolerant person's beliefs align with the intolerant person's
//The influence of intolerant people raises the number which is calculated and compared to violence.
//All people who are adjacent to an intolerant person and do not share his beliefs are killed if violence is exceeded for that person.
//Adjacency is defined as touching diagonally or cardinally.
#define VIOLENCE 150
#define MAX_INF 50

class Person
{
private:
	bool tolerant;//whether or the person is tolerant of others' beliefs
	bool belief;
	bool alive;//whether or not the person is alive; a dead person has no effect on violence
	int influence;//how influencial a person is on a scale of 1-MAX_INF
public:
	Person(bool t, bool b, int i)//constructor for person t=tolerant, b=belief, i=influence
	{
		tolerant = t;
		belief = b;
		influence = i;
		alive = true;
	}
	bool getTol()//returns whether the person is tolerant
	{
		return tolerant;
	}
	bool getBelief()//returns whether or not the person believes
	{
		return belief;
	}
	bool getAlive()//returns whether or not the person is alive
	{
		return alive;
	}
	bool doesKill(int violence)//returns whether or not the person will kill this round
	{
		if(!tolerant)
			return (violence > VIOLENCE);
		return false;
	}
	void kill()//kills the person
	{
		alive = false;
	}
	int getInf()//return the magnitude of a person's influence
	{
		return influence;
	}
};

#endif
