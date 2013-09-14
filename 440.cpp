//uva 440
#include <iostream>

using namespace std;

int Josephus(int n, int s)
{
  if(n == 0)return 0; 
  else return (s + Josephus(n - 1, s) ) % n ;//0~n-1
  
}

int main(void)
{
  for(int n; ; ){
    cin >> n; 
    if(n == 0)break;
    for(int i=1; ; ++i){
      if((n + i) % n == Josephus(n, i)){
	cout << i << endl;
	break;
      }
    }
  }
  return 0;
}

