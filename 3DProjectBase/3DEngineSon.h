#pragma once
#include "3DEngine.h"
#include "GL/GL.h"
#include "GL/GLU.h"


class C3DEngineSon : public C3DEngine
{
	//--- Application setup/shutdown
	void Setup(HWND hWnd);
	void Shutdown(void);

	//--- Update/render
	void Update(float fDT);
	void Render(unsigned int u32Width, unsigned int u32Height);

	virtual void MouseWheel(float fIncrement);
	virtual void MouseMove(POINT Pos);
	virtual void LButtonDown(POINT Pos);
	virtual void LButtonUp(POINT Pos);
	virtual void RButtonDown(POINT Pos);
	virtual void RButtonUp(POINT Pos);
	virtual void KeyDown(int s32VirtualKey) ;

};


