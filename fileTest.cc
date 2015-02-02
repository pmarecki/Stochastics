#include "XUI_macros.hh"
#include "gaussian_generator.h"

/**
* Goal: 2 functions (save 800MB gaussians; load 800MB gaussians) + main with info how to call them.
*/


int SZ = 100;
const char* cacheFileName="/home/tttuuu/ramdrive/test.dat";

void createFile() {
  FILE* ff; ff = fopen(cacheFileName,"wb");
  double* dane = new double[SZ];
  REP(i, SZ) dane[i] = i;
  fwrite(dane, 8, SZ, ff);
  fclose(ff);
  delete[] dane;
}

void readFile() {
  FILE* ff; ff=fopen(cacheFileName,"rb");
  double* dane = new double[SZ];
  fread(dane, 8, SZ, ff);
  fclose(ff);
  REP(i,20) printf("%f\n", dane[i]);
  delete dane;
}

int main() {
  createFile();
  readFile();
}
