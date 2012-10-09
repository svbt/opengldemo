#ifndef QLINESTIPPLE_H
#define QLINESTIPPLE_H

#include <QGLWidget>
#include <GL/gl.h>

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

class qlinestipple : public QGLWidget
{
    Q_OBJECT

public:
    qlinestipple(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:

};

#endif // QLINESTIPPLE_H
