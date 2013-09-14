#include <iostream>

using namespace std;

bool cmp(string s, string t) 
{
  string a = s + t;
  string b = t + s;
  return a < b;
}

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    string num[n];
    for(int i=0; i<n; ++i){
      cin >> num[i];
    }
    sort(num, num + n, cmp);
    reverse(num, num + n);
    for(int i=0; i<n; ++i){
      cout << num[i];
    }
    cout << endl;
  }
  return 0;
}
