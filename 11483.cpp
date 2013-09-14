#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc = 0;
  for(int n; cin >> n; ){
    if(n == 0)break;
    cout << "Case " << ++tc << ":" << endl; 
    cout << "#include<string.h>" << endl;
    cout << "#include<stdio.h>" << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;
    for(int i=0; i<n; ++i){
      string s;
      getline(cin, s);
      if(s.size() == 0){
	--i;
      }
      else{
	for(int i=0; i<s.size(); ++i){
	  if(s[i] == '\''){
	    s.insert(s.begin() + i, '\\');
	    ++i;
	  }
	  else if(s[i] == '\"'){
	    s.insert(s.begin() + i, '\\');
	    ++i;
	  }
	  else if(s[i] == '\\'){
	    s.insert(s.begin() + i, '\\');
	    ++i;
	  }
	}
	cout << "printf(\"" << s << "\\n\");" << endl;
      }
    }
    cout << "printf(\"\\n\");" << endl;
    cout << "return 0;" << endl;
    cout << "}" << endl;
  }
  return 0;
}
