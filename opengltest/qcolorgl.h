#ifndef QCOLORGL_H
#define QCOLORGL_H

#include <QGLWidget>

#include <GL/gl.h>
#include <glut.h>

class qcolorgl : public QGLWidget
{
    Q_OBJECT

public:
    qcolorgl(QWidget *parent = 0);
    void triangle();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:

};

#endif // QCOLORGL_H
