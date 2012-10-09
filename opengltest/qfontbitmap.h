#ifndef QFONTBITMAP_H
#define QFONTBITMAP_H

#include <QGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>
#include <string.h>

class qfontbitmap : public QGLWidget
{
    Q_OBJECT
public:
    qfontbitmap(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void makeRasterFont(void);
    void printString(char *s);
signals:

public slots:

};

#endif // QFONTBITMAP_H
