#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "sculptor.h"
#include "figurageometrica.h"

class putEllipsoid : public FiguraGeometrica
{
public:
    float r, g, b, a;
    int xcenter; int ycenter; int zcenter; int rx; int ry; int rz;
    putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
