#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    int num[n];
    for(int i=0; i<n; i++)
      cin >> num[i];
    int cnt = 0;
    for(int i=0; i<n-1; i++){
      if(num[i] > num[i+1]){
	swap(num[i], num[i+1]);
	cnt++;
	i = -1;
      }
    }
    //for(int i=0; i<n; i++)cout << num[i] << ' '; cout << endl;
    cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
  }
  return 0;
}
