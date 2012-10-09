#ifndef QDISPLAYLIST_H
#define QDISPLAYLIST_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>

class qdisplaylist : public QGLWidget
{
    Q_OBJECT
public:
    qdisplaylist(QWidget *parent = 0);
    void drawLine();

public:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

signals:

public slots:

};

#endif // QDISPLAYLIST_H
