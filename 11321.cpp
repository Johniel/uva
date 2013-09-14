#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m; 

bool cmp(int a, int b)
{
  int am = a % m, bm = b % m;

  if(am == bm){
    if(abs(a % 2) == 1 && abs(b % 2) == 0)return true;
    if(abs(a % 2) == 0 && abs(b % 2) == 1)return false;
    if(abs(a % 2) == 1 && abs(b % 2) == 1)return a > b;
    if(abs(a % 2) == 0 && abs(b % 2) == 0)return a < b; 
  }
  return am < bm;
}

int main(void)
{  
  const int N = 10000;
  int array[N];
  while(true){
    cin >> n >> m;
    cout << n << ' ' << m << endl;
    if(n == 0 && m == 0)break;
    for(int i=0; i<n; ++i){
      cin >> array[i];
    }
    sort(array, array + n, cmp);
    for(int i=0; i<n; ++i){
      cout << array[i] << endl;
    }
  }
  return 0;
}
