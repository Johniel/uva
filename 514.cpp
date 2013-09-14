#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;    
    while(true){
      queue<int> S;
      stack<int> T;
      bool flg = true;
      for(int i=0; i<n && flg; ++i){
	int n;
	cin >> n;
	flg = n != 0;
	S.push(n);
      }
      if(!flg)break;
      for(int i=0; i<n; ++i){
	T.push(i+1);
	while(!(S.empty() || T.empty()) && T.top() == S.front()){
	  S.pop();
	  T.pop();
	}
      }
      cout << ((S.empty() && T.empty())? "Yes" : "No") << endl;
    }
    cout << endl;
  }
  return 0;
}
