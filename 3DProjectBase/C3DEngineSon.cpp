#include "StdAfx.h"
#include "3DEngineSon.h"
#include "OBJLoader.h"
#include "OBJLoader.h"
#include <iostream>
#include <time.h>
#include "Coordonnee.h"
#include <vector>

using namespace std;
/*
  Marche de Jarvis

Données : Points = un ensemble ﬁni de points du plan.
Sorties : Enveloppe = la liste des sommets de l'enveloppe convexe.
1 début
2 pmin ← le sommet le plus bas
3 pcourant ← pmin
4 Insérer(pcourant,L)
5 répéter
6 Choisir p ≠ pcourant
7 Prendre psuivant le point le plus à droite de [pcourant, p)
8 pcourant ← psuivant
9 Insérer(pcourant,L)
10 jusqu’à pcourant = pmin
11 retourner L
12 ﬁn

*/

C3DEngineSon engine;
SCENE * scene;



Coordonnee plusAdroite(Coordonnee pcourant ,Coordonnee p,vector <Coordonnee> v)
{
    Coordonnee Adroite;
    float valmin=0;
    for( int i =0 ;i< v.size();i++)
    {
        float val =((p.x - pcourant.x )*(v[i].z-pcourant.z))-((p.z-pcourant.z)*(v[i].x-p.x));
        if((val < 0 )&& (val < valmin))
        {
            //donc v[I]a droite
            valmin=val;
            Adroite.x=v[i].x;
            Adroite.z=v[i].z;
        }
    }
   return Adroite;
}

vector <Coordonnee> enveloppeConvexe( vector <Coordonnee> v)
{
    //calcul d'EC
    vector <Coordonnee> ListeConvexe = vector <Coordonnee>();

    //le sommet le plus bas
    Coordonnee pmin=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i].x < pmin.x) pmin=v[i];
    }
    //le sommet courant
    Coordonnee pcourant=pmin;
    //on ajoute a la liste
    ListeConvexe.push_back(pcourant);

     int j=0;
   do{
        //choix d'un p différent de pcourant
        Coordonnee p,psuivant;
        for(int i= 0; i<v.size();i++)
        {
            if((v[i].x != pcourant.x ) && (v[i].z != pcourant.z ))
                p=v[i];
        }
        psuivant.x=(plusAdroite( pcourant ,p,v)).x;
        psuivant.z=(plusAdroite( pcourant ,p,v)).z;

        pcourant.x=psuivant.x;
        pcourant.z=psuivant.z;

        ListeConvexe.push_back(pcourant);
        cout<<" ca plante :"<<j<<endl;
        j++;

    }while(( pcourant.x != pmin.x) && (pcourant.z != pmin.z));

    return ListeConvexe;// renvoie l'EC : liste contenant les EC
}

void printListe(vector <Coordonnee> v)
{
    for(int i=0; i< v.size();i++)
    {
        v[i].print();

    }
}

void C3DEngineSon ::Setup(HWND hWnd)
{
	/*initialisation */

	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	/* creation points */
	srand (time(NULL));


    vector <Coordonnee> Liste = vector <Coordonnee>();


    for(int i=0; i< 20;i++)
    {
        Coordonnee co ;
        co.randCoordonneeRand(100);
        Liste.push_back(co);
    }

    cout<< "taille : "<<Liste.size()<<endl;
    printListe(Liste);

    vector <Coordonnee> ListeConvexe = vector <Coordonnee>();
    ListeConvexe=enveloppeConvexe( Liste);
    /*for(int i =0 ; i<Liste.size();i++ )
    {
        ListeConvexe.push_back(Liste[i]);
    }*/

     cout<< "--------------"<<endl;
     cout<< "l'enveloppe convexe"<<endl;
    printListe(ListeConvexe);
    cout<<" Taille liste convexe: "<<ListeConvexe.size()<<" "<<endl;

	//affichage

}

void C3DEngineSon ::Render(unsigned int u32Width, unsigned int u32Height)
{	

	glClearDepth(1);

	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glColor3f( 0.0, 1.0,0.0 );
	
}




void C3DEngineSon ::Shutdown(void){}


void C3DEngineSon ::Update(float fDT){}
void C3DEngineSon :: MouseWheel(float fIncrement) {}
void C3DEngineSon :: MouseMove(POINT Pos) {}
void C3DEngineSon :: LButtonDown(POINT Pos) {}
void C3DEngineSon :: LButtonUp(POINT Pos) {}
void C3DEngineSon :: RButtonDown(POINT Pos) {}
void C3DEngineSon :: RButtonUp(POINT Pos) {}
void C3DEngineSon :: KeyDown(int s32VirtualKey) {}