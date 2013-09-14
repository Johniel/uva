#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
  int b, p, m;
  while(cin >> b >> p >> m){
    map<int, int> i2n, n2i;
    if(p == 0){
      cout << 1 << endl;
      continue;
    }
    int n = b % m;
    bool flg = false;
    for(int i=1; i<p; ++i){
      if(n2i.find(n) != n2i.end()){
	int j = n2i[n];
	int k = p % (i - 1);
	cout << i2n[k] << endl;
	flg = true;
	break;
      }
      if(n == 0){
	cout << 0 << endl;
	flg = true;
	break;
      }
      i2n[i] = n;
      n2i[n] = i;
      n *= b % m;
      n %= m;
    }
    if(!flg){
      cout << n << endl;
    }
  }
  return 0;
}
