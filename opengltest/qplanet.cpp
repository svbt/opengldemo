#include "qplanet.h"

qplanet::qplanet(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
    year=0;
    day=0;
}

void qplanet::initializeGL()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void qplanet::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glPushMatrix();
    glutWireSphere(1.0, 20, 16); /* draw sun */
    glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
    glTranslatef (2.0, 0.0, 0.0);
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
    glutWireSphere(0.2, 10, 8); /* draw smaller planet */
    glPopMatrix();
    glFlush ();
}

void qplanet::resizeGL(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void qplanet::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_D:
      day = (day + 10) % 360;
      repaint();
      break;

   case Qt::Key_E:
      day = (day - 10) % 360;
      repaint();
      break;

   case Qt::Key_Y:
      year = (year + 5) % 360;
      repaint();
      break;

   case Qt::Key_Z:
      year = (year - 5) % 360;
      repaint();
      break;

   case Qt::Key_Escape:
      this->close();
      break;

    default:
      break;
   };
}
