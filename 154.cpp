#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
  const int N = 130;
  int e[N][N];
  int buff[N];
  while(true){
    string s;
    vector<string> v;
    fill(buff, buff + N, 0);
    for(; cin >> s && s[0] != 'e'; v.push_back(s));
    if(s == "#")break;
    for(int i=0; i<v.size(); ++i){
      for(int j=2; j<v[i].size(); j+=4){
        int a = v[i][j-2];
        int b = v[i][j];
        e[i][a] = b;
      }
    }
    for(int i=0; i<v.size(); ++i){
      for(int j=i+1; j<v.size(); ++j){
        int cnt = 0;
        string t = "roygb";
        for(int k=0; k<t.size(); ++k){
          if(e[i][t[k]] != e[j][t[k]])++cnt;
        }
        buff[i] += cnt;
        buff[j] += cnt;
      }
    }
    int mn = 1 << 22;
    int idx;
    for(int i=0; i<v.size(); ++i){
      if(buff[i] < mn){
        mn = buff[i];
        idx = i;
      }      
    }
    cout << idx + 1 << endl;
  }  
  return 0;
}
