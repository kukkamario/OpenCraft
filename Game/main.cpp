#include <QImage>
#include <QDebug>
#include "glinclude/glinclude.h"
#include <stdlib.h>
#include <math.h>
#include <cstdio>


void changeSize(int w, int h) {

        // Prevent a divide by zero, when window is too short
        // (you cant make a window of zero width).
        if (h == 0)
                h = 1;

        float ratio =  w * 1.0 / h;

        // Use the Projection Matrix
        glMatrixMode(GL_PROJECTION);

        // Reset Matrix
        glLoadIdentity();

        // Set the viewport to be the entire window
        glViewport(0, 0, w, h);

        // Set the correct perspective.
        gluPerspective(45.0f, ratio, 0.1f, 100.0f);

        // Get Back to the Modelview
        glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;

void renderScene(void)
{

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(	0.0f, 0.0f, 10.0f,
                            0.0f, 0.0f,  0.0f,
                            0.0f, 1.0f,  0.0f);

    glRotatef(angle, 0.2f, 0.8f, 0.0f);

    glBegin(GL_QUADS);

    glBegin(GL_QUADS);                          // Start Drawing Quads
        // Bottom Face
        glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        // Front Face
        glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        // Back Face
        glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        // Right face
        glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        // Left Face
        glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glEnd();

    angle+=0.1f;

    glutSwapBuffers();
}

void main(int argc, char **argv) {

        // init GLUT and create window
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100,100);
        glutInitWindowSize(320,320);
        glutCreateWindow("Lighthouse3D- GLUT Tutorial");

        // register callbacks
        glutDisplayFunc(renderScene);
        glutReshapeFunc(changeSize);
        glutIdleFunc(renderScene);

        // enter GLUT event processing cycle
        glutMainLoop();
}
