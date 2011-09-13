
#include <QApplication>
#include "screenstatemanager.h"
#include "mainwindow.h"
#include "glinclude/glinclude.h"


//void windowResize(int w, int h)
//{
//    ScreenStateManager::instance()->windowResize(w,h);
//}

//void renderScene(void)
//{
//    // Clear Color and Depth Buffers
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


//    ScreenStateManager::instance()->render();

//    glutSwapBuffers();
//}

//void keyPressEvent(unsigned char key, int mouseX, int mouseY)
//{
//    ScreenStateManager::instance()->keyPressEvent(key,mouseX,mouseY);
//}

//void keyReleaseEvent(unsigned char key, int mouseX, int mouseY)
//{
//    ScreenStateManager::instance()->keyReleaseEvent(key,mouseX,mouseY);
//}

//void specialKeyPressEvent(int key, int mouseX, int mouseY)
//{
//    ScreenStateManager::instance()->specialKeyPressEvent(key,mouseX,mouseY);
//}

//void specialKeyReleaseEvent(int key, int mouseX, int mouseY)
//{
//    ScreenStateManager::instance()->specialKeyReleaseEvent(key,mouseX,mouseY);
//}

//void mouseEvent(int button, int state, int x, int y)
//{
//    ScreenStateManager::instance()->mouseEvent(button,state,x,y);
//}

//void mouseWheelEvent(int wheel,int direction,int,int)
//{
//    ScreenStateManager::instance()->mouseWheelEvent(wheel,direction);
//}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    QApplication app(argc,argv);
    MainWindow window;

    if (!ScreenStateManager::instance()->init(320,320))
    {
        qCritical("Can't initialize ScreenStateManager.");
        return 1;
    }
    loadExtension(window.context());
    window.show();
    return app.exec();


//    // init GLUT and create window
//    glutInit(&argc, argv);

//    typedef bool (APIENTRY *PFNWGLSWAPINTERVALFARPROC)(int);
//    PFNWGLSWAPINTERVALFARPROC wglSwapIntervalEXT = 0;
//    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALFARPROC)wglGetProcAddress("wglSwapIntervalEXT");
//    if (wglSwapIntervalEXT)wglSwapIntervalEXT(0);

//    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
//    glutInitWindowPosition(100,100);
//    glutInitWindowSize(320,320);
//    glutCreateWindow("OpenCraft");

//    if (!ScreenStateManager::instance()->init(320,320))
//    {
//        qCritical("Can't initialize ScreenStateManager.");
//        return 1;
//    }
//    // register callbacks
//    glutDisplayFunc(&renderScene);
//    glutReshapeFunc(&windowResize);
//    glutIdleFunc(&renderScene);
//    glutKeyboardUpFunc(&keyReleaseEvent);
//    glutKeyboardFunc(&keyPressEvent);
//    glutSpecialFunc(&specialKeyPressEvent);
//    glutSpecialUpFunc(&specialKeyReleaseEvent);
//    glutMouseFunc(&mouseEvent);
//    glutMouseWheelFunc(&mouseWheelEvent);

//    glEnable(GL_ALPHA_TEST);


//    // enter GLUT event processing cycle
//    glutMainLoop();
    return 0;
}
