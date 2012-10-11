#include "texturegeneration.h"

#define stripeImageWidth 32
GLubyte stripeImage[4*stripeImageWidth];
static GLuint texName;

/* planes for texture coordinate generation */
static GLfloat xequalzero[] = {1.0, 0.0, 0.0, 0.0};
static GLfloat slanted[] = {1.0, 1.0, 1.0, 0.0};
static GLfloat *currentCoeff;
static GLenum currentPlane;
static GLint currentGenMode;

texturegeneration::texturegeneration(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

void texturegeneration::makeStripeImage(void)
{
    int j;
    for (j = 0; j < stripeImageWidth; j++) {
        stripeImage[4*j] = (GLubyte) ((j<=4) ? 255 : 0);
        stripeImage[4*j+1] = (GLubyte) ((j>4) ? 255 : 0);
        stripeImage[4*j+2] = (GLubyte) 0;
        stripeImage[4*j+3] = (GLubyte) 255;
    }
}

void texturegeneration::initializeGL()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    makeStripeImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_1D, texName);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER,
    GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER,
    GL_LINEAR);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,
    GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    currentCoeff = xequalzero;
    currentGenMode = GL_OBJECT_LINEAR;
    currentPlane = GL_OBJECT_PLANE;
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
    glTexGenfv(GL_S, currentPlane, currentCoeff);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_1D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glMaterialf (GL_FRONT, GL_SHININESS, 64.0);
}

void texturegeneration::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix ();
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_1D, texName);
    glutSolidTeapot(2.0);
    glPopMatrix ();
    glFlush();
}

void texturegeneration::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    glOrtho (-3.5, 3.5, -3.5*(GLfloat)h/(GLfloat)w,
    3.5*(GLfloat)h/(GLfloat)w, -3.5, 3.5);
    else
    glOrtho (-3.5*(GLfloat)w/(GLfloat)h,
    3.5*(GLfloat)w/(GLfloat)h, -3.5, 3.5, -3.5, 3.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void texturegeneration::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_E:
      currentGenMode = GL_EYE_LINEAR;
      currentPlane = GL_EYE_PLANE;
      glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
      glTexGenfv(GL_S, currentPlane, currentCoeff);
      this->repaint();
      break;

   case Qt::Key_O:
      currentGenMode = GL_OBJECT_LINEAR;
      currentPlane = GL_OBJECT_PLANE;
      glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
      glTexGenfv(GL_S, currentPlane, currentCoeff);
      this->repaint();
      break;

   case Qt::Key_S:
      currentCoeff = slanted;
      glTexGenfv(GL_S, currentPlane, currentCoeff);
      this->repaint();
      break;

   case Qt::Key_X:
      currentCoeff = xequalzero;
      glTexGenfv(GL_S, currentPlane, currentCoeff);
      this->repaint();
      break;

   case Qt::Key_Escape:
      this->close();
      break;

    default:
      break;
   };
}

void texturegeneration::mousePressEvent( QMouseEvent *e )
{
    if(e->buttons()==Qt::LeftButton | Qt::RightButton)
    {
        static texturegeneration openanotherwindow;
        openanotherwindow.show();
    }
}
