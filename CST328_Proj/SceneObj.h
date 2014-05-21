#include "stdafx.h"

class SceneGraph;

class SceneObj
{
protected:
	SceneGraph * m_graph;

public:
	SceneObj(SceneGraph * graph) : m_graph(graph)
	{}

	virtual void render() = 0;
	virtual void reset() = 0;

	virtual bool isCollision(M3DVector3f pos, M3DVector3f dir) = 0;
	//{

	//	return true; // return true if collison, false if no
	//}

};
