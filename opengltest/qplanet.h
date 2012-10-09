#ifndef QPLANET_H
#define QPLANET_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <QKeyEvent>



class qplanet : public QGLWidget
{
    Q_OBJECT
private:
    int year, day;
public:
    qplanet(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent(QKeyEvent * event);

signals:

public slots:

};

#endif // QPLANET_H
