#ifndef BEZIERMESH_H
#define BEZIERMESH_H

#include <QGLWidget>
#include <QMouseEvent>
class beziermesh : public QGLWidget
{
    Q_OBJECT
public:
    beziermesh(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent( QMouseEvent *e );

    void initlights();

signals:

public slots:

};

#endif // BEZIERMESH_H
