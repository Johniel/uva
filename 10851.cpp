#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
  int n;
  
  cin >> n;
  
  while(n--){
    vector<char>  Hieroglyphs[10]; 
    
    for(int i=0; i<10; i++){
      string s;
      cin >> s;
      if(s[0] == '\n'){
	i--;
	continue;
      }
      Hieroglyphs[i].clear();
      for(int j=0; j<s.size()-1 ;j++)
	Hieroglyphs[i].push_back(s[j]);
    }
    
    //cout << "test";
    
    for(int j=1; j<Hieroglyphs[0].size(); j++){
      int Msg = 0;
      char c;
      for(int i=1; i<9; i++){
	if(Hieroglyphs[i][j] == '\\')
	  Msg += (int)pow(2.0,i-1);
      }
      c = (char)Msg;
      cout << c ;
    }
    cout << endl;
  }

  return 0;
}
