#include <iostream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int f, b;
    cin >> f >> b;
    int sum = 0;
    for(int i=0; i<b; ++i){
      int k;
      int mult = 1;
      cin >> k;
      for(int j=0; j<k; ++j){
	int tmp;
	cin >> tmp;
	mult *= tmp;
	mult %= f;
      }
      sum += mult % f;
    }
    cout << sum % f << endl;
  }
  return 0;
}
