#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-7;
const double H = sqrt(3) / 2;

int skew1(double a, double b)
{
  a += EPS;
  b += EPS;
  int w = floor(a - 0.5);
  int h = floor((b - 1) / H) + 1;
  w = max(w, 0);
  h = max(h, 0);
  //cout << "skew1 : " << w << ' ' << h << endl;
  return w * h;
}

int skew2(double a, double b)
{
  a += EPS;
  b += EPS;
  int w = floor(a);
  int h = floor((b - 1) / H) + 1;
   w = max(w, 0);
   h = max(h, 0);
  //cout << "skew2 : " << w << ' ' << h << endl;
  return w * h - h / 2;
}

int main(void)
{
  for(double a, b; cin >> a >> b; ){
    int grid = floor(a) * floor(b);    
    int skew = max(max(skew1(a, b), skew1(b, a)), 
		   max(skew2(a, b), skew2(b, a)));       
    cout << max(grid, skew) << (grid<skew? " skew" : " grid") << endl;
  }  

  return 0;
}
