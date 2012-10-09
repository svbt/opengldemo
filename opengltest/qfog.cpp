#include "qfog.h"

qfog::qfog(QWidget *parent)
    :QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

void qfog::initializeGL()
{
    // Set up the rendering context, define display lists etc.:
    GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 };
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    {
        GLfloat mat[3] = {0.1745, 0.01175, 0.01175};
        glMaterialfv (GL_FRONT, GL_AMBIENT, mat);
        mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
        glMaterialfv (GL_FRONT, GL_DIFFUSE, mat);
        mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
        glMaterialfv (GL_FRONT, GL_SPECULAR, mat);
        glMaterialf (GL_FRONT, GL_SHININESS, 0.6*128.0);
        }
    glEnable(GL_FOG);
    {
        GLfloat qfogColor[4] = {0.5, 0.5, 0.5, 1.0};
        qfogMode = GL_EXP;
        glFogi (GL_FOG_MODE, qfogMode);
        glFogfv (GL_FOG_COLOR, qfogColor);
        glFogf (GL_FOG_DENSITY, 0.35);
        glHint (GL_FOG_HINT, GL_DONT_CARE);
        glFogf (GL_FOG_START, 1.0);
        glFogf (GL_FOG_END, 5.0);
    }
    glClearColor(0.5, 0.5, 0.5, 1.0); /* qfog color */
}

void qfog::resizeGL(int w, int h)
{
    // setup viewport, projection etc.:
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    glOrtho (-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,
    2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
    glOrtho (-2.5*(GLfloat)w/(GLfloat)h,
    2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
}

void qfog::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderSphere (-2., -0.5, -1.0);
    renderSphere (-1., -0.5, -2.0);
    renderSphere (0., -0.5, -3.0);
    renderSphere (1., -0.5, -4.0);
    renderSphere (2., -0.5, -5.0);
    glFlush();
}

void qfog::renderSphere (GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
    glTranslatef (x, y, z);
    glutSolidSphere(0.4, 16, 16);
    glPopMatrix();
}

void qfog::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_F:
      if (qfogMode == GL_EXP) {
      qfogMode = GL_EXP2;
      printf ("Fog mode is GL_EXP2\n");
      }
      else if (qfogMode == GL_EXP2) {
      qfogMode = GL_LINEAR;
      printf ("Fog mode is GL_LINEAR\n");
      }
      else if (qfogMode == GL_LINEAR) {
      qfogMode = GL_EXP;
      printf ("Fog mode is GL_EXP\n");
      }
      glFogi (GL_FOG_MODE, qfogMode);
      this->repaint();
      break;

   case Qt::Key_Escape:
      this->close();
      break;

    default:
      break;
   };
}
