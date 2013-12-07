#include "Coordonnee.h"

#include <iostream>
using namespace std;



Coordonnee::Coordonnee(float x1,float y1)
{
	x=x1;
	z=y1;	
}

void Coordonnee::randCoordonneeRand(int min,int max)
{
	srand (time(NULL));
	x = rand() % (max*100) + (min*100);	
	z = rand() % (max*100) + (min*100);
	x=x/100;
	z=z/100;
}

void Coordonnee::print()
{
	cout<<" x="<<x<<" , z ="<<z<<endl;
}

Coordonnee::Coordonnee()
{

}


Coordonnee::~Coordonnee()
{
}
