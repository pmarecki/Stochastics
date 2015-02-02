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

int main() {
  //compute stochastic value, and its stddev at end;
  vd vals;
  int nTrials = 1e5;
  int tMax = 4000; // 24 * 30 = 720;
  double sig = 0.1;
  double dt = 1./24;  //twice/Month
  double sq_dt = sqrt(dt);
  double factor = sig*sq_dt;
  GenG gg(time(0));
  START;
  REP(i,nTrials) {
    double x = 0;
    REP(t,tMax) {
      x += - sig * sig * dt/2 + sig * sq_dt * gg.nxtGauss();
    }
    vals.push_back(exp(x));
  }
  STOP("simend");
//  printContainer(vals);
  double avg = accumulate(ALL(vals), 0.0) / vals.SS;
  printContainer(vals, 10);
  double stDev = 0;
  REP(i,vals.SS) stDev += (vals[i] - avg) * (vals[i] - avg);
  stDev = sqrt(stDev/(vals.SS -1));
  printf("Avg=%f; stdev=%f\n", avg, stDev);

}










