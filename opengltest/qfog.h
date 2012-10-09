#ifndef QFOG_H
#define QFOG_H

#include <QGLWidget>
#include <QKeyEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>


static GLint qfogMode;
class qfog : public QGLWidget
{
    Q_OBJECT

public:
     qfog(QWidget *parent=0);
     void renderSphere (GLfloat x, GLfloat y, GLfloat z);
     void initializeGL();
     void paintGL();
     void resizeGL(int w, int h);
     void keyPressEvent ( QKeyEvent * event );


signals:

public slots:

};

#endif // QFOG_H
