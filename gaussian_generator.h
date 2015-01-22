#include "XUI_macros.hh"

#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H


// FAST PRIMITIVE GAUSS GENERATOR
class GenG {
  double twopi;
  int m;
  double invm;
  int t;
  double x1, x2;
public:
  GenG(int seed) {
    twopi = 6.283185307;
    m = (1<<30)-1;
    invm = 1.0/m;
    srand(seed);
    t=0;
  }
  double nxtGauss() {
    if (t==0) {
      x1 = (rand() % m) * invm;
      x2 = (rand() % m) * invm;
      t=1;
      return sqrt(-2*log(x1)) * cos(twopi * x2);
    } else {
      t=0;
      return sqrt(-2*log(x1)) * sin(twopi * x2);
    }

    //speed this up by factor 2
  }
};


#endif //GAUSSIAN_GENERATOR_H
