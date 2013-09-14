#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

static const double PI = 3.141592653589793;

typedef struct{double x, y;} point;

point center3p(double x1, double y1,
	       double x2, double y2,
	       double x3, double y3)
{
  double G=( y2*x1-y1*x2 +y3*x2-y2*x3 +y1*x3-y3*x1 );
  double Xc= ((x1*x1 + y1*y1) * (y2 - y3) + (x2*x2 + y2*y2) * (y3-y1) + (x3*x3 + y3*y3) * (y1 - y2)) / (2*G);
  double Yc = -( (x1*x1 + y1*y1) * (x2-x3) + (x2*x2 + y2*y2) * (x3-x1) + (x3*x3 + y3*y3) * (x1 - x2)) / (2*G);
  point re;
  re.x = Xc;
  re.y = Yc;
  return re;
}

double dist(point c, point p)
{
  return sqrt( (c.x - p.x) * (c.x - p.x) + (c.y - p.y) * (c.y - p.y) );
}

int main(void)
{
  while(true){
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(cin.eof())break;
    point c = center3p(x1, y1, x2, y2, x3, y3);
    point p;
    p.x = x1;
    p.y = y1; 
    printf("%.2lf\n",dist(c, p) * 2 * PI);
  }
  return 0;
}
