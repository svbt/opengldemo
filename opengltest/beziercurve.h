#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <glut.h>

class beziercurve : public QGLWidget
{
    Q_OBJECT
public:
    beziercurve(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:

};

#endif // BEZIERCURVE_H
