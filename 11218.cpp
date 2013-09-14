#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
  int n[3];
  int score;
}Group;

int re;

void bt(Group g[], int size, int b, bool s[], int sum, int d)
{
  if(d == 3){
    re = max(re, sum);
    return ;
  }
  for(int i=b; i<size; ++i){
    if(s[g[i].n[0]] && s[g[i].n[1]] && s[g[i].n[2]]){
      s[g[i].n[0]] = s[g[i].n[1]] = s[g[i].n[2]] = false;
      bt(g, size, b, s, sum + g[i].score, d + 1);
      s[g[i].n[0]] = s[g[i].n[1]] = s[g[i].n[2]] = true;
    }
  }

  return ;
}

int main(void)
{
  int tc = 0;
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    Group g[n];
    bool s[9];
    fill(s, s + 9, true);
    for(int i=0; i<n; ++i){
      cin >> g[i].n[0] >> g[i].n[1] >> g[i].n[2] >> g[i].score;
      --g[i].n[0];
      --g[i].n[1];
      --g[i].n[2];
    }
    re = -1;
    bt(g, n, 0, s, 0, 0);
    cout << "Case " << ++tc << ": " << re << endl;
  }  
  return 0;
}
