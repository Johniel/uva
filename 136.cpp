#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
  priority_queue<long long int, vector<long long int>, greater<long long int> > que;
  long long int cnt = 1500, num;// - 1;
  que.push(1);
  while(cnt--){
    num = que.top();
    que.pop();
    if(!que.empty())
    if(num == que.top()){
      cnt++;
      continue;
    }
    //cout << num << " No." << 1500 - cnt << endl;
    que.push( num * 2 ); 
    que.push( num * 3 );
    que.push( num * 5 );
  }
  cout << "The 1500'th ugly number is "<< num << "." << endl;
  return 0;
}
