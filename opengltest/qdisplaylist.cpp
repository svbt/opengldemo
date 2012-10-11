#include "qdisplaylist.h"

GLuint listName;

qdisplaylist::qdisplaylist(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

void qdisplaylist::initializeGL()
{
    listName = glGenLists (1);
    glNewList (listName, GL_COMPILE);
    glColor3f (1.0, 0.0, 0.0); /* current color red */
    glBegin (GL_TRIANGLES);
    glVertex2f (0.0, 0.0);
    glVertex2f (1.0, 0.0);
    glVertex2f (0.0, 1.0);
    glEnd ();
    glTranslatef (1.5, 0.0, 0.0); /* move position */
    glEndList ();
    glShadeModel (GL_FLAT);

}

void qdisplaylist::drawLine()
{
    glBegin (GL_LINES);
    glVertex2f (0.0, 0.5);
    glVertex2f (15.0, 0.5);
    glEnd ();
}

void qdisplaylist::paintGL()
{
    GLuint i;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0); /* current color green */
    for (i = 0; i < 10; i++) /* draw 10 triangles */
    {
        glCallList (listName);
    }
    drawLine (); /* is this line green? NO! */
    /* where is the line drawn? */
    glFlush ();
}

void qdisplaylist::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    gluOrtho2D (0.0, 2.0, -0.5 * (GLfloat) h/(GLfloat) w,
    1.5 * (GLfloat) h/(GLfloat) w);
    else
    gluOrtho2D (0.0, 2.0*(GLfloat) w/(GLfloat) h, -0.5, 1.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void qdisplaylist::mousePressEvent( QMouseEvent *e )
{
    if(e->buttons()==Qt::LeftButton | Qt::RightButton)
    {
        static qdisplaylist openanotherwindow;
        openanotherwindow.show();
    }
}
