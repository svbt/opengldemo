#ifndef TEXTUREBIND_H
#define TEXTUREBIND_H

#include <QGLWidget>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>

class texturebind : public QGLWidget
{
    Q_OBJECT
public:
    texturebind(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent( QMouseEvent *e );

    void makeCheckImages(void);
signals:

public slots:

};

#endif // TEXTUREBIND_H
