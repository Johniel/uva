#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
  bool prime[1001];
  fill(&prime[0], &prime[1001], true);
  prime[0] = false;
  prime[1] = true;
  for(int i=2; i*i<1001; i++){
    for(int j=2; j*i<1001; j++){
      prime[i*j] = false;
    }
  }
  while(true){
    int n, m;
    cin >> n >> m;
    if(cin.eof() == true)
      break;
    int cnt = 0;
    vector<int> out;
    for(int i=1; i<=n; i++)
      if(prime[i] == true)out.push_back(i);

    cout << n << ' ' << m << ':' ;

    //cout << out.size() << ' ' << out.size()/2 << ' ' << m*2 << endl;

    int to, from;
    if(out.size() % 2 == 1){
      int c = out.size()/2 + 1;
      from = c - m;
      to = c + m - 1 - 1;
    }
    else{
      int c = out.size()/2;
      from = c - m;
      to = c + m - 1;
    }
    if(to >= out.size()){
      from -= to - out.size();
      to = out.size()-1;
    }
    if(from < 0)
      from = 0;
    //cout << from << ' ' << to << endl;
    for(int i=from; i<=to; i++){
      cout << ' ' << out[i] ;
    }
    cout << endl;
    //for(int i=0; i<out.size(); i++){
    //cout << out[i] << ' ' ;
    //}
    cout << endl;
  }
  return 0;
}
