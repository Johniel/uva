#include <iostream>
#include <map>
#include <algorithm>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()


using namespace std;

int main(void)
{
  while(!cin.eof()){    
    map<int, int> M;
    char c;
    string s;
    while(true){
      if(!cin.get(c))return 0;
      if(c == '\'')continue;
      if(c == '-'){
	char tmp;
	cin.get(tmp);
	if(tmp != '\n')cin.unget();
	continue;	
      }
      if(c == ' ' || c == '?' || c == '!' || c == '\n' || c == '.' || c == ','){
	if(s.size()){
	  //cout << s << endl;
	  ++M[s.size()];
	  s = "";
	}
      }
      else if(c == '#')break;
      else s += c;
    }
    FOR(i, M){
      cout << i->first << ' ' << i->second << endl;
    }
    cout << endl;
  }
  return 0;
}
