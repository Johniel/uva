#include <iostream>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

static const double EPS = 1e-7;

inline bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}

inline bool lessThan(double a, double b)
{
  return !eq(a, b) && a < b;
}

inline bool greaterThan(double a, double b)
{
  return !eq(a, b) && a > b;
}


bool comp(string s, map<string, double> M)
{
  istringstream iss(s);
  string t;
  double sum = 0;
  int r;
  while(iss >> t){
    if(t == "<"  || t == ">"  || 
       t == "<=" || t == ">=" || 
       t == "=")break;
    else if(t == "+")continue;
    else sum += M[t];
  }
  iss >> r;
  if(t == "<")
    return lessThan(sum, r);
  if(t == ">")
    return greaterThan(sum, r);
  if(t == "<=")
    return lessThan(sum, r) || eq(sum, r);
  if(t == ">=")
    return greaterThan(sum, r) || eq(sum, r);
  if(t == "=")
    return eq(sum, r);
}

int main(void)
{
  int v, q;
  while(cin >> v >> q){
    map<string, double> M; 
    for(int i=0; i<v; ++i){
      string s;
      double d;
      cin >> s >> d;
      M[s] = d;
    }
    cin.ignore();
    for(int i=0; i<q; ++i){
      string s;
      getline(cin, s);
      cout << "Guess #" << i + 1 <<" was "; 
      if(comp(s, M))cout << "correct." << endl;
      else cout << "incorrect." << endl;
    }
  }
  return 0;
}
