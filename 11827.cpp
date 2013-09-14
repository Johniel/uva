#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
  return b? gcd(b, a%b) : a;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    getline(cin, s);
    istringstream iss(s);
    vector<int> v;
    for(int n; iss >> n; v.push_back(n));
    int result = -1;
    for(int i=0; i<v.size(); ++i){
      for(int j=i+1; j<v.size(); ++j){
	result = max(result, gcd(max(v[i], v[j]), min(v[i], v[j])));
      }
    }
    cout << result << endl;
  }
  return 0;
}
