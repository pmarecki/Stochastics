#include "XUI_macros.hh"
#include "gaussian_generator.h"

/**
* Goal: 2 functions (save 800MB gaussians; load 800MB gaussians) + main with info how to call them.
*/


int SZ = 100000000;
const char* cacheFileName="/home/tttuuu/ramdrive/randomDoubles.dat";

void createFile() {
  FILE* ff; ff = fopen(cacheFileName,"wb");
  double* dane = new double[SZ];
  //generate SZ normal doubles[0,1] here
  mt19937 genrator(123);  //needs the seed
  normal_distribution<double> normal(0,1);  //wrapper
  REP(i, SZ) dane[i] = normal(genrator);
  fwrite(dane, 8, SZ, ff);
  fclose(ff);
  delete[] dane;
}

double* readFile(int nNormals) {
  FILE* ff; ff=fopen(cacheFileName,"rb");
  double* dane = new double[nNormals];
  fread(dane, 8, nNormals, ff);
  fclose(ff);
  REP(i,20) printf("%f\n", dane[i]);
  return dane;
}

int main() {
//  createFile();
  double* normals = readFile(3e6);
  delete normals;
}
