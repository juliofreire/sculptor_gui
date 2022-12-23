#include "cutellipsoid.h"
#include "math.h"

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> rx = rx;
    this -> ry = ry;
    this -> rz = rz;
}

void cutEllipsoid::draw(Sculptor &s){
    for(int k =0; k<zcenter+rz; k++){
        for(int j =0; j<ycenter+ry; j++){
            for(int i =0; i<xcenter+rx; i++){
                if( (pow(i-xcenter,2)/pow(rx,2)) + (pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) < 1){
                    s.cutVoxel(i,j,k);
                };
            }
        }
    }
}
