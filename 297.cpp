#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

const int V = 1024 + 10;
const int H = 32, W = 32;

bool color[V][V];

int build(string s, int idx, int ai, int aj, int bi, int bj)
{
  if(s.size() <= idx)return idx;
  if(false){
    for(int i=0; i<s.size(); ++i)cout << (i == idx ? '|' : '-') ; cout << endl;
    cout << s << endl;
    cout << ai << ' ' << aj << " :: " << bi << ' ' << bj << endl;
  }
  if(s[idx] == 'f'){

    //cout << "(" << ai << ',' << aj << ")"; cout << " : ";
    //cout << "(" << bi << ',' << bj << ")"; cout << endl;
    for(int i=ai; i<bi; ++i){
      for(int j=aj; j<bj; ++j){
        color[i][j] = true;
      }
    }
  }
  else if(s[idx] == 'e'){}
  else{
    int ci = (ai + bi) / 2;
    int cj = (aj + bj) / 2;
    int di = ai;
    int dj = cj;
    int ei = ci;
    int ej = bj;
    int fi = ci;
    int fj = aj;
    int gi = bi;
    int gj = cj;
    idx = build(s, idx + 1, di, dj, ei, ej);// 1
    idx = build(s, idx + 1, ai, aj, ci, cj);// 2
    idx = build(s, idx + 1, fi, fj, gi, gj);// 3
    idx = build(s, idx + 1, ci, cj, bi, bj);// 4
  }
  return idx;
}


int main(void)
{
  
  int tc;
  cin >> tc;
  while(tc--){
    string s, t;
    cin >> s >> t;
    fill(&color[0][0], &color[H-1][W], false);
    build(s, 0, 0, 0, 32, 32);
    build(t, 0, 0, 0, 32, 32);
    /*
    for(int i=0; i<32; ++i){
      for(int j=0; j<32; ++j)cout << color[i][j];
      cout << endl;
    }
    */
    cout << "There are " 
         << count(&color[0][0], &color[H-1][W], true)
         << " black pixels." << endl;
  }
  return 0;
}
