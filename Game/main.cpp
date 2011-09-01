#include <QImage>
#include <QDebug>
#include "glinclude/glinclude.h"
#include <stdlib.h>
#include <math.h>
#include <cstdio>


GLuint textureId;


void GLFWCALL windowResize( int width, int height )
{
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60,(float)width / (float)height,1,1000);
    glViewport(0,0,width,height);
    glMatrixMode(GL_MODELVIEW);
}

void renderScene()
{
    gluLookAt(0,0,10,0,0,0,0,1,0);
    glRotated(0.2,0.4,0.5,-0.1);
    glBegin(GL_QUADS);

    //Takaseinä:
    glVertex3d(-0.5,-0.5,0.5);
    glVertex3d(0.5,-0.5,0.5);
    glVertex3d(-0.5,0.5,0.5);
    glVertex3d(0.5,0.5,0.5);

    //Etuseinä:
    glVertex3d(-0.5,-0.5,-0.5);
    glVertex3d(0.5,-0.5,-0.5);
    glVertex3d(-0.5,0.5,-0.5);
    glVertex3d(0.5,0.5,-0.5);

    //Oikea sivu:
    glVertex3d(0.5,-0.5,0.5);
    glVertex3d(0.5,-0.5,-0.5);
    glVertex3d(0.5,0.5,-0.5);
    glVertex3d(0.5,0.5,0.5);

    //Vasen sivu:
    glVertex3d(-0.5,-0.5,0.5);
    glVertex3d(-0.5,-0.5,-0.5);
    glVertex3d(-0.5,0.5,-0.5);
    glVertex3d(-0.5,0.5,0.5);

    //Pohja:
    glVertex3d(-0.5,-0.5,-0.5);
    glVertex3d(-0.5,-0.5,0.5);
    glVertex3d(0.5,-0.5,0.5);
    glVertex3d(0.5,-0.5,-0.5);

    //Kansi:
    glVertex3d(-0.5,0.5,-0.5);
    glVertex3d(-0.5,0.5,0.5);
    glVertex3d(0.5,0.5,0.5);
    glVertex3d(0.5,0.5,-0.5);
    glEnd();
}


int main( void )
{
    qDebug("Started");
    int running = GL_TRUE;
    // Initialize GLFW
    if( !glfwInit() )
    {
        exit( EXIT_FAILURE );
    }
    // Open an OpenGL window
    if( !glfwOpenWindow( 800,600, 8,8,8,8,24,0, GLFW_WINDOW ) )
    {
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    if (!loadExtension())
    {
        qCritical("Your graphicscard doesn't support required OpenGL extensions...");
        glfwCloseWindow();
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowTitle("OpenCraft");
    qDebug("Window open");


    glfwSetWindowSizeCallback(windowResize);


    glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

    windowResize(300,300);
    // Main loop
    while( running )
    {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        renderScene();

        glfwSwapBuffers();


        running = !glfwGetKey( GLFW_KEY_ESC ) &&
        glfwGetWindowParam( GLFW_OPENED );
    }

    glfwTerminate();
    exit( EXIT_SUCCESS );
}
