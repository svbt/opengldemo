#ifndef STENCILBUFFERTEST_H
#define STENCILBUFFERTEST_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>

class stencilbuffertest : public QGLWidget
{
    Q_OBJECT
public:
    stencilbuffertest(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:

};

#endif // STENCILBUFFERTEST_H
