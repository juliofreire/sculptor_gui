#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "sculptor.h"
#include "figurageometrica.h"

class putVoxel : public FiguraGeometrica
{
public:
    int x, y, z;
    float r, g, b, a;
    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~putVoxel();
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
