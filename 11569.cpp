#include <iostream>
#include <algorithm>

using namespace std;

void dp(string s)
{
  static const int L = 250 + 1, C = 'Z' - 'A' + 2;  
  static int t[L][L][C];
  int n[L];
  fill(&t[0][0][0], &t[L-1][L][C], 0);
  t[0][0][0] = 1;

  for(int i=0; i<s.size(); ++i){
    n[i] = s[i] - 'A' + 1;
  }

  //cout << s << endl;

  for(int in=0; in<s.size(); ++in){
    for(int out=0; out<s.size(); ++out){
      for(int c=0; c<C; ++c){
	if(t[in][out][c]){
	  t[in+1][out][c] += t[in][out][c];
	  if(5 * c <= 4 * n[in]){
	    t[in+1][out+1][n[in]] += t[in][out][c];
	  }
	}
      }
    }
  }
  /*
  for(int in=0; in<s.size()+1; ++in){
    cout << "  ";for(int c=1; c<C; ++c)cout << (char)('A' - 1 + c) << ' ' ;cout << endl;
    for(int out=0; out<s.size()+1; ++out){
      for(int c=0; c<C; ++c){
	cout << t[in][out][c] << ' ' ;
      }
      cout << endl;
    }
    cout << endl;
  }
  cout << endl;
  */
  for(int out=s.size()+1; out--;){
    int cnt = 0;
    for(int c=0; c<C; ++c){
      cnt += t[(int)s.size()][out][c];
    }
    if(cnt){
      cout << out << ' ' << cnt << endl;
      return ;
    }    
  }

  cout << *max_element(&t[0][0][0], &t[L-1][L][C]) << endl;
  return ;
}

int main(void)
{
  int tc;
  for(cin >> tc, cin.ignore(); tc--; ){
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());
    for(int i=0; i<s.size(); ++i){
      if(i && s[i] == s[i-1]){
	s.erase(s.begin() + i--);
      }
      if(isalpha(s[i]));
      else{
	s.erase(s.begin() + i--);
      }
    }
    dp(s);
  }
  return 0;
}
