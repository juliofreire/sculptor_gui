#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "sculptor.h"
#include "Voxel.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    // uving 'new' to allocate the povition of matrix elementv

    v = new Voxel**[nz];
    v[0] = new Voxel*[ny*nz];
    v[0][0] = new Voxel[nx*ny*nz];


    // running into the matrix to vtore the addrevv of elementv

    for (int k=1;k<nz;k++){
        v[k] = v[k-1]+ny;
    }

    for (int k=0;k<nz;k++){
        for (int j=0;j<ny;j++){
            if ((k==0 && j==0)){
            v[k][1] = v[k][0]+nx;
            }
            else v[k][j] = v[k][j-1]+nx;
        }
    }

    for(int k =0; k<nz; k++){
        for(int j =0; j<ny; j++){
            for(int i =0; i<nx; i++){
                v[i][j][k].isOn = false;
            }
        }
    }
}
Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a){
    // define colors of my draw
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z){
    // just put voxel inside the sculptor shape
    if(x>=0 && y>=0 && z>=0 && x<nx && y <ny && z<nz){
    v[x][y][z].isOn = true;
    v[x][y][z].r= r;
    v[x][y][z].g= g;
    v[x][y][z].b= b;
    v[x][y][z].a= a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(std::string filename){
    std::ofstream myfile;
    fixed(myfile);

    myfile.open(filename);
    if(myfile.is_open() == false){
        std::cout << "File isn't open";
        exit(1);
    }

    // first line which define the OFF file
    myfile << "OFF" << std::endl;

    // counting vertices and faces of each voxel activated
    int countVertices=0;
    int countFaces=0;

    for(int k =0; k<nz; k++){
        for(int j =0; j<ny; j++){
            for(int i =0; i<nx; i++){
                if(v[i][j][k].isOn){
                    countVertices+=8;
                    countFaces+=6;
                }
            }
        }
    }

    // second line contains numberOfVertices numberOfFaces numberOfEdges
    // which the numberOfEdges doesnt matter, so its values is 0
    myfile << countVertices << " " << countFaces << " " << 0 << std::endl;


    // walking on all matrix and place vertices of each voxel
    // each element of matrix represent the center of a voxel with
    // width, lenght and height equals 1
    for(int k =0; k<nz; k++){
        for(int j =0; j<ny; j++){
            for(int i =0; i<nx; i++){
                if(v[i][j][k].isOn){
                    myfile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    myfile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    myfile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    myfile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    myfile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                    myfile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    myfile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    myfile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                }
            }
        }
    }

    // walking on all matrix selecting the vertices that represent each face
    // enumareting them in counterclockwise for the normal vector to point out
    // of the area by the right hand law.
    int numVoxel = 0;
    for(int k =0; k<nz; k++){
        for(int j =0; j<ny; j++){
            for(int i =0; i<nx; i++){
                if(v[i][j][k].isOn){
                    myfile << 4 << " " << 0+numVoxel << " " << 3+numVoxel << " " << 2+numVoxel << " " << 1+numVoxel << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    myfile << 4 << " " << 4+numVoxel << " " << 5+numVoxel << " " << 6+numVoxel << " " << 7+numVoxel << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    myfile << 4 << " " << 0+numVoxel << " " << 1+numVoxel << " " << 5+numVoxel << " " << 4+numVoxel << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    myfile << 4 << " " << 0+numVoxel << " " << 4+numVoxel << " " << 7+numVoxel << " " << 3+numVoxel << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    myfile << 4 << " " << 3+numVoxel << " " << 7+numVoxel << " " << 6+numVoxel << " " << 2+numVoxel << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    myfile << 4 << " " << 1+numVoxel << " " << 2+numVoxel << " " << 6+numVoxel << " " << 5+numVoxel << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    numVoxel += 8;
                }
            }
        }
    }

    if(myfile.is_open()){
        std::cout << "The file was saved with succesful!" << std::endl;
        myfile.close();
    }
}

std::vector<std::vector<Voxel>> Sculptor::readMx(int dimension, int plan){
    std::vector<std::vector<Voxel>> planVoxels;
    std::vector<Voxel> lineVoxels;

    switch(plan) {
      case XY:
        lineVoxels.resize(ny);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                Voxel *voxel = &v[i][j][dimension];
                lineVoxels[j].isOn = voxel -> isOn;
                lineVoxels[j].r = (int)(voxel -> r * 255.0);
                lineVoxels[j].g = (int)(voxel -> g * 255.0);
                lineVoxels[j].b = (int)(voxel -> b * 255.0);
                lineVoxels[j].a = (int)(voxel -> a * 255.0);
            }
            planVoxels.push_back(lineVoxels);
        }
        break;
      case YZ:
        lineVoxels.resize(nz);
        for(int i = 0; i<ny; i++){
            for(int j = 0; j<nz; j++){
                Voxel *voxel = &v[dimension][i][j];
                lineVoxels[j].isOn = voxel -> isOn;
                lineVoxels[j].r = (int)(voxel -> r * 255.0);
                lineVoxels[j].g = (int)(voxel -> g * 255.0);
                lineVoxels[j].b = (int)(voxel -> b * 255.0);
                lineVoxels[j].a = (int)(voxel -> a * 255.0);
            }
            planVoxels.push_back(lineVoxels);
        }
        break;
      case ZX:
        lineVoxels.resize(nx);
        for(int i = 0; i<nz; i++){
            for(int j = 0; j<nx; j++){
                Voxel *voxel = &v[j][dimension][i];
                lineVoxels[j].isOn = voxel -> isOn;
                lineVoxels[j].r = (int)(voxel -> r * 255.0);
                lineVoxels[j].g = (int)(voxel -> g * 255.0);
                lineVoxels[j].b = (int)(voxel -> b * 255.0);
                lineVoxels[j].a = (int)(voxel -> a * 255.0);
            }
            planVoxels.push_back(lineVoxels);
        }
      break;
    }
    lineVoxels.clear();
    return planVoxels;
}
