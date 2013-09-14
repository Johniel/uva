#include<iostream>

using namespace std;

int main(void)
{
  int cnt[100];  
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    cin >> n >> m;
    fill(cnt, cnt + 100, 0);
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        int no;
        cin >> no;
        if(no == 1)cnt[j]++;
      }
    }
    unsigned long long int r = 1;
    for(int i=0; i<n; i++){
      if(1 < cnt[i]){
        r *= (unsigned long long int)cnt[i];
      }
    }
    cout << r << endl;
  }  
  return 0;   
}
