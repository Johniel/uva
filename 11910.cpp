#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstring>

using namespace std;

int gcd(int a, int b){ return a % b ? gcd(b, a%b) : b; }

char buff[20];
string f[] = {"%1.9lf", 
              "%1.9lf",
              "%2.8lf",
              "%3.7lf",                
              "%4.6lf",
              "%5.5lf",
              "%6.4lf",
              "%7.3lf",
              "%8.2lf",
              "%9.1lf",
              "%10.0lf"};

const double eps = 1e-12;

inline
bool eq(double a, double b)
{
  return fabs(a - b) < eps;
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

inline
char* conv(double n)
{
  sprintf(buff, "%d", (int)n);
  int tmp = strlen(buff);
  sprintf(buff, f[tmp].c_str(), n);
  return buff;
}

int main(void)
{
  const int N = 608383 + 5;
  static double num[N];
  static char str[N][20];
  int size = 0;
  static char s[10000];  
  double n, diff; 
  int a, b, c;
  for(int i=1; i<=1000; ++i){
    for(int j=1; j<=1000; ++j){
      if(gcd( max(i, j), min(i, j) ) != 1)continue;
      num[size] = (double)i / (double)j;
      sprintf(str[size], "%4d / %d", i, j);
      ++size;
    }
  }  
  num[size] = 1e256; 
  while(gets(s)){
    sscanf(s, "%lf", &n);
    a = b = c = size;    
    for(int i=0; i<size; ++i){
      diff = fabs(n - num[i]);
      double s = fabs(n - num[a]);
      double t = fabs(n - num[b]);
      double u = fabs(n - num[c]);
      //if(s >= diff){
      if(greaterThan(s, diff) || eq(s, diff)){
        c = b;
        b = a;
        a = i;
      }
      //else if(t >= diff){
      else if(greaterThan(t, diff) || eq(t, diff)){
        c = b;
        b = i;
      }
      //else if(u > diff){
      else if(greaterThan(u, diff)){
        c = i;
      }
    }    
    printf("Input : "); puts(s);
    printf("    1 : %s = %s\n", conv(num[a]), str[a]);
    printf("    2 : %s = %s\n", conv(num[b]), str[b]);
    printf("    3 : %s = %s\n", conv(num[c]), str[c]);
  }
  return 0;
}
