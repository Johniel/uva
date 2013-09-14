#include <iostream>
#include <sstream>

using namespace std;

#include <cstdio>

string conv(double sum)
{
  static char buff[100000];
  string s, t;
  sprintf(buff, "%.2lf", sum / 12.0);
  s = string(buff);
  t = s.substr( (int)s.size()-3 );
  int cnt = 0;
  for(int i=(int)s.size()-4; 0<=i; --i){
    if( cnt && cnt % 3 == 0 )t = "," + t;
    t = s[i] + t;
    ++cnt;
  }
  return t;
}

int main(void)
{
  int tc;
  int cnt = 0;
  cin >> tc; 
  while( tc-- ){
    double sum = 0;
    for(int i=0; i<12; ++i){
      double n;
      cin >> n;
      sum += n;
    }
    cout << ++cnt << " $" << conv(sum) << endl;
  }
  return 0;
}
