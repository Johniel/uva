#include <iostream>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; i++)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == -1)
      break;
    string a, s;
    cin >> a >> s ;
    int r = 0;
    REP(i, s.size()){
      int tmp = 0;
      REP(j, a.size()){
	if(s[i] == a[j]){
	  a.erase(j, 1);
	  j--;
	  tmp++;
	}
      }
      if(tmp)r++;
      for(int j=i+1; j<s.size(); j++){
	if(s[i] == s[j]){
	  s.erase(j, 1);
	  j--;
	}
      }
    }
    cout << endl;
    if(r >= 7)
      cout << "You lose." << endl;
    else if(a.size() == 0)
      cout << "You win." << endl;
    else 
      cout << "You chickened out." << endl;
  }
  return 0;
}
