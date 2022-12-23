#ifndef PUTBOX_H
#define PUTBOX_H

#include "sculptor.h"
#include "figurageometrica.h"

class putBox : public FiguraGeometrica
{
public:
    float r, g, b, a;
    int x0, x1, y0, y1, z0, z1;
    putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~putBox();
    void draw(Sculptor &s);
};

#endif // PUTBOX_H
