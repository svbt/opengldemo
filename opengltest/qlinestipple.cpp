#include "qlinestipple.h"
/*
qlinestipple::qlinestipple()
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}
*/
qlinestipple::qlinestipple(QWidget *parent)
    : QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

void qlinestipple::initializeGL()
{
    // Set up the rendering context, define display lists etc.:
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void qlinestipple::resizeGL(int w, int h)
{
    // setup viewport, projection etc.:
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);

}

void qlinestipple::paintGL()
{
    int i;
    glClear (GL_COLOR_BUFFER_BIT);

 /* select white for all lines  */
    glColor3f (1.0, 1.0, 1.0);

 /* in 1st row, 3 lines, each with a different stipple  */
    glEnable (GL_LINE_STIPPLE);

    glLineStipple (1, 0x0101);  /*  dotted  */
    drawOneLine (50.0, 125.0, 150.0, 125.0);
    glLineStipple (1, 0x00FF);  /*  dashed  */
    drawOneLine (150.0, 125.0, 250.0, 125.0);
    glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
    drawOneLine (250.0, 125.0, 350.0, 125.0);
 /* in 2nd row, 3 wide lines, each with different stipple */
    glLineWidth (5.0);
    glLineStipple (1, 0x0101);  /*  dotted  */
    drawOneLine (50.0, 100.0, 150.0, 100.0);
    glLineStipple (1, 0x00FF);  /*  dashed  */
    drawOneLine (150.0, 100.0, 250.0, 100.0);
    glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
    drawOneLine (250.0, 100.0, 350.0, 100.0);
    glLineWidth (1.0);

 /* in 3rd row, 6 lines, with dash/dot/dash stipple  */
 /* as part of a single connected line strip         */
    glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
    glBegin (GL_LINE_STRIP);
    for (i = 0; i < 7; i++)
       glVertex2f (50.0 + ((GLfloat) i * 50.0), 75.0);
    glEnd ();

 /* in 4th row, 6 independent lines with same stipple  */
    for (i = 0; i < 6; i++) {
       drawOneLine (50.0 + ((GLfloat) i * 50.0), 50.0,
          50.0 + ((GLfloat)(i+1) * 50.0), 50.0);
    }

 /* in 5th row, 1 line, with dash/dot/dash stipple    */
 /* and a stipple repeat factor of 5                  */
    glLineStipple (5, 0x1C47);  /*  dash/dot/dash  */
    drawOneLine (50.0, 25.0, 350.0, 25.0);

    glDisable (GL_LINE_STIPPLE);
    glFlush ();

}

void qlinestipple::mousePressEvent( QMouseEvent *e )
{
    if(e->buttons()==Qt::LeftButton | Qt::RightButton)
    {
        static qlinestipple openanotherwindow;
        openanotherwindow.show();
    }
}
