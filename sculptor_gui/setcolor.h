#ifndef SETCOLOR_H
#define SETCOLOR_H

#include <QWidget>


class setColor : public QWidget
{
    Q_OBJECT

private:
    int r;
    int g;
    int b;
    int a;
public:
    explicit setColor(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    setColor();
signals:

public slots:
    void set_r(int r_);
    void set_g(int g_);
    void set_b(int b_);
    void set_a(int a_);
};

#endif // SETCOLOR_H
