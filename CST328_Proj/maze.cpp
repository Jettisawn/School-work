#include "stdafx.h"

const float Maze::yMin = 0.0f;
const float Maze::yMax = 5.0f;

// NOTE: vertical walls, still bottom left point first, then CCW looking at it from the right side (positive X)

M3DVector3f Maze::pointArray[NUM_WALLS][4] = {
									 {{-25.0f, yMin,   -30.0f}, /* wall 1 */
								     { 25.0f, yMin,   -30.0f},
								     { 25.0f,  yMax,   -30.0f},
								     {-25.0f,  yMax,   -30.0f}},
									{{-25.0f, yMin,  15.0},    /* wall 2 */
									 { 25.0f, yMin,   15.0},
									 { 25.0f,  yMax,   15.0},
									 {-25.0f,  yMax,  15.0}},
									{{ 25.0f, yMin, 15.0f},    /* wall 3 */
									 { 25.0f, yMin,  -30.0f},
									 { 25.0f,  yMax,  -30.0f},
									 { 25.0f,  yMax, 15.0f}},
									{{ -25.0f, yMin, 15.0f},    /* wall 4  */
									 { -25.0f, yMin, -30.0f},
									 { -25.0f,  yMax, -30.0f},
									 { -25.0f, yMax, 15.0f}},
									 {{ -25.0f, yMin, 15.0f}, /* wall 5 floor */
									 {  25.0f, yMin, 15.0f},
									 {  25.0f, yMin, -30.0f},
									 {-25.0f, yMin, -30.0f}}, 
									 {{-25.0f, yMin,   -15.0f}, /* wall 6 */ // Interior walls
								     { 20.0f, yMin,   -15},
								     { 20.0f,  yMax,   -15.0f},
								     {-25.0f,  yMax,   -15.0f}},
									 {{-15.0f, yMin,   -20.0f}, /* wall 7 */ // Interior walls
								     {-15.0f, yMin,   -30.0f},
								     { -15.0f,  yMax,   -30.0f},
								     {-15.0f,  yMax,   -20.0f}},
									 {{-25.0f, yMin, 5.0f}, /* wall 8 */ // Interior walls
									 {20, yMin, 5.0f},
									 {20, yMax, 5.0f},
									 {-25, yMax, 5.0f}},
									  {{-10.0f, yMin,   -15.0f}, /* wall 9 */ // Interior walls
								     {-10.0f, yMin,   -20.0f},
								     { -10.0f,  yMax,   -20.0f},
								     {-10.0f,  yMax,   -15.0f}},
									 {{-5.0f, yMin,   -20.0f}, /* wall 10 */ // Interior walls
								     {15.0f, yMin,     -20.0f},
								     { 15.0f,  yMax,   -20.0f},
								     {-5.0f,  yMax,   -20.0f}},
									 {{15.0f, yMin,   -20.0f}, /* wall 11 */ // Interior walls
								     {15.0f, yMin,     -30.0f},
								     { 15.0f,  yMax,   -30.0f},
								     { 15.0f,  yMax,   -20.0f}},
									 {{-10.0f, yMin,   0.0f}, /* wall 12 */ // Interior walls
								     { -10.0f, yMin,     -10.0f},
								     { -10.0f,  yMax,   -10.0f},
								     { -10.0f,  yMax,   0.0f}},
									 {{-15.0f, yMin,   -5.0f}, /* wall 13 */ // Interior walls
								     { -5.0f, yMin,     -5.0f},
								     { -5.0f,  yMax,   -5.0f},
								     { -15.0f,  yMax,   -5.0f}},
									 {{ 10.0f, yMin,   0.0f}, /* wall 14 */ // Interior walls
								     {  10.0f, yMin,     -15.0f},
								     {  10.0f,  yMax,   -15.0f},
								     {  10.0f,  yMax,   0.0f}},
									 {{ 0.0f, yMin,   -5.0f}, /* wall 15 */ // Interior walls
								     { 15.0f, yMin,     -5.0f},
								     { 15.0f,  yMax,   -5.0f},
								     { 0.0f,  yMax,   -5.0f}},
									 {{ 20.0f, yMin,   10.0f}, /* wall 16 */ // Interior walls
								     { 20.0f, yMin,     -5.0f},
								     { 20.0f,  yMax,   -5.0f},
								     { 20.0f,  yMax,   10.0f}},
									 {{ 5.0f, yMin,   15.0f}, /* wall 17 */ // Boss wall
								     { 5.0f, yMin,     10.0f},
								     { 5.0f,  yMax,    10.0f},
								     { 5.0f,  yMax,   15.0f}},
									 {{ -10.0f, yMin,   15.0f}, /* wall 18 */ // Boss wall
								     { -10.0f, yMin,     5.0f},
								     { -10.0f,  yMax,    5.0f},
								     { -10.0f,  yMax,   15.0f}},

								};

M3DVector3f Maze::normalArray[NUM_WALLS] = {
	{0, 0, 1},
	{0, 0, -1},
	{1, 0, 0},
	{-1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{0, 0, 1}
};

Maze::Maze(SceneGraph * graph) : SceneObj(graph)
{

}

void Maze::reset()
{

}

void Maze::render()
{
	//draw the walls
	glEnable(GL_TEXTURE_2D);

	for (int i = 0; i < NUM_WALLS; i++)
	{
		glColor3f(0.5f, 0.5f, 0.5f);
			
		if( i == 4)
		glColor3f(0.0f,1.0f,0.0f);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glBegin(GL_QUADS);

		glNormal3f(normalArray[i][0], normalArray[i][1], normalArray[i][2]);
		for (int j = 0; j < 4; j++)
		{
			glVertex3f(pointArray[i][j][0],
					    pointArray[i][j][1],
					    pointArray[i][j][2]);
		}
		glEnd();
	}
}

bool Maze::isCollision(M3DVector3f pos, M3DVector3f dir)
{
	bool collision = false;
	SF3dVector curPoints[4]; //this is the wall
	SF3dVector Position = {pos[0], pos[1], pos[2] };
	SF3dVector Destination = {pos[0], pos[1], pos[2] };
	SF3dVector Direction = {dir[0], dir[1], dir[2] };
	AddF3dVectorToVector(&Destination, &Direction);

	for(int i = 0; i < NUM_WALLS && !collision ; i++)
	{
		for(int j = 0; j < 4 && !collision  ; j++ )
		{
			curPoints[j] = F3dVector(pointArray[i][j][0], pointArray[i][j][1], pointArray[i][j][2]);
		}

		//check forward direction
		if( Position.x    > curPoints[0].x && Position.x < curPoints[1].x
			&& Position.x < curPoints[2].x && Position.x > curPoints[3].x
			&& Position.z > curPoints[0].z && Position.z > curPoints[1].z
			&& Position.z > curPoints[2].z && Position.z > curPoints[3].z
			&& 
			Destination.x    > curPoints[0].x && Destination.x < curPoints[1].x
			&& Destination.x < curPoints[2].x && Destination.x > curPoints[3].x
			&& Destination.z < curPoints[0].z && Destination.z < curPoints[1].z
			&& Destination.z < curPoints[2].z && Destination.z < curPoints[3].z
			)
		{	
			collision = true;
		}
		//check back direction
		else if(Position.x    > curPoints[0].x && Position.x < curPoints[1].x
			&& Position.x < curPoints[2].x && Position.x > curPoints[3].x
			&& Position.z < curPoints[0].z && Position.z < curPoints[1].z
			&& Position.z < curPoints[2].z && Position.z < curPoints[3].z
			&& 
			Destination.x    > curPoints[0].x && Destination.x < curPoints[1].x
			&& Destination.x < curPoints[2].x && Destination.x > curPoints[3].x
			&& Destination.z > curPoints[0].z && Destination.z > curPoints[1].z
			&& Destination.z > curPoints[2].z && Destination.z > curPoints[3].z)
		{
			collision = true;
		}
		//check left direction
		else if(Position.x    >= curPoints[0].x && Position.x >= curPoints[1].x
			&& Position.x >= curPoints[2].x && Position.x >= curPoints[3].x
			&& Position.z <= curPoints[0].z && Position.z >= curPoints[1].z
			&& Position.z >= curPoints[2].z && Position.z <= curPoints[3].z
			&& 
			Destination.x    <= curPoints[0].x && Destination.x <= curPoints[1].x
			&& Destination.x <= curPoints[2].x && Destination.x <= curPoints[3].x
			&& Destination.z <= curPoints[0].z && Destination.z >= curPoints[1].z
			&& Destination.z >= curPoints[2].z && Destination.z <= curPoints[3].z)
		{
			collision = true;
		}
		//check right direction
		else if(Position.x    < curPoints[0].x && Position.x < curPoints[1].x
			&& Position.x < curPoints[2].x && Position.x < curPoints[3].x
			&& Position.z < curPoints[0].z && Position.z > curPoints[1].z
			&& Position.z > curPoints[2].z && Position.z < curPoints[3].z
			&& 
			Destination.x    > curPoints[0].x && Destination.x > curPoints[1].x
			&& Destination.x > curPoints[2].x && Destination.x > curPoints[3].x
			&& Destination.z < curPoints[0].z && Destination.z > curPoints[1].z
			&& Destination.z > curPoints[2].z && Destination.z < curPoints[3].z)
		{
			collision = true;
		}
	}

	return collision;
}
