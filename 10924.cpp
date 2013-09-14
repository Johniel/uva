#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  const int LIM = 2000;
  int cnt = 0;
  map<char, int> M;  
  string s;
  bool p[LIM];  
  for(int c='a'; c <= 'z'; ++c)M[c] = ++cnt;
  for(int c='A'; c <= 'Z'; ++c)M[c] = ++cnt;
  p[0] = false;
  fill(p + 1, p + LIM, true);  
  for(int i = 2; i * i < LIM; ++i){    
    for(int j = 2; i * j < LIM; ++j)
      p[i * j] = false;
  }
  while(cin >> s){
    int sum = 0;
    for(int i=0; i<s.size(); ++i){      
      sum += M[s[i]];
    }
    if(p[sum])cout << "It is a prime word." << endl;
    else cout << "It is not a prime word." << endl;
  }
  return 0;
}
