#ifndef BEZIERTEXTURESURFACE_H
#define BEZIERTEXTURESURFACE_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <glut.h>
#include <math.h>


class beziertexturesurface : public QGLWidget
{
    Q_OBJECT
public:
    beziertexturesurface(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void makeImage();
signals:

public slots:

};

#endif // BEZIERTEXTURESURFACE_H
