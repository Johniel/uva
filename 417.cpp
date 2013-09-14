#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
  char s[6];
  int no = 0;
  fill(s, s + 6, '\0');
  map<string, int> M;

  for(char c = 'a'; c <= 'z'; ++c){
    s[0] = c;
    M[string(s)] = ++no;
  }

  for(char c = 'a'; c <= 'z'; ++c){
    for(char d = c+1; d <= 'z'; ++d){
      s[0] = c;
      s[1] = d;
      M[string(s)] = ++no;
    }
  }

  for(char c = 'a'; c <= 'z'; ++c){
    for(char d = c+1; d <= 'z'; ++d){
      for(char e = d+1; e <= 'z'; ++e){
      s[0] = c;
      s[1] = d;
      s[2] = e;
      string str = string(s);
      if(str == "aab" || str == "are" || str == "cat"){
	continue;
      }
      M[str] = ++no;
      }
    }
  }
  
  for(char c = 'a'; c <= 'z'; ++c){
    for(char d = c+1; d <= 'z'; ++d){
      for(char e = d+1; e <= 'z'; ++e){
	for(char f = e+1; f <= 'z'; ++f){
	  s[0] = c;
	  s[1] = d;
	  s[2] = e; 
	  s[3] = f;
	  string str = string(s);
	  M[str] = ++no;
	}
      }
    }
  }

    
  for(char c = 'a'; c <= 'z'; ++c){
    for(char d = c+1; d <= 'z'; ++d){
      for(char e = d+1; e <= 'z'; ++e){
	for(char f = e+1; f <= 'z'; ++f){
	  for(char g = f+1; g <= 'z'; ++g){
	    s[0] = c;
	    s[1] = d;
	    s[2] = e; 
	    s[3] = f;
	    s[4] = g;
	    string str = string(s);
	    M[str] = ++no;
	  }
	}
      }
    }
  }


  for(string t; cin >> t; ){
    cout << M[t] << endl;
  }

  return 0;
}
