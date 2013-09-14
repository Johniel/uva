#include <iostream>

using namespace std;

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  cin.ignore();
  for(; tc--; ){
    string a, b, result;
    getline(cin, a);
    getline(cin, b);
    if(a== b)result = "Yes";
    else{
      bool flg = true;
      for(int i=0; i<a.size(); ++i){
	if(a[i] == ' '){
	  a.erase(a.begin() + i);
	  --i;
	}
      }
      for(int i=0; i<b.size(); ++i){
	if(b[i] == ' '){
	  b.erase(b.begin() + i);
	  --i;
	}
      }
      result = (a== b) ? "Output Format Error" : "Wrong Answer";
    }
    cout << "Case " << ++cnt << ": " << result << endl;
  }
  return 0;
}
