#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>

#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


class tictactoe : public QGLWidget
{
    Q_OBJECT
public:
    tictactoe(QWidget *parent = 0);
    void init_game();
    int check_move();
    int blocking_win();
    int check_corner();
    int check_row();
    int computer_move();
    void Sprint( int x, int y, char *st);
    void Draw_O(int x, int y, int z, int a);
    void Draw_X(int x, int y, int z, int a);

public:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void keyPressEvent ( QKeyEvent * event );
    void mouseReleaseEvent( QMouseEvent* event );
signals:

public slots:

};

#endif // TICTACTOE_H
