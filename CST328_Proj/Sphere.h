#include "stdafx.h"

extern GLfloat xRot;
extern GLfloat zRot;
extern GLuint _textureId1;
extern M3DVector3f pointArray;

class Sphere : public SceneObj
{
private:
	static const float radius;
	static const float slices;
	static const float stacks;
	static const M3DVector3f initialPosition;
	double x;
	double y;
	double z;
	GLUquadricObj   *q;
	double rotationZ;
	double rotationX;

public:
	
	Sphere(SceneGraph * graph);

	virtual void render();

	virtual void reset();

	virtual bool isCollision(M3DVector3f pos, M3DVector3f dir);

};
