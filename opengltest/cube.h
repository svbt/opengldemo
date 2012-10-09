#ifndef CUBE_H
#define CUBE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include <QGLWidget>

class cube : public QGLWidget
{
    Q_OBJECT

public:
    cube(QWidget *parent)
        : QGLWidget(parent)
    {
        this->setMaximumSize(500,500);
        this->setMinimumSize(500,500);
    }

    void initializeGL()
    {
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_FLAT);
    }

    void paintGL()
    {
        glClear (GL_COLOR_BUFFER_BIT);
        glColor3f (1.0, 1.0, 1.0);
        glLoadIdentity (); /* clear the matrix */

        /* viewing transformation */
        gluLookAt (0.0, 0.0, 5.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
        glScalef (1.0, 2.0, 1.0); /* modeling transformation */
        glutWireCube (1.0);
        glFlush ();

    }
    void resizeGL(int w, int h)
    {
        glViewport (0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
        glMatrixMode (GL_MODELVIEW);

    }

};
#endif // CUBE_H
