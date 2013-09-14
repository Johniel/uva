#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int C = 30;

  char c[C];
  int num[300];
  fill(c, c + C, '@');
  for(int i='a'; i<='z'; ++i){
    num[i] = i - 'a' + 1;
    c[i - 'a' + 1] = i;
  }  
  num['.'] = 27;
  num['&'] = 0;
  c[27] = '.';
  c[0] = '&';

  int k;
  while(cin >> k && k){    
    string s;
    cin >> s;
    cout << k << " : " << s << endl;    
    int n = s.size();
    for(int i=0; i<s.size(); ++i){
      for(int j=0; j<80; ++j){
	int tmp = ((j % n) - i) % 28;
	while(tmp < 0)tmp += 28;

	if(c[tmp] == s[i]){
	  
	}

	cout << j << " : " << c[tmp] << endl;
      }
      cout << "===========" << endl;
    }
    cout << endl;
    break;
  }
  return 0;
}
