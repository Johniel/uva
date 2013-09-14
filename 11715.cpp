#include <iostream>
#include <cmath>

using namespace std;

void output(double x, double y)
{
  static int tc = 0;
  printf("Case %d: %.3lf %.3lf\n",++tc, x, y);
  return ;
}

void query1(void)
{
  double u, v, t, a;
  cin >> u >> v >> t;
  a = (v - u) / t;
  output((v * v - u * u) / (2 * a), a);
  return ;
}

void query2(void)
{
  double u, v, a, t;
  cin >> u >> v >> a;
  t = (v - u) / a;
  output((v * v - u * u) / (2 * a), t);
  return ;
}

void query3(void)
{
  double u, a, s, t, v;
  cin >> u >> a >> s;
  v = sqrt(2 * a * s + u * u);
  output(v, 2 * s / (u + v));
  return ;
}

void query4(void)
{
  double v, a, s, t, u;
  cin >> v >> a >> s;
  u = sqrt(- 2 * a * s + v * v);
  output(u, 2 * s / (u + v));
  return ;
}

int main(void)
{
  while(true){
    int q;
    cin >> q;
    if(q == 1)query1();
    else if(q == 2)query2();
    else if(q == 3)query3();
    else if(q == 4)query4();
    else break;
  }
  return 0;
}
