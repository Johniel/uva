#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(cin.eof() == true)break;
    int num[n];
    set<int> mul;
    map<int, int> h;

    for(int i=0; i<n; i++){
      int in;
      cin >> in;
      if(h.count(in)){
	h[in]++;
	n--;
	i--;
      }
      else 
	h.insert( make_pair(in,0) );
      num[i] = in;
    }

    int cnt = 0;
    sort(&num[0], &num[n]);
    set<int> rem;
    for(int i=0; i<n; i++){
      for(int j=i; j<n; j++){
	int t = num[i] + num[j];
	int left = 0, right = n, p;
	if(rem.count(t)){cnt++;continue;}
	while(left <= right){
	  p = left + (right - left) * (num[p] -  num[left]) / (num[right]) ;
	  if(num[p] == t){
	    rem.insert(t);
	    cnt++;
	    break;
	  }
	  if(num[p] > t)left = p;
	  else right = p;
	}
      }
    }
  }
  return 0;
}
