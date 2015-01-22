
#ifndef XMACROS_H
#define XMACROS_H



#include <bits/stdc++.h>
#define REP(i,n)  for(int i=0;i<(int)(n);++i)
#define FOR(i,b,n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define CLR(a,v) memset((a),(v), sizeof a)
#define ST first
#define ND second
template<typename T, typename U> inline void AMIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void AMAX(T &x, U y) { if(x < y) x = y; }
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pii;

template <typename T> void printContainer(T& a, int num = 10) {
  auto it = a.begin();
  cout << "{" << *(it++);
  for(int n =0; it!=a.end() && n<num; ++it, ++num) cout << ", " << (*it);
  cout << "}\n";
}

timespec startCLK, stopCLK;
#define START clock_gettime(CLOCK_MONOTONIC, &startCLK)
#define STOP(c) clock_gettime(CLOCK_MONOTONIC, &stopCLK); \
printf("dt = %6.3f [ms]%s\n", (stopCLK.tv_sec - startCLK.tv_sec) * 1000. +\
1. * (stopCLK.tv_nsec - startCLK.tv_nsec) / 1e6, (c))



#endif //XMACROS_H