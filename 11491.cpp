//uva 11419
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 100000;
const int candidate = 2;

void rec(int n, int m, queue<int> q[])
{  
  //cout << n << ' ' << m << endl;
  if(m == 0)return ;  
  for(int i=9; i>=0; --i){
    if(q[i].empty())continue;
    if(n - q[i].front() >= m){
      int tmp = q[i].front();
      q[i].pop();
      for(int j=9; j>=0; --j){
	while(q[j].size() && q[j].front() <= tmp){
	  q[j].pop();
	}
      }
      cout << i ;
      rec(n, m-1, q);
      break;
    }
  }  
  return ;
}

int main(void)
{
  for(int n, m; ; ){
    cin >> n >> m;
    if(n + m == 0)break;
    queue<int> q[10];
    for(int i=0; i<n; ++i){
      char c;
      cin >> c;
      q[c - '0'].push(i);
    }
    rec(n, n-m, q);
    cout << endl;
  }
  return 0;
}
