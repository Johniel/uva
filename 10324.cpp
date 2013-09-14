#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 1000000 + 1;
  int sum[N];
  string s;
  int tc = 0;
  while( cin >> s ){
    const int size = s.size();
    sum[0] = s[0] - '0';
    for(int i=1; i<size; ++i){
      sum[i] = s[i] != s[i-1];
      sum[i] += sum[i-1];
    }
    int n;
    cin >> n;
    cout << "Case " << ++tc << ":" << endl; 
    while(n--){
      int begin, end;
      cin >> begin >> end;
      cout << (sum[begin] == sum[end] ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
