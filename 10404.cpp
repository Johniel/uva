#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10, STONE = 1000000 + 1;

bool dp(int num[], int rm, int st)
{
  static bool t[STONE];
  fill(t, t + st, false);
  for(int i=0; i<rm; ++i){
    if(0 <= st - num[i])
      t[st - num[i]] = true;
  }
  for(int i=st; i--; ){
    if(t[i])continue;
    for(int j=0; j<rm; ++j){     
      if(0 <= i - num[j]){
	t[i - num[j]] = true;
      }
    }
  }
  return t[0];
}

int main(void)
{
  int num[N];
  for(int st, rm; cin >> st >> rm; ){
    for(int i=0; i<rm; ++i){
      cin >> num[i];
    }
    cout << (dp(num, rm, st)? "Stan" : "Ollie") << " wins" << endl;
  }
  return 0;
}
