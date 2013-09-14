#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
  if(a.second != b.second)return a.second < b.second;
  return a.first < b.first;
}

int main(void)
{
  int tc;
  cin >> tc;
  //cin.ignore();
  for(; tc--; ){
    cin.ignore();
    string title;
    int m, n, b;
    getline(cin, title);
    cin >> m >> n >> b;
    map<string, int> price;
    pair<string, int> recipe[n];
    for(int i=0; i<m; ++i){
      string s;
      int p;
      cin >> s >> p;
      price[s] = p;
    }

    for(int i=0; i<n; ++i){
      string s;
      int k, sum = 0;
      cin.ignore();
      getline(cin, s);
      cin >> k; 
      
      //cout << s << ' ' << k << endl;

      for(int j=0; j<k; ++j){	
	string t;
	int req;
	cin >> t >> req;
	sum += price[t] * req;
      }
      recipe[i] = make_pair(s, sum);
    }

    for(int i=0; i<title.size(); ++i){
      cout << (char)toupper(title[i]) ;
    }
    cout << endl;

    int sum = 0;
    sort(recipe, recipe + n, cmp);
    for(int i=0; i<n; ++i){
      //sum += recipe[i].second;
      if(b < recipe[i].second){
	if(i == 0)cout << "Too expensive!" << endl;
	break;
      }
      cout <<  recipe[i].first << endl;
    }
    cout << endl;
  }
  return 0;
}
