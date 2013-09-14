#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v;
int n, m;
int cnt;
bool fin;

void output(string s)
{
  int tmp = s.size();
  for(int i=4; i<s.size(); i+=5){
    s.insert(s.begin() + i, i == 79 ? '\n' : ' ');
  }
  cout << s << endl;
  cout << tmp << endl;
  return ;
}

void rec(string s)
{
  if(cnt == n){
    output(s);
    return ;
  }
  for(int i=0; i<m; ++i){
    string t = s + (char)('A' + i);
    bool flg = true;
    int size = t.size();
    if(fin)return ;
    for(int j=1; j<=size/2 && flg; ++j){
      string a = t.substr(size-j, j);
      string b = t.substr(size-j-j, j);
      if(a == b)flg = false;
    }
    if(!flg)continue;
    if(cnt++ == n)return ;
    rec(t);
    if(cnt == n)return ;
  }
  return ;
}

int main(void)
{
  while(cin >> n >> m && (n | m)){
    cnt = 0;
    rec("");
  }
  return 0;
}
