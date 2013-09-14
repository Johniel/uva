#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int SIZE = CHAR_MAX;

class str{
public:
  int cnt[SIZE];
  string s;
  str(void){
    fill(cnt, cnt + SIZE, 0);
  }
  bool operator == (str& s){
    REP(i, SIZE)if(cnt[i] != s.cnt[i])return false;
    return true;
  }
  char operator [] (int i){
    return s[i];
  }
  int size(void){
    return s.size();
  }
};

static const int M = 100 + 1;
str data[M];

bool cmp(str a, str b)
{
  return a.s < b.s ;
  REP(i, a.size()){
    if(a[i] ==  ' ')continue;
    REP(j, b.size()){
      if(b[j] ==  ' ')continue;
      if(toupper(a[i]) == toupper(b[i]))
        if(a[i] < b[i])return false;
      if(toupper(a[i]) != toupper(b[i]))
        if(a[i] < b[i])return false;
    }
  }
  return true;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  while(tc--){
    int p = 0;
    REP(i, M)data[i] = str();
    while(true){
      string in;
      getline(cin, in);
      if(in.size() == 0)break;
      REP(i, in.size())data[p].s += in[i];
      REP(i, in.size())data[p].cnt[in[i]]++;
      data[p].cnt[' '] = 0;
      p++;
    }
    sort(data, data + p, cmp);
    REP(i, p-1)for(int j=i+1; j<p; j++){
      if(data[i] == data[j])cout << data[i].s << " = " << data[j].s << endl;
    }
    if(tc)cout << endl;
  }
  return 0;
}
