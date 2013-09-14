#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  while(true){
    int num[3][3];
    int color[3];
    int sum = 0;
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
	cin >> num[i][j];
	if(cin.eof() == true)return 0;
	sum += num[i][j];
      }
    }

    for(int i=0; i<3; i++)
      swap(num[i][1], num[i][2]);

    int result = INT_MIN;
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
	if(i == j)continue;
	for(int k=0; k<3; k++){
	  if(j == k || i == k)continue;
	  if(result < num[0][i] + num[1][j] + num[2][k]){
	    result = num[0][i] + num[1][j] + num[2][k];
	    color[0] = i;
	    color[1] = j;
	    color[2] = k;
	    //cout << result << endl;
	  }
	}
      }
    }
    for(int i=0; i<3; i++){
      if(color[i] == 0)
	cout << 'B';
      else if(color[i] == 2)
	cout << 'G';
      else if(color[i] == 1)
	cout << 'C';
    }
    //cout << num << ' ' << result << endl;
    cout << ' ' << (sum-result) << endl;
  }
  return 0;
}
