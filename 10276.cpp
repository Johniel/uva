#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

bool canPush(stack<int> s[], int i, int n)
{
  if(s[i].empty())return true;
  int a = s[i].top() + n;
  int b = sqrt(a);    
  return b * b == a;
}

void rec(stack<int> s[], const int S, int depth, int &result)
{
  //cout << depth << endl;
  result = max(depth, result);
  for(int i=0; i<S; ++i){
    if(canPush(s, i, depth)){
      s[i].push(depth);
      rec(s, S, depth + 1, result);
      s[i].pop();
      break;
    }    
  }
  return ;
}

int main(void)
{
  int tc, n;
  stack<int> s[50 + 1];
  for(cin >> tc; tc--; ){
    cin >> n;
    int result = -1;
    rec(s, n, 1, result);
    cout << result-1 << endl;
  }
  return 0;
}
