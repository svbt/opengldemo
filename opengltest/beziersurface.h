#ifndef BEZIERSURFACE_H
#define BEZIERSURFACE_H

#include <QGLWidget>
#include <QMouseEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <glut.h>

class beziersurface : public QGLWidget
{
    Q_OBJECT
public:
    beziersurface(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent( QMouseEvent *e );
signals:

public slots:

};

#endif // BEZIERSURFACE_H
