#include <iostream>
#include <vector>

using namespace std;

bool sim(vector<int> v, int i)
{
  int lim = v.size() / 2;
  int j = i;
  int size = v.size();
  i %= size;
  while(lim--){
    if(v[i] < size/2)return false;
    v.erase( v.begin() + i );
    i = (i + j) % v.size();    
  }
  return true;
}

int main(void)
{
  int r[] = {
    2,
    7,
    5,
    30,
3    169,
    441,
    1872,
    7632,
    1740,
    93313,
    459901,
    1358657,
    2504881};
  for(int n; cin >> n && n; ){
    cout << r[n-1] << endl;
  }
  return 0;
}

