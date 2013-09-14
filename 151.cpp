#include <iostream>

using namespace std;

int Josephus(int n, int s)
{
  if (n == 0) return 0; 
  else return (s + Josephus(n - 1, s) ) % n ;//0~n-1
  
}

int main(void)
{
  //cout << Josephus(13, 1) << endl;
  while(true){
    int n, m;
    cin >> n ;
    if(n == 0)
      break;
    for(int i=0; ; i++){
      if( (12 + i - 1) % n == Josephus(n, i)){
	//cout << Josephus(n, i) << ' ';
	cout << i << endl;
	break;
      }
    }
  }
  return 0;
}
