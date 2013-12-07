#include "StdAfx.h"
#include "3DEngineSon.h"
#include "OBJLoader.h"
#include "OBJLoader.h"
#include "Coordonnee.h"
#include <vector>
using namespace std;

C3DEngineSon engine;
SCENE * scene;

const int nb_points=10854
vector <Coordonnee> Liste = vector <Coordonnee>();

vector <Coordonnee> enveloppeConvexe( vector <Coordonnee> v)
{
	//calcul d'EC

	return v;// renvoie l'EC : liste contenant les EC
}

void addTextures(){}

void dispay_castle ()
{	/* creer lescontours */ 


}

void C3DEngineSon ::Setup(HWND hWnd)
{
	/*initialisation */

	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	/* creation points */
	for(int i=0; i< nb_points;i++)
	{
		Coordonnee c;
		c.randCoordonneeRand(-50,50);
		Liste.push_back(c);
		srand (time(NULL));
	}	

	// calcul de l'Ec
	vector <Coordonnee> Ec= vector <Coordonnee>();
	Ec=enveloppeConvexe( Liste);

	//affichage

}

void C3DEngineSon ::Render(unsigned int u32Width, unsigned int u32Height)
{	
	for(int i=0;i<Liste.size();i++)
	{
		Liste[i].print();
	}

	

	glClearDepth(1);

	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glColor3f( 0.0, 1.0,0.0 );
	glBegin(GL_QUADS);
		glVertex3f(-10.0,0,-10.0);
		glVertex3f(10.0,0,-10.0);
		glVertex3f(10.0,0,10.0);
		glVertex3f(-10.0,0,10.0);
	glEnd();
}




void C3DEngineSon ::Shutdown(void){}


void C3DEngineSon ::Update(float fDT)
{

}


void C3DEngineSon :: MouseWheel(float fIncrement) {

}
void C3DEngineSon :: MouseMove(POINT Pos) {}
void C3DEngineSon :: LButtonDown(POINT Pos) {}
void C3DEngineSon :: LButtonUp(POINT Pos) {}
void C3DEngineSon :: RButtonDown(POINT Pos) {}
void C3DEngineSon :: RButtonUp(POINT Pos) {}
void C3DEngineSon :: KeyDown(int s32VirtualKey) {}