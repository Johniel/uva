#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
  int num[1000];
  int tc = 0;
  while(true){
    int n;
    set<int> S;
    cin >> n;    
    if(n == 0)
      break;
    for(int i=0; i<n; ++i)
      cin >> num[i];
    for(int i=0; i<n-1; ++i){
      for(int j=i+1; j<n; ++j){
	if(num[i] == num[j])continue;
	S.insert(num[i] + num[j]);
      }
    }
    cout << "Case " << ++tc << ":" << endl;
    int q;
    cin >> q;
    for(int i=0; i<q; ++i){
      int m, r;
      cin >> m;
      set<int>::iterator itr = S.find(m);
      if(itr == S.end()){
	S.insert(m);
	itr = S.find(m);
	if(itr == S.begin())r = *(++itr);	
	else if(++itr == S.end())r = *(++S.rbegin());
	else{
	  set<int>::iterator a = itr, b = S.begin();
	  int l = distance(S.begin(), S.find(m));
	  for(int j=0; j<l-1; ++j)++b;
	  r = (abs(*a - m) < abs(*b - m))? *a : *b;
	}
	S.erase(m);
      }
      else r = m;
      cout << "Closest sum to " << m << " is " << r << "." << endl;
    }
  }  
  return 0;
}
