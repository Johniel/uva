#include <iostream>
#include <algorithm>

using namespace std;

int n[10];
int m[10];

bool check(void)
{
  for(int i=0; i<10; ++i){
    if(n[i] !=m[i])return false;
  }
  return true;
}

int main(void)
{
  int tc;
  cin >> tc;
  cout << "Lumberjacks:" << endl;
  while( tc-- ){
    for(int i=0; i<10; ++i){
      cin >> n[i];
      m[i] = n[i];
    }
    bool flg = false;
    sort(m, m + 10);
    flg = flg || check();
    reverse(m, m + 10);
    flg = flg || check();
    cout << (flg ? "Ordered" : "Unordered") << endl;
  }
  return 0;
}
