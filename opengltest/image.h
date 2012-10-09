#ifndef IMAGE_H
#define IMAGE_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <QKeyEvent>
#include <QMouseEvent>


class image : public QGLWidget
{
    Q_OBJECT
public:
    image(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );
    //void mouseMoveEvent( QMouseEvent *e );

    void makeCheckImage();

signals:

public slots:

};

#endif // IMAGE_H
