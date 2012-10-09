#ifndef QLIGHT_H
#define QLIGHT_H

#include <QGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

class qlight : public QGLWidget
{
    Q_OBJECT

public:
    //qlight(QWidget *parent = 0);

    qlight(QWidget *parent)
        : QGLWidget(parent)
    {
        this->setMaximumSize(500,500);
        this->setMinimumSize(500,500);
    }

    void paintGL()
    {
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidSphere (1.0, 20, 16);
        glFlush ();
    }

    void initializeGL()
    {
        GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat mat_shininess[] = { 50.0 };
        GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
    }

    void resizeGL(int w, int h)
    {
        glViewport (0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();
        if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
        1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
        else
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
        1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

signals:

public slots:

};
#endif // QLIGHT_H
