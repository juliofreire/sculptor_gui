#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class cutEllipsoid : public FiguraGeometrica
{
public:
    int xcenter; int ycenter; int zcenter; int rx; int ry; int rz;
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void draw(Sculptor &s);

};

#endif // CUTELLIPSOID_H
