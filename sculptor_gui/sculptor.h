#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <fstream>

#include "vector"
#include "Voxel.h"

  enum{XY,YZ,ZX};

class Sculptor
{
private:
    Voxel ***v;
    int nx, ny, nz;
    float r, g, b, a;
public:
    Sculptor(int _nx, int _ny, int _nz); // default constructor of a vector
    ~Sculptor(); // destructor
    void setColor(float r, float g, float b, float a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(std::string filename);
    std::vector<std::vector<Voxel >> readMx(int dimension = 0, int plan = XY);

};

#endif // SCULPTOR_H
