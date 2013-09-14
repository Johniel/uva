#include <iostream>
#include <set>

using namespace std;

int main(void)
{
  while(true){
    string s, t;
    set<int> S;
    cin >> s;
    int size = s.size();
    if(s == "0")break;
    while(true){
      int n = atoi(s.c_str());
      //cout << S.size() << " : n : " << n ;//<< endl;
      if(S.count(n)){
	cout << S.size() << endl;
	break;
      }
      else{
	S.insert(n);
	n *= n;
	while(10 <= n){
	  t = (char)('0' + (n % 10)) + t;
	  n /= 10;
	}
	t = (char)('0' + n) + t;
	while(t.size() < 2 * size){
	  t = '0' + t;
	  //t = t + '0';
	}
	int tmp = ((int)t.size() - size + 1) / 2;
	s = t.substr(tmp, size);
	//cout << " : t : " << t << endl;
	t = "";
      }
    }
  }
  return 0;
}
