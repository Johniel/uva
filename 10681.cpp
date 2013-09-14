#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100 + 1;

int node, edge;

struct M{
  int m[N][N];
  M(){ fill(&m[0][0], &m[N-1][N], 0); }
};
M operator * (const M &a, const M &b)  
{
  M c;
  for(int i=1; i<=node; ++i){
    for(int j=1; j<=node; ++j){
      for(int k=1; k<=node; ++k){
        c.m[i][j] += (a.m[i][k] * b.m[k][j] ) % 100;
      }
    }
  }
  return c;
}

M unit(void)
{
  M m;
  for(int i=1; i<=node; ++i)m.m[i][i] = 1;
  return m;
}

M m_pow(M m, int p)
{
  if(p == 0)return unit();
  if(p == 1)return m;
  M n = m_pow(m, p / 2);
  n = n * n;
  return p % 2 ? n * m : n;
}

M test(M m, int d)
{
  M t = unit();
  while(d){
    if(d & 1)t = t * m;
    m = m * m;
    d >>= 1;
  }
  return t;
}

int main(void)
{
  while(cin >> node >> edge && (edge | node)){
    M m;
    int a, b, c;
    while(edge--){
      cin >> a >> b;
      m.m[a][b] = m.m[b][a] = 1;
    }
    cin >> a >> b >> c;
    m = m_pow(m, c);
    //m = test(m, c);
    if(m.m[a][b])cout << "Yes, Teobaldo can travel." << endl;
    else cout << "No, Teobaldo can not travel." << endl;
  }
  return 0;
}
