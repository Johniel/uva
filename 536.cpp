#include <iostream>
#include <algorithm>

using namespace std;

bool used['Z' + 1];

void parser(string s, string t, int &i)
{  
  //cout << s << ' ' << t << endl;
  if(t.size() == 1){
    cout << t[0];
    //cout << "# " << t[0] << endl;
    used[t[0]] = true;
  }
  else if(t.size()){
    for(; i<s.size(); ++i){
      if(used[s[i]])continue;
      used[s[i]] = true;
      for(int j=0; j<t.size(); ++j){
	if(s[i] == t[j]){
	  parser(s, t.substr(0, j), i);
	  parser(s, t.substr(j+1, t.size()), i);
	  cout << t[j];
	  //cout << "# " << t[j] << endl;
	  return ;
	}
      }
    }
  }  
  return ;
}

int main(void)
{
  for(string s, t; cin >> s >> t; ){
    fill(used, used + 'Z' + 1, false);
    int i = 0;
    parser(s, t, i);
    cout << endl;
  }
  return 0;
}
