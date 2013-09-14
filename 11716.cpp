#include <iostream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    getline(cin, s);
    int l;
    for(l = 0; l * l < s.size(); ++l);
    if(l * l != s.size()){
      cout << "INVALID" << endl;
      continue;
    }
    char t[l][l];
    fill(&t[0][0], &t[l-1][l], '\0');
    int cnt = 0;
    for(int i=0; i<l; ++i){
      for(int j=0; j<l; ++j){
	t[i][j] = s[cnt++];
      }
    }
    
    for(int i=0; i<l; ++i){
      for(int j=0; j<l; ++j){
	if(t[j][i] == '\0')break;
	cout << t[j][i];
      }
    }
    cout << endl;
  }
  return 0;
}
