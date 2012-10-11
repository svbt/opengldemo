#ifndef QCLIP_H
#define QCLIP_H

#include <QGLWidget>
#include <QMouseEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

class qclip : public QGLWidget
{
    Q_OBJECT

public:
    qclip(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent( QMouseEvent *e );

signals:

public slots:

};

#endif // QCLIP_H
