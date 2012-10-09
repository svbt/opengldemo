#include "texturemapsub.h"

/* Create checkerboard textures */
#define checkImageWidth2 64
#define checkImageHeight2 64
#define subImageWidth 16
#define subImageHeight 16
static GLubyte checkImage[checkImageHeight2][checkImageWidth2][4];
static GLubyte subImage[subImageHeight][subImageWidth][4];
static GLuint texName;

texturemapsub::texturemapsub(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

void texturemapsub::makeCheckImage(void)
{
    int i, j, c;
    for (i = 0; i < checkImageHeight2; i++) {
        for (j = 0; j < checkImageWidth2; j++) {
            c = ((((i&0x8)==0)^((j&0x8))==0))*255;
            checkImage[i][j][0] = (GLubyte) c;
            checkImage[i][j][1] = (GLubyte) c;
            checkImage[i][j][2] = (GLubyte) c;
            checkImage[i][j][3] = (GLubyte) 255;
        }
    }
    for (i = 0; i < subImageHeight; i++) {
        for (j = 0; j < subImageWidth; j++) {
            c = ((((i&0x4)==0)^((j&0x4))==0))*255;
            subImage[i][j][0] = (GLubyte) c;
            subImage[i][j][1] = (GLubyte) 0;
            subImage[i][j][2] = (GLubyte) 0;
            subImage[i][j][3] = (GLubyte) 255;
        }
    }
}


void texturemapsub::initializeGL()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
    GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth2,
    checkImageHeight2, 0, GL_RGBA, GL_UNSIGNED_BYTE,
    checkImage);
}

void texturemapsub::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texName);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
    glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
}

void texturemapsub::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.6);
}

void texturemapsub::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_S:
      glBindTexture(GL_TEXTURE_2D, texName);
      glTexSubImage2D(GL_TEXTURE_2D, 0, 12, 44,
      subImageWidth, subImageHeight, GL_RGBA,
      GL_UNSIGNED_BYTE, subImage);
      this->repaint();
      break;

   case Qt::Key_R:
      glBindTexture(GL_TEXTURE_2D, texName);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
      checkImageWidth2, checkImageHeight2, 0,
      GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
      this->repaint();
      break;

   case Qt::Key_Escape:
      this->close();
      break;

    default:
      break;
   };
}
