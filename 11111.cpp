#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>

using namespace std;

const int INF = 1 << 22;

int cnt;

int solve(const vector<int> &v, int b, int e)
{
  //cout << v[b] << ' ' << v[e] << " : " << b << ' ' << e << endl;
  if(v[b] != -v[e])return INF;  
  ++cnt;
  int sum = 0;  
  int size = v[e];
  ++b;  
  while(b < e){
    int o = 0, c = 0, i;
    for(i = b + 1; i < e; ++i){
      if(o == c && v[b] == -v[i])break;
      if(v[i] < 0)++o;
      else ++c;
    }
    sum += solve(v, b, i);
    b = i + 1;
  }
  return (sum < size) ? size : INF;
}

int main(void)
{
  for(string s; getline(cin, s); ){
    istringstream iss(s);
    vector<int> v;    
    for(int n; iss >> n; v.push_back(n));

    cnt = 0;

    if(solve(v, 0, (int)v.size() - 1) == -v[0]){
      if(cnt * 2 == v.size()){
	//cout << ":-) Matrioshka!" << endl;
	puts(":-) Matrioshka!");
      }
      else{
	//cout << ":-( Try again." << endl;
	puts(":-( Try again.");
      }
    }
    else{
      //cout << ":-( Try again." << endl;
      puts(":-( Try again.");
    }
  }
  return 0;
}
