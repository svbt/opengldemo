#ifndef QBLENDING3D_H
#define QBLENDING3D_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>

#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#define MAXZ 8.0
#define MINZ -8.0
#define ZINC 0.4

class qblending3d : public QGLWidget
{
    Q_OBJECT

private:
    float solidZ;
    float transparentZ;
    GLuint sphereList, cubeList;

public:
    qblending3d(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );
    void mousePressEvent( QMouseEvent *e );

    void animate();

signals:

public slots:

};

#endif // QBLENDING3D_H
