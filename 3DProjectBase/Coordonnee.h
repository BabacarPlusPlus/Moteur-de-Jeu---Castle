#pragma once
#include <time.h> 

class Coordonnee
{
	

public:

	float x;
	float z;
	Coordonnee(float,float);
	void randCoordonneeRand(int min,int max);
	void print();
	Coordonnee();
	~Coordonnee();
};

