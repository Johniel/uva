#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

inline
double conv(double d)
{
  return M_PI * d / 180.0;
}

int main(void)
{
  int tc, n;
  for(cin >> tc; tc--; ){    
    double angle, i, j, l;
    string s;
    angle = i = j = 0;
    for(cin >> n; n--; ){
      cin >> s >> l;
      if(s == "fd"){	
        i += l * sin(conv(angle));
        j += l * cos(conv(angle));
      }
      else if(s == "lt"){
        angle = fmod(angle + l, 360.);
      }
      else if(s == "rt"){
        angle = fmod(angle - l, 360.);
      }
      else if(s == "bk"){
        i -= l * sin(conv(angle));
        j -= l * cos(conv(angle));
      }
    }
    printf("%0.lf\n", sqrt(i * i + j * j));
  }
  return 0;
}
