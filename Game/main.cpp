#include <QImage>
#include "glinclude.h"
#include <stdlib.h>
#include <math.h>
#include <cstdio>


GLuint textureId;


void GLFWCALL windowResize( int width, int height )
{
	glMatrixMode(GL_PROJECTION);
	glPerspective(60,(float)width / (float)height,1,1000);
    glViewport(0,0,width,height);
	glMatrixMode(GL_MODELVIEW);
}

void renderScene()
{
	gluLookAt(0,0,10,0,0,0,0,1,0);
	glBegin(GL_QUADS);
	
	glEnd();
}


int main(int argc, char **argv)
{
    if (!loadExtension())
    {
        printf("Your graphicscard doesn't support required opengl extensions");
        return 0;
    }


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("OpenCraft");
    windowResize(320,320);

    glutDisplayFunc(renderScene);
    glutReshapeFunc(windowResize);




    glutIdleFunc(renderScene);


    glutMainLoop();

}
