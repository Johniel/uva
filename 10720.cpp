#include <iostream>
#include <algorithm>

using namespace std;

bool graphicSequence(int degree[], int size)
{
  int sum = 0;
  for(int i=0; i<size; ++i){
    sum += degree[i];    
  }
  if(sum % 2)return false;
  sort(degree, degree + size);
  reverse(degree, degree + size);
  sum = 0;
  for(int r=0; r<size-1; ++r){
    sum += degree[r];
    int m = 0;
    for(int i=r+1; i<size; ++i){
      m += min(r + 1, degree[i]);
    }
    if(r * (r + 1) + m < sum){
      return false;
    }
  }  
  return true;
}

int main(void)
{
  int degree[10000 + 1];
  int tc, n;
  for(cin >> tc; tc--; ){
    cin >> n;
    bool flg = true;
    for(int i=0; i<n; ++i){
      cin >> degree[i];
      flg = flg & degree[i] >= 0;
    }
    cout << (flg && graphicSequence(degree, n) && !(n==1 && degree[0] > 0)? 
	     "Yes" : "No") << endl;
  }
  return 0;
}
