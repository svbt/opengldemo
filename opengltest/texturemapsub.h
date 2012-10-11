#ifndef TEXTUREMAPSUB_H
#define TEXTUREMAPSUB_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>

class texturemapsub : public QGLWidget
{
    Q_OBJECT
public:
    texturemapsub(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );
    void makeCheckImage(void);
    void mousePressEvent( QMouseEvent *e );

signals:

public slots:

};

#endif // TEXTUREMAPSUB_H
