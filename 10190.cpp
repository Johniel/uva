#include <iostream>

using namespace std;

bool valid(int n, int m)
{
  int p = 2000000000 + 1;
  if(n < m)return false;
  if(!n)return false;
  if(!m)return false;
  while(n % m == 0){
    if(n >= p)return false;
    p = n;
    n /= m;    
  }
  return n == 1;
}

int main(void)
{
  for(int n, m; cin >> n >> m; ){
    if(valid(n, m)){
      while(true){
	cout << n;
	if(n == 1)break;
	cout << ' ';
	n /= m;	
      }
      cout << endl;
    }    
    else{
      cout << "Boring!" << endl;
    }
  }
  return 0;
}
