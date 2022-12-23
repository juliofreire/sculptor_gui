#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include "sculptor.h"
#include "plotter.h"
#include "QMessageBox"
#include "QProcess"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->horizontalSliderBoxX->setMaximum(ui->plotter->sculptorDimensionX - 1);
    ui->horizontalSliderBoxY->setMaximum(ui->plotter->sculptorDimensionY-1);
    ui->horizontalSliderBoxZ->setMaximum(ui->plotter->sculptorDimensionZ-1);
    ui->horizontalSliderRaioEsfera->setMaximum(ui->plotter->sculptorDimensionX/2 -1);
    ui->horizontalSliderElipRx->setMaximum(ui->plotter->sculptorDimensionX/2 -1);
    ui->horizontalSliderElipRy->setMaximum(ui->plotter->sculptorDimensionY/2 -1);
    ui->horizontalSliderElipRz->setMaximum(ui->plotter->sculptorDimensionZ/2 -1);
    ui->horizontalSliderPlanoSpec->setMaximum(ui->plotter->sculptorDimensionZ -1);
    ui->spinBoxAlpha->setValue(255);
    ui->horizontalSliderDimX->setValue(ui->plotter->sculptorDimensionX);
    ui->horizontalSliderDimY->setValue(ui->plotter->sculptorDimensionY);
    ui->horizontalSliderDimZ->setValue(ui->plotter->sculptorDimensionZ);
    ui->pushButtonXY->setChecked(true);

    connect(ui->horizontalSliderPlanoSpec, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeSlice(int)));
    connect(ui->radioButtonPutVoxel, SIGNAL(clicked(bool)), this, SLOT(pVoxel()));
    connect(ui->radioButtonCutVoxel, SIGNAL(clicked(bool)), this, SLOT(cVoxel()));
    connect(ui->radioButtonPutBox, SIGNAL(clicked(bool)), this, SLOT(pBox()));
    connect(ui->radioButtonCutBox, SIGNAL(clicked(bool)), this, SLOT(cBox()));
    connect(ui->radioButtonPutSphere, SIGNAL(clicked(bool)), this, SLOT(pShpere()));
    connect(ui->radioButtonCutSphere, SIGNAL(clicked(bool)), this, SLOT(cShpere()));
    connect(ui->radioButtonPutEllipsoid, SIGNAL(clicked(bool)), this, SLOT(pEllip()));
    connect(ui->radioButtonCutEllipsoid, SIGNAL(clicked(bool)), this, SLOT(cEllip()));
    connect(ui->horizontalSliderRed, SIGNAL(valueChanged(int)), this, SLOT(changeRed(int)));
    connect(ui->horizontalSliderBlue, SIGNAL(valueChanged(int)), this, SLOT(changeBlue(int)));
    connect(ui->horizontalSliderGreen, SIGNAL(valueChanged(int)), this, SLOT(changeGreen(int)));
    connect(ui->horizontalSliderAlpha, SIGNAL(valueChanged(int)), this, SLOT(changeAlpha(int)));
    connect(ui->horizontalSliderBoxX, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeDimx(int)));
    connect(ui->horizontalSliderBoxY, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeDimy(int)));
    connect(ui->horizontalSliderBoxZ, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeDimz(int)));
    connect(ui->horizontalSliderRaioEsfera, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeRad(int)));
    connect(ui->horizontalSliderElipRx, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeRx(int)));
    connect(ui->horizontalSliderElipRy, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeRy(int)));
    connect(ui->horizontalSliderElipRz, SIGNAL(valueChanged(int)), ui->plotter, SLOT(changeRz(int)));
    connect(ui->pushButtonXY,SIGNAL(clicked(bool)),this,SLOT(changeXY()));
    connect(ui->pushButtonYZ, SIGNAL(clicked(bool)), this, SLOT(changeYZ()));
    connect(ui->pushButtonXZ, SIGNAL(clicked(bool)), this, SLOT(changeZX()));
    connect(ui->pushButtonCanvas, SIGNAL(clicked(bool)), this, SLOT(selectPlane()));
    connect(ui->pushButtonGeomview, SIGNAL(clicked(bool)), this, SLOT(geomview()));
    connect(ui->pushButtonMeshlab, SIGNAL(clicked(bool)), this, SLOT(meshlab()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::selectPlane(){
    ui->plotter->sculptorDimensionX = ui->horizontalSliderDimX->value();
    ui->plotter->sculptorDimensionY = ui->horizontalSliderDimY->value();
    ui->plotter->sculptorDimensionZ = ui->horizontalSliderDimZ->value();
    ui->plotter->sculptor->~Sculptor();
    ui->plotter->sculptor = new Sculptor(ui->plotter->sculptorDimensionX,ui->plotter->sculptorDimensionY,ui->plotter->sculptorDimensionZ);
    ui->horizontalSliderBoxX->setMaximum(ui->plotter->sculptorDimensionX-1);
    ui->horizontalSliderBoxY->setMaximum(ui->plotter->sculptorDimensionY-1);
    ui->horizontalSliderBoxZ->setMaximum(ui->plotter->sculptorDimensionZ-1);
    ui->horizontalSliderRaioEsfera->setMaximum(ui->plotter->sculptorDimensionX/2 -1);
    ui->horizontalSliderElipRx->setMaximum(ui->plotter->sculptorDimensionX/2 -1);
    ui->horizontalSliderElipRy->setMaximum(ui->plotter->sculptorDimensionY/2 -1);
    ui->horizontalSliderElipRz->setMaximum(ui->plotter->sculptorDimensionZ/2 -1);
    ui->horizontalSliderPlanoSpec->setMaximum(ui->plotter->sculptorDimensionZ -1);
    ui->plotter->repaint();
}

void MainWindow::changeXY(){
    ui -> plotter -> plan = XY;
    emit ui -> plotter -> planeChosen(XY);
    ui -> plotter -> dim = ui -> plotter -> sculptorDimensionZ/2;
    ui -> horizontalSliderPlanoSpec -> setMaximum(ui -> plotter -> sculptorDimensionZ -1);
    ui -> plotter -> repaint();
}

void MainWindow::changeYZ(){
    ui -> plotter -> plan = YZ;
    emit ui -> plotter->planeChosen(YZ);
    ui -> plotter -> dim = ui -> plotter -> sculptorDimensionX/2;
    ui -> horizontalSliderPlanoSpec -> setMaximum(ui -> plotter -> sculptorDimensionX -1);
    ui -> plotter -> repaint();
}

void MainWindow::changeZX(){
    ui -> plotter -> plan
            = ZX;
    emit ui -> plotter -> planeChosen(ZX);
    ui -> plotter -> dim = ui -> plotter -> sculptorDimensionY/2;
    ui -> horizontalSliderPlanoSpec -> setMaximum(ui -> plotter -> sculptorDimensionY -1);
    ui -> plotter -> repaint();
}

void MainWindow::changeRed(int red){
    ui -> plotter -> changeRed(red);
    ui -> CurrentColor -> set_r(red);
}

void MainWindow::changeBlue(int blue){
    ui -> plotter -> changeBlue(blue);
    ui -> CurrentColor -> set_b(blue);
}

void MainWindow::changeGreen(int green){
    ui -> plotter -> changeGreen(green);
    ui -> CurrentColor -> set_g(green);
}

void MainWindow::changeAlpha(int alpha){
    ui -> plotter -> changeAlpha(alpha);
    ui -> CurrentColor -> set_a(alpha);
}

void MainWindow::pVoxel()  { ui -> plotter -> method = PVoxel; }
void MainWindow::cVoxel()  { ui -> plotter -> method = CVoxel; }
void MainWindow::pBox()    { ui -> plotter -> method = PBox; }
void MainWindow::cBox()    { ui -> plotter -> method = CBox; }
void MainWindow::pShpere() { ui -> plotter -> method = PSphere; }
void MainWindow::cShpere() { ui -> plotter -> method = CSphere; }
void MainWindow::pEllip()  { ui -> plotter -> method = PEllipsoid; }
void MainWindow::cEllip()  { ui -> plotter -> method = CEllipsoid; }

void MainWindow::geomview() {
    QProcess process;
    process.start("geomview", QStringList() << ui->lineEditOFF->text() +".OFF");
    process.waitForFinished();
}

void MainWindow::meshlab(){
    QProcess process;
    process.start("meshlab", QStringList() << ui->lineEditOFF->text() + ".OFF");
    process.waitForFinished();
}

void MainWindow::criarOFF(){ ui->plotter->Off(ui->lineEditOFF->text()); }
void MainWindow::quit() { exit(0);}
