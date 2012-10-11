#ifndef QSTROKE_H
#define QSTROKE_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <stdlib.h>
#include <string.h>

#define PT 1
#define STROKE 2
#define END 3

typedef struct charpoint {
GLfloat x, y;
int type;
} CP;

class qstroke : public QGLWidget
{
    Q_OBJECT
public:
    qstroke(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );
    void mousePressEvent( QMouseEvent *e );

    void printStrokedString(char *s);
    void drawLetter(CP *l);
signals:

public slots:

};

#endif // QSTROKE_H
