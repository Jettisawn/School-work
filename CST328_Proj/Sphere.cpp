#include "stdafx.h"

const float Sphere::radius = 1.0f;
const float Sphere::slices = 10.0f;
const float Sphere::stacks = 10.0f;
const M3DVector3f Sphere::initialPosition = { -20, 1, -25 };

Sphere::Sphere(SceneGraph * graph): SceneObj(graph), x(initialPosition[0]), y(initialPosition[1]), z(initialPosition[2]),
	rotationZ(0), rotationX(0)
{
	q = gluNewQuadric();                            // Create A New Quadratic
	gluQuadricNormals(q, GL_SMOOTH);                    // Generate Smooth Normals For The Quad
	gluQuadricTexture(q, GL_TRUE);                      // Enable Texture Coords For The Quad
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);            // Set Up Sphere Mapping
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);            // Set Up Sphere Mapping
}

void Sphere::reset()
{
	//go to initial position
	x = initialPosition[0];
	y = initialPosition[1];
	z = initialPosition[2];
	rotationZ = rotationX = 0;
}

void Sphere::render()
{
	M3DVector3f pos = { x, y, z };
	double angleZ = -zRot * M_PI / 180;//negative since life and math work differently >.<
	double angleX = -xRot * M_PI / 180;
	double speedX = 0.005 * (1 + xRot);
	if(speedX == 0)
	{
		if(xRot > 0)
		{
			speedX = 0.0025;
		}
		else
		{
			speedX = -0.0025;
		}
	}
	double speedZ = 0.005 * (1 + zRot);
	if(speedZ == 0)
	{
		if(zRot > 0)
		{
			speedZ = 0.0025;
		}
		else
		{
			speedZ = -0.0025;
		}
	}
	double x0 = 0;
	double z0 = 0;
	bool collisionX = false;
	bool collisionZ = false;

	if(angleZ != 0)
	{
		double oldX = x;
		//translation
		x0 = cos(angleZ) * abs(speedZ);
		x += (angleZ > 0) ? x0 : -x0; //flip sign since cosine is positive for us

		//rotation (spinning)
		rotationZ += speedZ*50;
		if(abs(rotationZ) >= 360)
		{
			rotationZ = 0;
		}

		M3DVector3f dir = {x - oldX, 0, 0 };
		//check collision in x direction
		if(dir[0] < 0)
		{
			pos[0] -= radius;
		}
		else
		{
			pos[0] += radius;
		}
		collisionX = m_graph->isCollision(this, pos, dir);
		if(collisionX)
		{
			//revert
			x = oldX;
		}
	}
	if(angleX != 0)
	{
		double oldZ = z;

		//translation
		z0 = cos(angleX) * abs(speedX);
		z += (angleX > 0) ? -z0 : z0;
		
		//rotation (spinning)
		rotationX += speedX *50; 
		if(abs(rotationX) >= 360)
		{
			rotationX = 0;
		}

		M3DVector3f dir = {0, 0, z - oldZ };

		if(dir[2] < 0)
		{
			pos[2] -= radius;
		}
		else
		{
			pos[2] += radius;
		}
		//check collision in z direction
		collisionZ = m_graph->isCollision(this, pos, dir);
		if(collisionZ)
		{
			//revert
			z = oldZ;
		}
	}

	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		//glEnable(GL_BLEND);							  // Enable Blending
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE);              // Set Blending Mode To Mix Based On SRC Alpha
		//glEnable(GL_TEXTURE_GEN_S);                     // Enable Sphere Mapping
		//glEnable(GL_TEXTURE_GEN_T);
		glTranslatef(x, y ,z);
		if(!collisionZ)
		{
			glRotatef(rotationX, 1.0, 0.0, 0.0);
		}
		if(!collisionX)
		{
			glRotatef(rotationZ, 0.0f, 0.0f, 1.0f);
		}
		
		glBindTexture(GL_TEXTURE_2D, _textureId1);
		//glutSolidSphere(radius, slices, stacks);
		gluSphere(q, radius, slices, stacks);
		
	glPopMatrix();
	
}

bool Sphere::isCollision(M3DVector3f pos, M3DVector3f dir)
{
	//dont need to implement this yet, nothing is colliding with sphere

	return false;
}
