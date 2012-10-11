#ifndef QROBOT_H
#define QROBOT_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>


class qrobot : public QGLWidget
{
    Q_OBJECT
private:
    int shoulder, elbow;

public:
     qrobot(QWidget *parent = 0);
     void initializeGL();
     void paintGL();
     void resizeGL(int w, int h);
     void keyPressEvent ( QKeyEvent * event );
     void mousePressEvent( QMouseEvent *e );


signals:

public slots:

};

#endif // QROBOT_H
