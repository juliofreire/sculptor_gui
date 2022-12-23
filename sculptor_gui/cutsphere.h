#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class cutSphere : public FiguraGeometrica
{
public:
    int xcenter, ycenter, zcenter, radius;
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &s);

};

#endif // CUTSPHERE_H
