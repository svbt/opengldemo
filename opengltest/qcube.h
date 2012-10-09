#ifndef QCUBE_H
#define QCUBE_H


#include <QGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

class qcube : public QGLWidget
{
    Q_OBJECT

public:

    qcube(QWidget *parent)
        : QGLWidget(parent)
    {
        this->setMaximumSize(500,500);
        this->setMinimumSize(500,500);
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

    void initializeGL()
    {
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_FLAT);
    }

    void resizeGL(int w, int h)
    {
        glViewport (0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
        glMatrixMode (GL_MODELVIEW);
    }

signals:

public slots:

};

#endif // QCUBE_H
