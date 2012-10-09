#include "qstroke.h"

char *test1 = "A SPARE SERAPE APPEARS AS";
char *test2 = "APES PREPARE RARE PEPPERS";

CP Adata[] = {
{ 0, 0, PT}, {0, 9, PT}, {1, 10, PT}, {4, 10, PT},
{5, 9, PT}, {5, 0, STROKE}, {0, 5, PT}, {5, 5, END}
};
CP Edata[] = {
{5, 0, PT}, {0, 0, PT}, {0, 10, PT}, {5, 10, STROKE},
{0, 5, PT}, {4, 5, END}
};
CP Pdata[] = {
{0, 0, PT}, {0, 10, PT}, {4, 10, PT}, {5, 9, PT}, {5, 6, PT},
{4, 5, PT}, {0, 5, END}
};
CP Rdata[] = {
{0, 0, PT}, {0, 10, PT}, {4, 10, PT}, {5, 9, PT}, {5, 6, PT},
{4, 5, PT}, {0, 5, STROKE}, {3, 5, PT}, {5, 0, END}
};
CP Sdata[] = {
{0, 1, PT}, {1, 0, PT}, {4, 0, PT}, {5, 1, PT}, {5, 4, PT},
{4, 5, PT}, {1, 5, PT}, {0, 6, PT}, {0, 9, PT}, {1, 10, PT},
{4, 10, PT}, {5, 9, END}
};

qstroke::qstroke(QWidget *parent) :
    QGLWidget(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);
}

/* drawLetter() interprets the instructions from the array
* for that letter and renders the letter with line segments.
*/
void qstroke::drawLetter(CP *l)
{
    glBegin(GL_LINE_STRIP);
    while (1)
    {
    switch (l->type)
    {
        case PT:
            glVertex2fv(&l->x);
        break;
        case STROKE:
            glVertex2fv(&l->x);
            glEnd();
            glBegin(GL_LINE_STRIP);
        break;
        case END:
            glVertex2fv(&l->x);
            glEnd();
            glTranslatef(8.0, 0.0, 0.0);
        return;
    }
    l++;
    }
}

void qstroke::initializeGL()
{
    GLuint base;
    glShadeModel (GL_FLAT);
    base = glGenLists (128);
    glListBase(base);
    glNewList(base+'A', GL_COMPILE); drawLetter(Adata);
    glEndList();
    glNewList(base+'E', GL_COMPILE); drawLetter(Edata);
    glEndList();
    glNewList(base+'P', GL_COMPILE); drawLetter(Pdata);
    glEndList();
    glNewList(base+'R', GL_COMPILE); drawLetter(Rdata);
    glEndList();
    glNewList(base+'S', GL_COMPILE); drawLetter(Sdata);
    glEndList();
    glNewList(base+' ', GL_COMPILE);
    glTranslatef(8.0, 0.0, 0.0);
    glEndList();
}

void qstroke::printStrokedString(char *s)
{
    GLsizei len = strlen(s);
    glCallLists(len, GL_BYTE, (GLbyte *)s);
}

void qstroke::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    glTranslatef(10.0, 30.0, 0.0);
    printStrokedString(test1);
    glPopMatrix();
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    glTranslatef(10.0, 13.0, 0.0);
    printStrokedString(test2);
    glPopMatrix();
    glFlush();
}

void qstroke::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}


void qstroke::keyPressEvent ( QKeyEvent * event )
{
  switch(event->key())
   {
   case Qt::Key_Space:
      this->repaint();
      break;

   case Qt::Key_Escape:
      this->close();
      break;

    default:
      break;
   };
}

