#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 1000 + 1;
  int num[N];
  for(int n; cin >> n; ){
    for(int i=0; i<n; ++i){
      cin >> num[i];
    }
    int cnt = 0;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n-i-1; ++j){
	if(num[j] > num[j + 1]){
	  ++cnt;
	  swap(num[j], num[j + 1]);
	}
      }
    }
    cout << "Minimum exchange operations : " << cnt << endl;
  }
  return 0;
}
