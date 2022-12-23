#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include <QPointF>
#include <QDebug>
#include <QProcess>
#include <QString>
#include "QMessageBox"
#include<cstring>

#include "sculptor.h"
#include "putvoxel.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "putbox.h"

#include "cutvoxel.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
#include "cutbox.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent){
    sculptorDimensionX = sculptorDimensionY = sculptorDimensionZ = 10;
    sculptor = new Sculptor(sculptorDimensionX, sculptorDimensionY, sculptorDimensionZ);
    method = dim = x = y = z = rad = r = ry = rx = rz = g = b = 0;
    a = 255;
    plan = XY;
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter pa(this);
    QPen pen;
    QBrush brush;
    pen.setColor(QColor(0,0,0,70));
    pen.setWidth(1);
    pa.setPen(pen);
    brush.setColor(QColor(255,255,255,255));
    brush.setStyle(Qt::SolidPattern);
    pa.setBrush(brush);
    p.clear();
    p = sculptor -> readMx(dim,plan);
    int dim1 = width()/p[0].size();
    int dim2 = height()/p.size();
    (dim1 >= dim2) ? square=dim2 : square=dim1;
    w = dim1;
    h = dim2;
    for(unsigned int i =0; i<p.size(); i++){
       for(unsigned int j =0; j<p[0].size(); j++){
            QRectF rectangle(i*square,j*square,square, square);
            pa.drawRoundedRect(rectangle, 3.0, 3.0);
        }
    }

    for(unsigned int i=0; i<p.size();i++){
        for(unsigned int j=0; j<p[0].size();j++){
            if(p[i][j].isOn){
                brush.setColor(QColor(p[i][j].r,p[i][j].g,p[i][j].b,p[i][j].a));
                brush.setStyle(Qt::SolidPattern);
                pa.setBrush(brush);
                QRectF rectangle(i*square,j*square,square, square);
                pa.drawRoundedRect(rectangle, 3.0, 3.0);
            }
       }
    }
}


void Plotter::mouseReleaseEvent(QMouseEvent *event){
    if(!(event->button() == Qt::LeftButton)){
        press = false;
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event) {
    if(!press){ return; }
    mouseEvents(event);
}

void Plotter::mousePressEvent(QMouseEvent *event){
    if(event->button() != Qt::LeftButton){ return; }
    mouseEvents(event);
}

void Plotter::changeRed(int red) { r = red; }
void Plotter::changeGreen(int green) { g = green; }
void Plotter::changeBlue(int blue) { b = blue; }
void Plotter::changeAlpha(int alpha) { a = alpha; }

void Plotter::changeDimx(int size) { x = size; }
void Plotter::changeDimy(int size) { y = size; }
void Plotter::changeDimz(int size) { z = size; }

void Plotter::changeRad(int rd) { rad=rd; }

void Plotter::changeRx(int radx) { rx=radx; }
void Plotter::changeRy(int rady) { ry=rady; }
void Plotter::changeRz(int radz) { rz=radz; }

void Plotter::changeSlice(int pln) { dim = pln; repaint(); }

void Plotter::shape(int method){
    float red = (float)(r/255.0);
    float green = (float)(g/255.0);
    float blue = (float)(b/255.0);
    float alpha = (float)(a/255.0);

    switch(method) {
        case PVoxel:
          (new putVoxel(px, py, pz, red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CVoxel:
          (new CutVoxel(px, py, pz)) -> draw(*sculptor);
          break;
        case PBox:
          (new putBox(px,(px+x),py,(py+y),pz,(pz+z), red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CBox:
          (new cutBox(px,(px+x),py,(py+y),pz,(pz+z))) -> draw(*sculptor);
          break;
        case PSphere:
          (new putSphere(px, py, pz, rad, red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CSphere:
          (new cutSphere(px, py, pz, rad)) -> draw(*sculptor);
          break;
        case PEllipsoid:
          (new putEllipsoid(px, py, pz, rx, ry, rz, red, green, blue, alpha)) -> draw(*sculptor);
          break;
        case CEllipsoid:
          (new cutEllipsoid(px, py, pz, rx, ry, rz)) -> draw(*sculptor);
        break;
    }
    repaint();
}

void Plotter::Off(QString file){
    std::string txt = file.toStdString() + ".OFF";
    this -> sculptor -> writeOFF(txt);
    QMessageBox box;
    QString msg;
    msg = "Arquivo OFF criado com sucesso !";
    box.setText(msg);
    box.exec();
}

void Plotter::mouseEvents(QMouseEvent *event){
    press = true;

    emit clickX(event->pos().x());
    emit clickY(event->pos().y());

    mx = (event->pos().x())/square;
    my = (event->pos().y())/square;

    emit moveX(mx);
    emit moveY(my);

    switch(plan) {
      case XY:
        px = mx; py = my; pz = dim;
        break;
      case YZ:
        px = dim; py = mx; pz = my;
        break;
       case ZX:
        px = my; py = dim; pz = mx;
        break;
    }
    Plotter::shape(method);
}
