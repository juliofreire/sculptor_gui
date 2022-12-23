#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "sculptor.h"
#include "figurageometrica.h"

class putSphere : public FiguraGeometrica
{
public:
    float r, g, b, a;
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
