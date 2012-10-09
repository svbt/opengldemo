#ifndef TEXTUREGENERATION_H
#define TEXTUREGENERATION_H

#include <QGLWidget>
#include <QKeyEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>

class texturegeneration : public QGLWidget
{
    Q_OBJECT
public:
    texturegeneration(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );

    void makeStripeImage(void);

signals:

public slots:

};

#endif // TEXTUREGENERATION_H
