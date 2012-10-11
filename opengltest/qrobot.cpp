#include "qrobot.h"

qrobot::qrobot(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
    shoulder=30;
    elbow=30;
}

void qrobot::initializeGL()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void qrobot::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();

    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();



    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef (1.0, 0.4, 0.25);
    glutWireCube (1.0);
    glPopMatrix();

    glTranslatef (0.0, 0.0, 0.25);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (1.0, 0.4, 0.25);
    glutWireCube (1.0);
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

void qrobot::resizeGL(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}

void qrobot::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_S:
      shoulder = (shoulder + 5) % 360;
      this->repaint();
      break;
   case Qt::Key_T:
      shoulder = (shoulder - 5) % 360;
      this->repaint();
      break;

   case Qt::Key_E:
      elbow = (elbow + 5) % 360;
      this->repaint();
      break;

   case Qt::Key_F:
      elbow = (elbow - 5) % 360;
      this->repaint();
      break;

   case Qt::Key_Escape:
      this->close();
      break;

    default:
      break;
   };
}

void qrobot::mousePressEvent( QMouseEvent *e )
{
    if(e->buttons()==Qt::LeftButton | Qt::RightButton)
    {
        static qrobot openanotherwindow;
        openanotherwindow.show();
    }
}
