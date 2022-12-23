#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector"
#include "sculptor.h"
#include "plotter.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void selectPlane();
    void changeRed(int);
    void changeBlue(int);
    void changeGreen(int);
    void changeAlpha(int);
    void changeXY();
    void changeYZ();
    void changeZX();
    void pVoxel();
    void cVoxel();
    void pBox();
    void cBox();
    void pShpere();
    void cShpere();
    void pEllip();
    void cEllip();
    void geomview();
    void meshlab();

private slots:
    void quit();
    void criarOFF();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};
#endif // MAINWINDOW_H
