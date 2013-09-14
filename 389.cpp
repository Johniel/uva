#include <iostream>

using namespace std;

int to10(string s, int n)
{
  reverse(s.begin(), s.end());
  int sum = 0;
  for(int i=0, b = 1; i<s.size(); ++i, b *= n){
    if(isalpha(s[i]))sum += (s[i] - 'A' + 10) * b;
    else sum += (s[i] - '0') * b;
  }
  return sum;
}

string baseCon(int sum, int m)
{
  //cout << sum << ' ' << m << endl;
  string s;
  while(m <= sum){
    int tmp = sum % m;
    sum /= m;
    s += (tmp < 10)? ('0' + tmp) : ('A' + tmp - 10);
  }
  s += (sum < 10)? ('0' + sum) : ('A' + sum - 10);
  while(s.size() < 7)s += ' ';
  reverse(s.begin(), s.end());
  if(s.size() != 7)s = "  ERROR";
  return s;
}

int main(void)
{
  string s;
  int n, m;
  while(cin >> s >> n >> m){
    cout << baseCon(to10(s, n), m) << endl;
  }
  return 0;
}
