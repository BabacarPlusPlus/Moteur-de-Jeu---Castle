#pragma once

#include <time.h>

class Coordonnee
{


public:

    float x;
    float z;

    Coordonnee(float,float);
    void randCoordonneeRand(int espace);
    void print();
    Coordonnee();
    ~Coordonnee();
};

