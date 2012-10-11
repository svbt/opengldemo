#ifndef QBLENDING_H
#define QBLENDING_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>

class qblending : public QGLWidget
{
    Q_OBJECT

private:
    int leftFirst;
public:
    qblending(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );
    void mousePressEvent( QMouseEvent *e );

    void drawRightTriangle();
    void drawLeftTriangle();

signals:

public slots:

};

#endif // QBLENDING_H
