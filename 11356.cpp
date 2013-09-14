#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

const string M[] = {"January", 
                    "February", 
                    "March", 
                    "April", 
                    "May", 
                    "June", 
                    "July", 
                    "August", 
                    "September", 
                    "October", 
                    "November", 
                    "December"};

const int D[12][2] = {{31, 31}, 
                      {28, 29}, 
                      {31, 31}, 
                      {30, 30}, 
                      {31, 31}, 
                      {30, 30}, 
                      {31, 31}, 
                      {31, 31}, 
                      {30, 30}, 
                      {31, 31}, 
                      {30, 30}, 
                      {31, 31}};

bool isleap(int y)
{
  if(y%4 == 0){
    if(y%100 == 0 && y%400 != 0)return false;
    return true;
  }
  return false;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    string s;
    int n;
    cin >> s >> n;
    for(int i=0; i<s.size();++i){
      if(s[i] == '-')s[i] = ' ';
    }
    istringstream iss(s);
    int y, m, d;
    string t;
    iss >> y >> t >> d;
    for(int i=0; ; ++i){
      if(M[i] == t){
        m = i + 1;
        break;
      }
    }
    for(int i=0; i<n; ++i){
      ++d;
      //cout << D[m-1][isleap(y)] << " : " << m << ", " << d << endl;
      if(D[m-1][isleap(y)] < d){
        ++m;
        d = 1;
      }
      if(m == 13){
        m = 1;        
        ++y;
      }
    }
    printf("Case %d: %d-%s-%02d\n", ++cnt, y, M[m-1].c_str(), d);
  }
  return 0;
}
