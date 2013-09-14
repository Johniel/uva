#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    queue<int> Q;
    for(int i=0; i<n; ++i){
      Q.push(i + 1);
    }
    cout << "Discarded cards:";
    bool flg = true;
    while(Q.size() != 1){
      if(flg){
	cout << ' ';
	flg = false;
      }
      else cout << ", ";
      cout << Q.front();
      Q.pop();
      Q.push(Q.front());
      Q.pop();
    }
    cout << endl;
    cout << "Remaining card: " << Q.front() << endl;
  }
  return 0;
}
