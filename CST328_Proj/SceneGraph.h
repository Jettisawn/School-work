#include "stdafx.h"

#include <list>
using std::list;

extern GLfloat xRot;
extern GLfloat zRot;

class SceneGraph
{
public:

	SceneGraph()
	{
		//create maze here and add to the m_objects list
	}

	void Add( SceneObj * obj)
	{
		m_objects.push_back(obj);
	}

	bool isCollision(SceneObj * caller, M3DVector3f pos, M3DVector3f dir)
	{
		bool collision = false;
		//loop through everything except the caller
		for(list<SceneObj*>::iterator i = m_objects.begin(); i != m_objects.end() && !collision; ++i)
		{
			if(*i != caller) //ptr comparison is ok
			{
				collision = (*i)->isCollision(pos, dir);
			}
		}

		return collision;
	}

	void Render(CCamera & Camera, int iOutline)
	{
		//render global stuff here like camera, etc (also floor, since not worried about collision)

		// Clear the window with current clearing color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		
		
		glColor3f(1.0f, 1.0f, 1.0f);

		glFrontFace(GL_CCW);

		if(iOutline)
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	//	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

		glLoadIdentity();

		Camera.Render();

		//then render each sceneobj
		for(list<SceneObj*>::iterator i = m_objects.begin(); i != m_objects.end(); ++i)
		{
			glPushMatrix();
				glRotatef(xRot, 1.0f, 0.0f, 0.0f);
				glRotatef(zRot, 0.0f, 0.0f, 1.0f);
				(*i)->render();
			glPopMatrix();
		}

		//done rendering, completely
		glFlush();  
		glutSwapBuffers();
	}

	void Reset()
	{
		for(list<SceneObj*>::iterator i = m_objects.begin(); i != m_objects.end(); ++i)
		{
			(*i)->reset();
		}
	}

private:
	list<SceneObj*> m_objects;
};
