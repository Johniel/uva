#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool cmp(const string &a, const string &b)
{
  return a.size() < b.size();
}

int main(void)
{
  string s;
  while(cin >> s){
    map<string, int> cnt;
    vector<string> v;
    for(int i=0; i<s.size(); ++i){
      for(int j=0; j<s.size(); ++j){
        if(j < i)continue;
        string t, u;
        for(int k=i; k<=j; ++k){
          t += s[k];
        }
        if(t.size()){
          u = t;
          reverse(u.begin(), u.end());
          if(u == t){
            if(2 <= ++cnt[t])continue;
            else v.push_back(t);
          }
        }
      }
    }
    //stable_sort(v.begin(), v.end(), cmp);
    cout << "The string \'" << s << "\' contains " << v.size() << " palindromes." << endl;
  }
  return 0;
}
