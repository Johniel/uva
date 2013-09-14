#include <iostream>
#include <algorithm>

using namespace std;

const int S = 100 + 5;
string s[S];

inline
bool cmp(const string &a, const string &b)
{
  int lim = min(a.size(), b.size());  
  for(int i=0; i<lim; ++i){
    if(a[i] != b[i])return a[i] > b[i];
  }
  return a.size() < b.size();
  if(a.size() != b.size()) a.size() < b.size();
  return a < b;
}

int calc(string s[], int size)
{
  int sum = 0;
  for(int i=1; i<size; ++i){
    string t = s[i - 1] + "@";
    string u = s[i] + "@";    
    for(int j=0; ; ++j){
      if(t[j] != u[j]){
        sum += (int)u.size() - j - 1;
        break;
      }
      if(t[j] == '@' || u[j] == '@')break;
    }
    //cout << t << ' ' << u << " : " << sum << endl;
  }
  return sum;
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> s[i];
    }
    s[n++] = "";
    sort(s, s + n, cmp);
    cout << calc(s, n) << endl;
    for(int i=1; i<n; ++i){
      cout << s[i] << endl;
    }
  }  
  return 0;
}
