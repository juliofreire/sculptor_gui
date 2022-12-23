#include "putsphere.h"
#include "math.h"

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;

    this ->r = r;
    this ->g = g;
    this ->b = b;
    this ->a = a;

}

void putSphere::draw(Sculptor &s){
    s.setColor(r, g, b, a);
    for(int k =0; k<zcenter+radius; k++){
        for(int j =0; j<ycenter+radius; j++){
            for(int i =0; i<xcenter+radius; i++){
                if(pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)<pow(radius,2)){
                    s.putVoxel(i,j,k);
                };
            }
        }
    }
}
