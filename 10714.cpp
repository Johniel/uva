#include <iostream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    cin >> n >> m;
    int pos[m];
    int fastest = -1;
    int lowest = -1;
    for(int i=0; i<m; ++i){
      cin >> pos[i];
      fastest = max(fastest, min(pos[i], n - pos[i]));
      lowest = max(lowest, max(pos[i], n - pos[i]));
    }
    cout << fastest << ' ' << lowest << endl;
  }
  return 0;
}
