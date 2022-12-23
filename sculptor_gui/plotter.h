#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QString>
#include "sculptor.h"
#include "vector"
#include <iostream>
#include <cstring>

enum{PVoxel, CVoxel, PBox, CBox, PSphere, CSphere, PEllipsoid, CEllipsoid};


class Plotter : public QWidget
{
    Q_OBJECT
private:
    void mouseEvents(QMouseEvent *event);

public:
    explicit Plotter(QWidget *parent = nullptr);
        void paintEvent(QPaintEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void shape(int sh);
        Sculptor *sculptor;
        int method;
        int dim;
        int plan;
        int sculptorDimensionX;
        int sculptorDimensionY;
        int sculptorDimensionZ;
        int r;
        int g;
        int b;
        int a;
        int rad;
        int rx;
        int ry;
        int rz;
        int x;
        int y;
        int z;
        int h;
        int w;
    private:
        std::vector<std::vector<Voxel>> p;
        QColor lineColor;
        int cor;
        QAction *actionMudaCor;
        int cube;
        int square;
        int px, py, pz;
        bool press;
        int mx, my;
    signals:
        void moveX(int);
        void moveY(int);
        void clickX(int);
        void clickY(int);
        void planeChosen(int);
    public slots:
        void changeDimx(int size);
        void changeDimy(int size);
        void changeDimz(int size);
        void changeRad(int rd);
        void changeRx(int radx);
        void changeRy(int rady);
        void changeRz(int radz);
        void changeRed(int red);
        void changeGreen(int green);
        void changeBlue(int blue);
        void changeAlpha(int alpha);
        void changeSlice(int pln);
        void Off(QString s);
public slots:

signals:

};

#endif // PLOTTER_H
