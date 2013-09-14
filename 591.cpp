#include <iostream>

using namespace std;

int main(void)
{
  int cnt = 0;
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;
    int num[n];
    int sum = 0;
    for(int i=0; i<n; i++){
      cin >> num[i];
      sum += num[i];
    }
    int ave = sum/n;
    int result = 0;
    for(int i=0; i<n; i++){
      if(num[i] > ave){
	result += num[i] - ave;
      }
    }
    cout << "Set #" << ++cnt << endl;
    cout << "The minimum number of moves is " << result << '.'<< endl << endl;
  }
  return 0;
}
