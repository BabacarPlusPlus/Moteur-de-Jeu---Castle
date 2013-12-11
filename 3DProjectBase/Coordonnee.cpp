#include "Coordonnee.h"
#include <time.h>
#include <iostream>
using namespace std;

Coordonnee::Coordonnee()
{
    x=0;
    z=0;
}

Coordonnee::Coordonnee(float x1,float y1)
{
    x=x1;
    z=y1;
}

void Coordonnee::randCoordonneeRand(int espace)
{

    int x1 = rand() % (espace*100) + (0);
    int z1 = rand() % (espace*100) + (0);

    x=((float)x1/100)-(espace/2);
    z=((float)z1/100)-(espace/2);
}

void Coordonnee::print()
{
    cout<<" x="<<x<<" , z ="<<z<<endl;
}


Coordonnee::~Coordonnee()
{
}
