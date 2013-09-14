#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
  if(a.second < b.second)return true;
  else if(a.second > b.second)return false;
  if(a.first > b.first)return true;
  else return false;
}

int main(void)
{
  bool flg = false;
  while(true){
    string s;
    getline(cin, s);
    if(cin.eof())break; 
    if(flg)cout << endl;
    else flg = true;
    pair<int, int> cnt[CHAR_MAX];
    fill(cnt, cnt + CHAR_MAX, make_pair(0, 0));
    for(int i=0; i<CHAR_MAX; i++)cnt[i].first = i;
    for(int i=0; i<s.size(); i++)cnt[s[i]].second++;
    sort(cnt, cnt + CHAR_MAX, cmp);
    for(int i=0; i<CHAR_MAX; i++)
      if(cnt[i].second)cout << cnt[i].first << ' ' << cnt[i].second << endl;
  }
  return 0;
}
