#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  while( n-- ){
    int size, cnt = 1;
    cin >> size;
    int num[size];
    for(int i=0; i<size; i++)
      cin >> num[i];
    for(int i=1; i<size; i++){
      if(cnt%2 == 1 && num[i-1] > num[i]){
	cnt++;
      }
      else if(cnt%2 == 0 && num[i-1] < num[i]){
	cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
