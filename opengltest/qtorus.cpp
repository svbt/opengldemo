#include "qtorus.h"

GLuint theTorus;

qtorus::qtorus(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

void qtorus::initializeGL()
{
    theTorus = glGenLists (1);
    glNewList(theTorus, GL_COMPILE);
    torus(8, 25);
    glEndList();
    glShadeModel(GL_FLAT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}
void qtorus::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glCallList(theTorus);
    glFlush();
}
void qtorus::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (GLfloat) w/(GLfloat) h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void qtorus::torus(int numc, int numt)
{
    int i, j, k;
    double s, t, x, y, z, twopi, M_PI;
    M_PI=3.14;
    twopi = 2 * M_PI;
    for (i = 0; i < numc; i++)
    {
    glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= numt; j++)
        {
            for (k = 1; k >= 0; k--)
            {
                s = (i + k) % numc + 0.5;
                t = j % numt;
                x = (1+.1*cos(s*twopi/numc))*cos(t*twopi/numt);
                y = (1+.1*cos(s*twopi/numc))*sin(t*twopi/numt);
                z = .1 * sin(s * twopi / numc);
                glVertex3f(x, y, z);
            }
        }
    glEnd();
    }
}

void qtorus::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_X:
      glRotatef(30.,1.0,0.0,0.0);
      this->repaint();
      break;
   case Qt::Key_Y:
      glRotatef(30.,0.0,1.0,0.0);
      this->repaint();
      break;

   case Qt::Key_I:
      glLoadIdentity();
      gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
      this->repaint();
      break;

   case Qt::Key_Escape:
      this->close();
      break;

    default:
      break;
   };
}
