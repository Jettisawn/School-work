#include "stdafx.h"

// contents of boss maze
SceneObj * maze;
SceneObj * sphere;
// Rotation amounts
GLfloat xRot = 0.0f;
GLfloat zRot = 0.0f;

int iOutline = 0;

CCamera Camera;
SceneGraph graph;

GLuint _textureId1;

static void Reset()
{
	xRot = zRot = 0.0f;
	graph.Reset();
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	
	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();
	//Angle of view:35 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0
	gluPerspective(35.0,(GLdouble)x/(GLdouble)y,0.5,120.0);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,x,y);  //Use the whole window for rendering

	Image*  image = loadBMP("AbombBoom.bmp"); // Texture loaded to the sphere

	_textureId1 = loadTexture(image); //load texture to ID

	delete image; // delete image, no longer needed


}

//setup rendering context
void SetupRC()
{
    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.45f, 0.45f, 0.45f, 1.0f };
    GLfloat  sourceLight[] = { 0.75f, 0.75f, 0.75f, 1.0f };
    GLfloat	 lightPos[] = { -50.f, 25.0f, 250.0f, 0.0f };

    glEnable(GL_DEPTH_TEST);	// Hidden surface removal
    glFrontFace(GL_CCW);		// Counter clock-wise polygons face out

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

	GLfloat light1_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat light1_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light1_specular[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat light1_position[] = { 0.0, 5.0, 0.0, 1.0 };
	GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, .1);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.05);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 100.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);
	glEnable(GL_LIGHT1);
	

	// Enable color tracking
    glEnable(GL_COLOR_MATERIAL);
	
    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
}

void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(30.0f, fAspect, 1.0, 400.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void RenderScene()
{
	graph.Render(Camera, iOutline);
}

void ProcessMenu(int value)
	{
	switch(value)
		{
		case 1:
			iOutline = !iOutline;
		default:
			break;
		}

	glutPostRedisplay();
}

void KeyDown(unsigned char key, int x, int y)
{
	switch (key) 
	{
	case 27:		//ESC
		PostQuitMessage(0);
		break;
	case 'a':		
		Camera.RotateY(2.0);
		break;
	case 'd':		
		Camera.RotateY(-2.0);
		break;
	case 'w':
		Camera.MoveForwards( -1.0 ) ;
		break;
	case 's':		
		Camera.MoveForwards( 1.0 ) ;
		break;
	case 'x':		
		Camera.RotateX(2.0);
		break;
	case 'y':		
		Camera.RotateX(-2.0);
		break;
	case 'q':		
		Camera.StrafeRight(-0.1);
		break;
	case 'e':		
		Camera.StrafeRight(0.1);
		break;
	case 'f':
		Camera.Move(F3dVector(0.0,-0.3,0.0));
		break;
	case 'r':
		Camera.Move(F3dVector(0.0,0.3,0.0));
		break;
	case '`':
		Reset();
		break;
	}

	glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		if(xRot > -45)	
			--xRot;
			break;

	case GLUT_KEY_RIGHT:
	
		if(zRot > -45)
			--zRot;
		break;

	case GLUT_KEY_LEFT:
		if(zRot < 45)
			++zRot;
		break;

	case GLUT_KEY_DOWN:
		if(xRot < 45)	
			++xRot;
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("BOSS Maze");

	glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Toggle outline back",1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	maze = new Maze(&graph);
	sphere = new Sphere(&graph);
	graph.Add(maze);
	graph.Add(sphere);

	Camera.Move( F3dVector(0.0, 60.0, 50.0 ));
	Camera.RotateX(-45);
	//Camera.MoveForwards( 1.0 );

    glutDisplayFunc(RenderScene);
	glutReshapeFunc(reshape);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(KeyDown);
	glutSpecialFunc(SpecialKeys);
	glutIdleFunc(RenderScene);

    SetupRC();

	glutReshapeFunc(reshape);
//    glutMouseFunc(mouse);

    glutMainLoop();
    
    return 0;
}