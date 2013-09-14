#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Book{
  string t, a;
  Book(string _t, string _a) : t(_t), a(_a) {}
};

bool operator < (const Book &a, const Book &b)
{
  if(a.a != b.a)return a.a < b.a;
  return a.t < b.t;
}

pair<string, string> sep(string s)
{
  string t, r;
  int cnt = 0;
  for(int i=0; i<s.size(); ++i){
    if(cnt < 2)t += s[i];
    else r += s[i];    
    if(s[i] == '\"')++cnt;
    if(cnt == 2){
      i += 4;
      ++cnt;
    }
  }
  return make_pair(t, r);
}

int main(void)
{
  bool flg = true;
  map<string, string> t2a;
  set<Book> rack, buff;
  string s, t;

  while(true){
    getline(cin, s);
    if(s == "END")break;
    pair<string, string> ta = sep(s);
    rack.insert(Book(ta.first, ta.second));
    t2a[ta.first] = ta.second;
  }

  while(true){
    char c;
    cin >> s;
    if(s == "END")break;
    if(s != "SHELVE"){
      cin.get(c);
      if(!getline(cin, t))return 0;
    }
    if(s == "BORROW"){
      rack.erase(Book(t, t2a[t]));
    }
    else if(s == "RETURN"){
      buff.insert(Book(t, t2a[t]));
    }
    else if(s == "SHELVE"){
      set<Book>::iterator itr = buff.begin();
      for(; itr != buff.end(); ++itr){
	rack.insert(*itr);
	set<Book>::iterator jtr = rack.find(*itr);
	cout << "Put " << itr->t;
	if(jtr == rack.begin())cout << " first" << endl;
	else cout << " after " << (--jtr)->t << endl;
      }
      buff.clear();
      cout << "END" << endl;
    }
  }
  return 0;
}
