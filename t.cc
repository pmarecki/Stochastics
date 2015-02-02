//#include <bits/stdc++.h>
//#define REP(i,n)  for(int i=0;i<(int)(n);++i)
//#define FOR(i,b,n)  for(int i=b;i<(n);++i)
//#define ALL(c) (c).begin(),(c).end()
//#define SS size()
//#define CLR(a,v) memset((a),(v), sizeof a)
//#define ST first
//#define ND second
//template<typename T, typename U> inline void AMIN(T &x, U y) { if(y < x) x = y; }
//template<typename T, typename U> inline void AMAX(T &x, U y) { if(x < y) x = y; }
//using namespace std;
//typedef long long ll;
//typedef vector<int> vi;
//typedef vector<vi> vvi;
//typedef vector<ll> vl;
//typedef vector<vl> vvl;
//typedef vector<double> vd;
//typedef vector<vd> vvd;
//typedef pair<int,int> pii;
//
//template <typename T> void printContainer(T& a) {
//    auto it = a.begin();
//    cout << "{" << *(it++);
//    for(; it!=a.end(); ++it) cout << ", " << (*it);
//    cout << "}\n";
//}

#include "XUI_macros.hh"
#include "gaussian_generator.h"

/**
* Testy symulacji stochastycznych;
*/
const int NTRIALS = 1e3;
const int TIMESTEPS = 1000; // 24 * 30 = 720;

const int NRANDOMS = NTRIALS * TIMESTEPS;
double* randoms;
int idx;
void preloadRandoms() {
  mt19937 genMt(time(0));
  normal_distribution<double> norDis(0,1);
  randoms = new double[NRANDOMS];
  REP(i,NRANDOMS) {
    randoms[i] = norDis(genMt);
  }
}


int main() {
  START;
  preloadRandoms();
  STOP("gen_random");

  default_random_engine genDefault(time(0));
  mt19937 genMt(time(0));     //just as fast as Default
  normal_distribution<double> norDis(0,1);
//  student_t_distribution<double> studDis(10.0);

  //compute stochastic value, and its stddev at end;
  vd vals, valS;
  double sig = 0.1;
  double dt = 1./24;  //twice/Month
  double sq_dt = sqrt(dt);
  double sig_sqrt_dt = sig*sq_dt;
  double sig_sig_dt_2 = sig * sig * dt / 2;
  GenG gg(time(0));
  START;
  REP(i, NTRIALS) {
    double x = 0, S = 1;
    REP(t, TIMESTEPS) {
//      double num = norDis(genMt);
      double num = randoms[(++idx)%NRANDOMS];
      x += - sig_sig_dt_2 + sig_sqrt_dt * num;
      num = randoms[(++idx)%NRANDOMS];
      S += S * sig_sqrt_dt * num;
    }
    vals.push_back(exp(x));
    valS.push_back(S);
  }
  STOP("simend");
//  printContainer(vals);
  double avg = accumulate(ALL(vals), 0.0) / vals.SS;
  double stDev = 0;
  REP(i,vals.SS) stDev += (vals[i] - avg) * (vals[i] - avg);
  stDev = sqrt(stDev/(vals.SS -1));
  printf("Avg=%f; stdev=%f\n", avg, stDev);
  printf("----------\n");
  avg = accumulate(ALL(valS), 0.0) / valS.SS;
  stDev = 0;
  REP(i,valS.SS) stDev += (valS[i] - avg) * (valS[i] - avg);
  stDev = sqrt(stDev/(valS.SS -1));
  printf("Avg=%f; stdev=%f --- for S\n", avg, stDev);

  delete[] randoms;
}










