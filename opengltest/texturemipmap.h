#ifndef TEXTUREMIPMAP_H
#define TEXTUREMIPMAP_H

#include <QGLWidget>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>

class texturemipmap : public QGLWidget
{
    Q_OBJECT
public:
    texturemipmap(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent( QMouseEvent *e );

    void makeImages(void);

signals:

public slots:

};

#endif // TEXTUREMIPMAP_H
