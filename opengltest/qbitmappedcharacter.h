#ifndef QBITMAPPEDCHARACTER_H
#define QBITMAPPEDCHARACTER_H

#include <QGLWidget>
#include <QMouseEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>

class qbitmappedcharacter : public QGLWidget
{
    Q_OBJECT
public:
    qbitmappedcharacter(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent( QMouseEvent *e );

signals:

public slots:

};

#endif // QBITMAPPEDCHARACTER_H
