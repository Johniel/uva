#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  string s;
  lli cd[30], buff[30], ans[30];
  while(getline(cin, s)){
    istringstream iss(s);
    lli n, t, mx = -1, sum, bit;
    lli size = 0, len;

    iss >> n >> t;
    while(iss >> cd[size++]);
    --size;
    
    lli lim = 1ll << size;
    for(lli i=0; i<lim; ++i){    
      sum = bit = 0;
      for(lli j=0; j<size; ++j){
        if(i & (1ll << j)){
          sum += cd[j];
          buff[bit++] = cd[j];
        }
      }
      if(sum <= n && mx < sum && bit <= t){        
        mx = sum;
        len = bit;
        copy(buff, buff + bit, ans); 
      }
      else if(mx == sum && len < bit){
        len = bit;
        copy(buff, buff + bit, ans); 
      }
    }

    //cout << endl; for(int i=0; i<size; ++i)cout << cd[i] << ' '; cout << endl;
    for(int i=0; i<len; ++i)cout << ans[i] << ' ';
    cout << "sum:" << mx << endl;
  }
  return 0;
}
