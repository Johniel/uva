#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i=0; i<n; ++i){
      int tmp;
      cin >> tmp;
      Q.push(tmp);
    }
    int sum = 0;
    while(Q.size() != 1){
      int a = Q.top();
      Q.pop();
      int b = Q.top();
      Q.pop();
      sum += a + b;
      Q.push(a + b);
    }
    cout << sum << endl;
  }
  return 0;
}
