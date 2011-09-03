#include <QImage>
#include <QDebug>
#include "glinclude/glinclude.h"
#include <stdlib.h>
#include <math.h>
#include <cstdio>

GLuint texture;

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
        gluPerspective(70.0f, ratio, 0.1f, 100.0f);

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

    glPushMatrix();
    glRotatef(angle, 0.3f, 0.6f, 0.1f);

    glBindTexture(GL_TEXTURE_2D,texture);
    glBegin(GL_QUADS);
        // Start Drawing Quads

        //Top face
        glTexCoord2d(0,0);glVertex3f(-1.0f, 1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2d(0.25,0);glVertex3f( 1.0f, 1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2d(0.25,1);glVertex3f( 1.0f, 1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2d(0,1);glVertex3f(-1.0f, 1.0f,  1.0f);  // Bottom Right Of The Texture and Quad

        // Bottom Face
        glTexCoord2d(1,0);glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2d(0.75,0);glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2d(0.75,1);glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2d(1,1);glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        // Front Face
        glTexCoord2d(0.5,1);glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2d(0.75,1);glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2d(0.75,0);glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2d(0.5,0);glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        // Back Face
        glTexCoord2d(0.75,1);glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2d(0.75,0);glVertex3f(1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2d(0.5,0);glVertex3f( -1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2d(0.5,1);glVertex3f( -1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        // Right face
        glTexCoord2d(0.75,1);glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2d(0.75,0);glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2d(0.5,0);glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2d(0.5,1);glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        // Left Face
        glTexCoord2d(0.5,1);glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2d(0.75,1);glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2d(0.75,0);glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2d(0.5,0);glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glEnd();
    glPopMatrix();

    angle+=0.1f;

    glutSwapBuffers();
}

void main(int argc, char **argv)
{

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("OpenCraft");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    glEnable(GL_TEXTURE_2D);
    QImage image("gfx/test.png");//Ladataan kuva
    image = image.convertToFormat(QImage::Format_RGB888); //Varmistetaan että oikea formaatti 24bittinen 8,8,8
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the original
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // the texture wraps over at the edges (repeat)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    gluBuild2DMipmaps(GL_TEXTURE_2D,3,image.width(),image.height(),GL_RGB,GL_UNSIGNED_BYTE,image.constBits());


    // enter GLUT event processing cycle
    glutMainLoop();

    glDeleteTextures(1,&texture);
}
