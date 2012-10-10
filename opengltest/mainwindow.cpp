#include "mainwindow.h"

#include <QtGui/QFormLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMaximumSize(500,500);
    this->setMinimumSize(500,500);

    _gw = new qlinestipple(this);
    connect(&timer[0], SIGNAL(timeout()), this, SLOT(exitGlWidget()));
    timer[0].start(1000);
}

void MainWindow::exitGlWidget()
{
    timer[0].stop();
    _gw->hide();

    _qlight = new qlight(this);
    _qlight->show();
    connect(&timer[1], SIGNAL(timeout()), this, SLOT(exitQLight()));
    timer[1].start(1000);
}

void MainWindow::exitQLight()
{
    timer[1].stop();
    _qlight->hide();

    _qclip = new qclip(this);
    _qclip->show();
    connect(&timer[2], SIGNAL(timeout()), this, SLOT(exitQClip()));
    timer[2].start(1000);
}

void MainWindow::exitQClip()
{
    timer[2].stop();
    _qclip->hide();

    _glqcolor = new qcolorgl(this);
    _glqcolor->show();
    connect(&timer[3], SIGNAL(timeout()), this, SLOT(exitQColor()));
    timer[3].start(1000);
}

void MainWindow::exitQColor()
{
    timer[3].stop();
    _glqcolor->hide();

    _qplanet = new qplanet(this);
    _qplanet->show();
    connect(&timer[4], SIGNAL(timeout()), this, SLOT(exitQPlanet()));
    timer[4].start(1000);

}

void MainWindow::exitQPlanet()
{
    timer[4].stop();
    _qplanet->hide();

    _qrobot = new qrobot(this);
    _qrobot->show();
    connect(&timer[5], SIGNAL(timeout()), this, SLOT(exitQRobot()));
    timer[5].start(1000);

}

void MainWindow::exitQRobot()
{
    timer[5].stop();
    _qrobot->hide();

    _qblending = new qblending(this);
    _qblending->show();
    connect(&timer[6], SIGNAL(timeout()), this, SLOT(exitQBlending()));
    timer[6].start(1000);
}

void MainWindow::exitQBlending()
{
    timer[6].stop();
    _qblending->hide();

    _qblending3d = new qblending3d(this);
    _qblending3d->show();
    connect(&timer[7], SIGNAL(timeout()), this, SLOT(exitQBlending3d()));
    timer[7].start(1000);
}

void MainWindow::exitQBlending3d()

{
    timer[7].stop();
    _qblending3d->hide();

    _qantialias = new qantialias(this);
    _qantialias->show();
    connect(&timer[8], SIGNAL(timeout()), this, SLOT(exitAntialias()));
    timer[8].start(1000);

}

void MainWindow::exitAntialias()
{
    timer[8].stop();
    _qantialias->hide();

    _qfog = new qfog(this);
    _qfog->show();
    connect(&timer[9], SIGNAL(timeout()), this, SLOT(exitqFog()));
    timer[9].start(1000);
}

void MainWindow::exitqFog()
{
    timer[9].stop();
    _qfog->hide();

    _qtorus = new qtorus(this);
    _qtorus->show();
    connect(&timer[10], SIGNAL(timeout()), this, SLOT(exitqTorus()));
    timer[10].start(1000);
}

void MainWindow::exitqTorus()
{
    timer[10].stop();
    _qtorus->hide();

    _qstroke = new qstroke(this);
    _qstroke->show();
    connect(&timer[11], SIGNAL(timeout()), this, SLOT(exitqstroke()));
    timer[11].start(1000);

}

void MainWindow::exitqstroke()
{
    timer[11].stop();
    _qstroke->hide();

    _qfontbitmap= new qfontbitmap(this);
    _qfontbitmap->show();
    connect(&timer[12], SIGNAL(timeout()), this, SLOT(exitqfontbitmap()));
    timer[12].start(1000);
}

void MainWindow::exitqfontbitmap()
{
    timer[12].stop();
    _qfontbitmap->hide();

    _texturemap = new texturemap(this);
    _texturemap->show();
    connect(&timer[13], SIGNAL(timeout()), this, SLOT( exittexturemap()));
    timer[13].start(1000);
}

void MainWindow::exittexturemap()
{
    timer[13].stop();
    _texturemap->hide();

    _texturemapsub = new texturemapsub(this);
    _texturemapsub->show();
    connect(&timer[14], SIGNAL(timeout()), this, SLOT( exittexturemapsub()));
    timer[14].start(1000);
}

void MainWindow::exittexturemapsub()
{
    timer[14].stop();
    _texturemapsub->hide();

    _texturemipmap = new texturemipmap(this);
    _texturemipmap->show();
    connect(&timer[15], SIGNAL(timeout()), this, SLOT( exittexturemipmap()));
    timer[15].start(1000);

}

void MainWindow::exittexturemipmap()
{
    timer[15].stop();
    _texturemipmap->hide();

    _texturegeneration = new texturegeneration(this);
    _texturegeneration->show();
    connect(&timer[16], SIGNAL(timeout()), this, SLOT( exittexturegeneration()));
    timer[16].start(1000);
}

void MainWindow::exittexturegeneration()
{
    timer[16].stop();
    _texturegeneration->hide();

    _stencilbuffertest = new stencilbuffertest(this);
    _stencilbuffertest->show();
    connect(&timer[17], SIGNAL(timeout()), this, SLOT( exitstencilbuffertest()));
    timer[17].start(1000);
}

void MainWindow::exitstencilbuffertest()
{
    timer[17].stop();
    _stencilbuffertest->hide();

    _beziercurve = new beziercurve(this);
    _beziercurve->show();
    connect(&timer[18], SIGNAL(timeout()), this, SLOT( exitbeziercurve()));
    timer[18].start(1000);

}

void MainWindow::exitbeziercurve()
{
  timer[18].stop();
  _beziercurve->hide();

  _beziersurface = new beziersurface(this);
  _beziersurface->show();
  connect(&timer[19], SIGNAL(timeout()), this, SLOT( exitbeziersurface()));
  timer[19].start(1000);
}

void MainWindow::exitbeziersurface()
{
    timer[19].stop();
    _beziersurface->hide();

    _beziermesh = new beziermesh(this);
    _beziermesh->show();
    connect(&timer[20], SIGNAL(timeout()), this, SLOT( exitbeziermesh()));
    timer[20].start(1000);
}

void MainWindow::exitbeziermesh()
{
    timer[20].stop();
    _beziermesh->hide();

    _beziertexturesurface = new beziertexturesurface(this);
    _beziertexturesurface->show();
    connect(&timer[21], SIGNAL(timeout()), this, SLOT( exitbeziertexturesurface()));
    timer[21].start(1000);
}

void MainWindow::exitbeziertexturesurface()
{
    timer[21].stop();
    _beziertexturesurface->hide();
}

MainWindow::~MainWindow()
{

}
