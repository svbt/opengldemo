#include "qantialias.h"

qantialias::qantialias(QWidget *parent)
    :QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);

    polySmooth = GL_TRUE;
}

void qantialias::initializeGL()
{
    glCullFace (GL_BACK);
    glEnable (GL_CULL_FACE);
    glBlendFunc (GL_SRC_ALPHA_SATURATE, GL_ONE);
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void qantialias::drawCube(GLdouble x0, GLdouble x1, GLdouble y0,
GLdouble y1, GLdouble z0, GLdouble z1)
{
    GLubyte indices[NFACE][4] = {
        {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3},
        {0, 1, 5, 4}, {1, 5, 6, 2}, {0, 3, 2, 1}
        };

    GLfloat v[8][3];
    GLfloat c[8][4] = {
        {0.0, 0.0, 0.0, 1.0}, {1.0, 0.0, 0.0, 1.0},
        {0.0, 1.0, 0.0, 1.0}, {1.0, 1.0, 0.0, 1.0},
        {0.0, 0.0, 1.0, 1.0}, {1.0, 0.0, 1.0, 1.0},
        {0.0, 1.0, 1.0, 1.0}, {1.0, 1.0, 1.0, 1.0}
         };

    v[0][0] = v[3][0] = v[4][0] = v[7][0] = x0;
    v[1][0] = v[2][0] = v[5][0] = v[6][0] = x1;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = y0;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = y1;
    v[0][2] = v[1][2] = v[2][2] = v[3][2] = z0;
    v[4][2] = v[5][2] = v[6][2] = v[7][2] = z1;
    #ifdef GL_VERSION_1_1
    glEnableClientState (GL_VERTEX_ARRAY);
    glEnableClientState (GL_COLOR_ARRAY);
    glVertexPointer (3, GL_FLOAT, 0, v);
    glColorPointer (4, GL_FLOAT, 0, c);
    glDrawElements(GL_QUADS, NFACE*4, GL_UNSIGNED_BYTE, indices);
    glDisableClientState (GL_VERTEX_ARRAY);
    glDisableClientState (GL_COLOR_ARRAY);
    #else
    printf ("If this is GL Version 1.0, ");
    printf ("vertex arrays are not supported.\n");
    exit(1);
    #endif
}

/* Note: polygons must be drawn from front to back
* for proper blending.
*/

void qantialias::paintGL()
{
    if (polySmooth) {
    glClear (GL_COLOR_BUFFER_BIT);
    glEnable (GL_BLEND);
    glEnable (GL_POLYGON_SMOOTH);
    glDisable (GL_DEPTH_TEST);
    }
    else {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable (GL_BLEND);
    glDisable (GL_POLYGON_SMOOTH);
    glEnable (GL_DEPTH_TEST);
    }
    glPushMatrix ();
    glTranslatef (0.0, 0.0, -8.0);
    glRotatef (30.0, 1.0, 0.0, 0.0);
    glRotatef (60.0, 0.0, 1.0, 0.0);
    drawCube(-0.5, 0.5, -0.5, 0.5, -0.5, 0.5);
    glPopMatrix ();
    glFlush ();
}

void qantialias::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void qantialias::keyPressEvent(QKeyEvent * event)
{
    switch (event->key())
    {
    case Qt::Key_T:
        polySmooth = !polySmooth;
        repaint();
        break;

    case Qt::Key_Escape:
       this->close();
       break;

     default:
       break;
    }
}

