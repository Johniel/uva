#include <iostream>
#include <algorithm>
#include <string>

#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

static const int MLEN = 10000;

int main(void)
{
  int tc = 0;
  while(true){
    int m, n;
    cin >> m;
    if(cin.eof())return 0;
    cin >> n;
    //if(tc)cout << endl;
    string key[m], str[n], data[n];
    REP(i, m)cin >> key[i];
    REP(i, m)REP(j, key[i].size())key[i][j] = toupper(key[i][j]);
    cin.ignore();
    REP(i, n)getline(cin, str[i]);
    REP(i, n)REP(j, str[i].size())
      data[i] += str[i][j];
    int cnt[n];
    fill(cnt, cnt + n, 0);
    REP(i, n){
      char *cp = (char*)data[i].c_str();
      int num = 0;
      REP(j, str[i].size()){
	if( !isalpha(*(cp + j)) ){
	  *(cp + j) = '\0';
	  num++;
	}
	else *(cp + j) = toupper( *(cp + j) );
      }
      cp = (char*)data[i].c_str();
      REP(j, num){
	REP(k, m){
	  if( strcmp(cp, key[k].c_str()) == 0 )cnt[i]++;
	}
	cp += strlen(cp) + 1;
      }
    }
    int re = INT_MIN;
    REP(i, n)re = max(re, cnt[i]);
    cout << "Excuse Set #" << ++tc << endl;
    REP(i, n)if(cnt[i] == re)
      cout << str[i] << endl;
    //REP(i, n)cout << cnt[i] << ' ' ;cout << endl;
    cout << endl;
  }
  return 0;
}
