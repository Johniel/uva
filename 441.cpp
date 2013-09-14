#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

int num[13];
int re[13];

void BT(int n, int p, int r)
{
  if(r == 6){
    REP(i, 6){
      cout << re[i];
      if(i != 5)cout << ' '; 
    }
    cout << endl;
  }
  else{
    for(int i=p; i<n; i++){
      re[r] = num[i];
      BT(n, i + 1, r + 1);
    }
  }
}

int main(void)
{
  bool flg = false;
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;
    if(flg)cout << endl;
    REP(i, n)
      cin >> num[i];
    sort(num, num + n);
    BT(n , 0, 0);
    //cout << endl;
    flg = true;
  }
  return 0;
}
