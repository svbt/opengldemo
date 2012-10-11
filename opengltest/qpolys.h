#ifndef QPOLYS_H
#define QPOLYS_H

#include <QGLWidget>
#include <QMouseEvent>
#include <GL/gl.h>
#include <glut.h>

class qpolys : public QGLWidget
{
    Q_OBJECT
public:
    qpolys();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent( QMouseEvent *e );


signals:

public slots:

};

#endif // QPOLYS_H
