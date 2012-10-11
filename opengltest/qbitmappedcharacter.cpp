#include "qbitmappedcharacter.h"


GLubyte rasters[24] = {
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
0xff, 0xc0, 0xff, 0xc0};


qbitmappedcharacter::qbitmappedcharacter(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}


void qbitmappedcharacter::initializeGL()
{
    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void qbitmappedcharacter::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glRasterPos2i (20, 20);
    glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
    glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
    glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
    glFlush();
}

void qbitmappedcharacter::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void qbitmappedcharacter::mousePressEvent( QMouseEvent *e )
{
    if(e->buttons()==Qt::LeftButton | Qt::RightButton)
    {
        static qbitmappedcharacter openanotherwindow;
        openanotherwindow.show();
    }
}
