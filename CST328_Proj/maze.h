#include "stdafx.h"

extern GLfloat xRot;
extern GLfloat zRot;

#define NUM_WALLS 18

class Maze : public SceneObj
{
	
private:
	typedef float	M3DVector3f[3];		// Vector of three floats (x, y, z)
	static const float yMin;
	static const float yMax;
	static M3DVector3f pointArray[NUM_WALLS][4];
	static M3DVector3f normalArray[NUM_WALLS];

public:
	Maze(SceneGraph * graph);

	virtual void render();

	virtual void reset();

	virtual bool isCollision(M3DVector3f pos, M3DVector3f dir);
};

