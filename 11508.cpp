#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
  string s;
  while(getline(cin, s) && s != "0"){
    istringstream iss(s);
    vector<int> v, result;
    int n;
    while(iss >> n){
      v.push_back(n);
    }
    sort(v.begin(), v.end());        
    result.resize(v.size(), -1);

    bool flg = true;
    
    for(int i=0; i<v.size() && flg; ++i){
      flg = v[i] < result.size();
      if(result[v[i]] == -1){
	result[v[i]] = v[i];
	v.erase(v.begin() + i--);
      }
    }

    for(int i=0, j = 0; i<v.size() && flg; ++i){
      while(result[j] != -1)++j;
      result[j] = v[i];
    }

    for(int i=0; i<result.size() && flg; ++i){      
      flg = result[result[i]] == result[i];	 
    }

    if(flg){
      for(int i=0; i<result.size(); ++i){	
	if(i)cout << ' ' ;
	cout << result[i];
      }
      cout << endl;
    }
    else cout << "Message hacked by the Martians!!!" << endl;
  }
  return 0;
}
