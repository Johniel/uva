//num[0] + num[1] + num[2] > num[3]

#include <iostream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    long long num[4];
    for(int i=0; i<4; i++)cin >> num[i];
    sort(num, num + 4);
    if(num[0] == num[1] && num[1] == num[2] && num[2] == num[3])
      cout << "square" << endl;
    else if(num[0] == num[1] && num[2] == num[3])
      cout << "rectangle" << endl;
    else if(num[0] + num[1] + num[2] > num[3])
      cout << "quadrangle" << endl;
    else
      cout << "banana" << endl;
  }  
  return 0;
}


 

