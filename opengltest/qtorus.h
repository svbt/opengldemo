#ifndef QTORUS_H
#define QTORUS_H

#include <QGLWidget>
#include <QKeyEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <glut.h>
#include <stdlib.h>


class qtorus : public QGLWidget
{
    Q_OBJECT
public:
    qtorus(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );

    void torus(int numc, int numt);

signals:

public slots:

};

#endif // QTORUS_H
