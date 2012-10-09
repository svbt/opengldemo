#ifndef TEXTUREMAP_H
#define TEXTUREMAP_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>



class texturemap : public QGLWidget
{
    Q_OBJECT
public:
    texturemap(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void makeCheckImage(void);

signals:

public slots:

};

#endif // TEXTUREMAP_H
