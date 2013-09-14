#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Task{
  int no;
  double num;
  Task(){}
  Task(int _no, double _num) : no(_no), num(_num)  {}
};

static const double EPS = 1e-7;

inline 
bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}

inline 
bool lessThan(double a, double b)
{
  return !eq(a, b) && a < b;
}

inline 
bool greaterThan(double a, double b)
{
  return !eq(a, b) && a > b;
}

bool operator < (const Task &a, const Task &b)
{
  return lessThan(a.num, b.num);
}

int main(void)
{
  int tc;
  Task T[1000 + 1];
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      double t, f;
      cin >> t >> f;
      T[i] = Task(i+1, t / f);
    }
    stable_sort(T, T + n);
    for(int i=0; i<n; ++i){
      if(i)cout << ' ';
      cout << T[i].no;
    }
    cout << endl;
    if(tc)cout << endl;
  }
  return 0;
}
