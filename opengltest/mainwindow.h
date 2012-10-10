#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTimer>

#include "qlinestipple.h"
#include "qlight.h"
#include "qclip.h"
#include "qfog.h"
#include "qcolorgl.h"
#include "qplanet.h"
#include "qrobot.h"
#include "qblending.h"
#include "qblending3d.h"
#include "qantialias.h"
#include "qfog.h"
#include "qtorus.h"
#include "qstroke.h"
#include "qfontbitmap.h"
#include "texturemap.h"
#include "texturemapsub.h"
#include "texturemipmap.h"
#include "texturegeneration.h"
#include "stencilbuffertest.h"
#include "beziercurve.h"
#include "beziersurface.h"
#include "beziermesh.h"
#include "beziertexturesurface.h"
#define MAX_TIMER 25

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QTimer timer[MAX_TIMER];
private:
    qlinestipple *_gw;
    qlight *_qlight;
    qclip *_qclip;
    qcolorgl *_glqcolor;
    qplanet * _qplanet;
    qrobot * _qrobot;
    qblending * _qblending;
    qblending3d * _qblending3d;
    qantialias * _qantialias;
    qfog * _qfog;
    qtorus * _qtorus;
    qstroke * _qstroke;
    qfontbitmap * _qfontbitmap;
    texturemap * _texturemap;
    texturemapsub * _texturemapsub;
    texturemipmap * _texturemipmap;
    texturegeneration * _texturegeneration;
    stencilbuffertest * _stencilbuffertest;
    beziercurve * _beziercurve;
    beziersurface * _beziersurface;
    beziermesh * _beziermesh;
    beziertexturesurface * _beziertexturesurface;
public slots:
    void exitGlWidget();
    void exitQLight();
    void exitQClip();
    void exitQColor();
    void exitQPlanet();
    void exitQRobot();
    void exitQBlending();
    void exitQBlending3d();
    void exitAntialias();
    void exitqFog();
    void exitqTorus();
    void exitqstroke();
    void exitqfontbitmap();
    void exittexturemap();
    void exittexturemapsub();
    void exittexturemipmap();
    void exittexturegeneration();
    void exitstencilbuffertest();
    void exitbeziercurve();
    void exitbeziersurface();
    void exitbeziermesh();
    void exitbeziertexturesurface();
};

#endif // MAINWINDOW_H
