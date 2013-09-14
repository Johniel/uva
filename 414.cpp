#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;
  while( cin >> n && n){
    vector<string> input;
    string tmp;
    getline(cin,tmp);
    while(n--){
      string in;
      getline(cin,in);
      input.push_back(in);
    }

    //for(int  i=0; i<input.size(); i++)cout << input[i] << endl;

    int blank = INT_MAX;
    int cnt = 0;
    vector<int> num;
    for(int i=0; i<input.size(); i++){
      for(int j=0; j<input[i].size(); j++){
	if( input[i][j] != 'X')
	  cnt++;
      }
      num.push_back(cnt);
      blank = min(blank,cnt);
      cnt = 0;
    }
    //cout << blank << endl;
    for(int i=0; i<num.size(); i++){
      cnt += num[i] - blank;
    }
    cout << cnt << endl;
  }
  return 0;
}
