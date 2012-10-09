#include "image.h"

#define checkImageWidth 64
#define checkImageHeight 64


GLubyte checkImage[checkImageHeight][checkImageWidth][3];
static GLdouble zoomFactor = 1.0;
static GLint height1;

image::image(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

void image::makeCheckImage()
{
    int i, j, c;
    for (i = 0; i < checkImageHeight; i++) {
    for (j = 0; j < checkImageWidth; j++) {
        c = ((((i&0x8)==0)^((j&0x8))==0))*255;
        checkImage[i][j][0] = (GLubyte) c;
        checkImage[i][j][1] = (GLubyte) c;
        checkImage[i][j][2] = (GLubyte) c;
        }
    }
}

void image::initializeGL()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void image::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2i(0, 0);
    glDrawPixels(checkImageWidth, checkImageHeight, GL_RGB,
    GL_UNSIGNED_BYTE, checkImage);
    glFlush();
}

void image::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    height1 = (GLint) h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*void image::motion(int x, int y)
{
    static GLint screeny;
    screeny = height1 - (GLint) y;
    glRasterPos2i (x, screeny);
    glPixelZoom (zoomFactor, zoomFactor);
    glCopyPixels (0, 0, checkImageWidth, checkImageHeight,
    GL_COLOR);
    glPixelZoom (1.0, 1.0);
    glFlush ();
}

*/
/*
void image::mouseMoveEvent( QMouseEvent *e )
{
    static GLint screeny;
    screeny = height1 - (GLint) e->y();
    glRasterPos2i (e->x(), screeny);
    glPixelZoom (zoomFactor, zoomFactor);
    glCopyPixels (0, 0, checkImageWidth, checkImageHeight,
    GL_COLOR);
    glPixelZoom (1.0, 1.0);
    glFlush ();

}
*/
void image::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_R:
      zoomFactor = 1.0;
      this->repaint();
      printf ("zoomFactor reset to 1.0\n");
      break;

   case Qt::Key_Z:
      zoomFactor += 0.5;
      if (zoomFactor >= 3.0)
      zoomFactor = 3.0;
      this->repaint();
      printf ("zoomFactor is now %4.1f\n", zoomFactor);
      break;

   case Qt::Key_X:
      zoomFactor -= 0.5;
      if (zoomFactor <= 0.5)
      zoomFactor = 0.5;
      this->repaint();
      printf ("zoomFactor is now %4.1f\n", zoomFactor);
      break;

    default:
      break;
   };
}
