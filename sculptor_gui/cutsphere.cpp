#include "cutsphere.h"
#include "math.h"

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;
}

void cutSphere::draw(Sculptor &s){
    for(int k =0; k<zcenter+radius; k++){
        for(int j =0; j<ycenter+radius; j++){
            for(int i =0; i<xcenter+radius; i++){
                if(pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)<pow(radius,2)){
                    s.cutVoxel(i,j,k);
                };
            }
        }
    }
}
