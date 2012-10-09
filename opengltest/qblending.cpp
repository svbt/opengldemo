#include "qblending.h"

qblending::qblending(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
    leftFirst = GL_TRUE;
}

void qblending::initializeGL()
{
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel (GL_FLAT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void qblending::drawLeftTriangle()
{
/* draw yellow triangle on LHS of screen */
glBegin (GL_TRIANGLES);
glColor4f(1.0, 1.0, 0.0, 0.75);
glVertex3f(0.1, 0.9, 0.0);
glVertex3f(0.1, 0.1, 0.0);
glVertex3f(0.7, 0.5, 0.0);
glEnd();
}

void qblending::drawRightTriangle()
{
    /* draw cyan triangle on RHS of screen */
    glBegin (GL_TRIANGLES);
    glColor4f(0.0, 1.0, 1.0, 0.75);
    glVertex3f(0.9, 0.9, 0.0);
    glVertex3f(0.3, 0.5, 0.0);
    glVertex3f(0.9, 0.1, 0.0);
    glEnd();
}

void qblending::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (leftFirst) {
    drawLeftTriangle();
    drawRightTriangle();
    }
    else {
    drawRightTriangle();
    drawLeftTriangle();
    }
    glFlush();
}

void qblending::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    gluOrtho2D (0.0, 1.0, 0.0, 1.0*(GLfloat)h/(GLfloat)w);
    else
    gluOrtho2D (0.0, 1.0*(GLfloat)w/(GLfloat)h, 0.0, 1.0);
}

void qblending::keyPressEvent ( QKeyEvent * event )
{
    switch(event->key())
     {
     case Qt::Key_T:
        leftFirst = !leftFirst;
        this->repaint();
        break;

     case Qt::Key_Escape:
        this->close();
        break;

      default:
        break;
     };
}
