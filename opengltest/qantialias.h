#ifndef QANTIALIAS_H
#define QANTIALIAS_H

#include <QGLWidget>
#include <QKeyEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NFACE 6
#define NVERT 8


class qantialias : public QGLWidget
{
    Q_OBJECT

private:
    GLboolean polySmooth;


public:
    qantialias(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );

    void drawCube(GLdouble x0, GLdouble x1, GLdouble y0,
                  GLdouble y1, GLdouble z0, GLdouble z1);
};
#endif // QANTIALIAS_H
