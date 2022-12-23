#include "setcolor.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>


setColor::setColor()
{

}

setColor::setColor(QWidget *parent) : QWidget(parent){
    r = 0;
    g = 0;
    b = 0;
    a = 255;
}

void setColor::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(r, g, b, a));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0, 255));
    pen.setWidth(3);

    painter.setBrush(brush);
    painter.setPen(pen);

    QRectF rectangle(0,0,width(), height());
    painter.drawRoundedRect(rectangle, 10.0, 10.0);
}

void setColor::set_r(int r_){
    r = r_;
    repaint();
}
void setColor::set_g(int g_) {
    g = g_;
    repaint();
}
void setColor::set_b(int b_) {
    b = b_;
    repaint();
}
void setColor::set_a(int a_) {
    a = a_;
    repaint();
}
