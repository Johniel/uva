#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

const int A = 2;
string a[A] = {"a", "the"};

const int N = 8;
string n[N] = {"tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"};

const int V = 4;
string v[V] = {"hate", "love", "know", "like"};

bool article(string s)
{
  return s == a[0] || s == a[1];
}

bool noun(string s)
{
  return binary_search(n, n + N, s);
}

bool verb(string s)
{
  int size = s.size();
  if(s[size-1] == 's')return verb(s.substr(0, size-1));
  return binary_search(v, v + V, s);
}

bool actor(string s)
{  
  int i = s.rfind(" ");
  if(i == string::npos)return noun(s);
  return article(s.substr(0, i)) && noun(s.substr(i + 1));
}

bool active_list(string s)
{
  int i = s.rfind(" and ");
  if(i == string::npos)return actor(s);
  return  active_list(s.substr(0, i)) && actor(s.substr(i + 5));
}

bool action(string s)
{
  int cnt = 0, idx;
  istringstream iss(s);
  vector<string> v;
  string t;
  while(iss >> t)v.push_back(t);
  if(v.size() < 3)return false;
  for(int i=0; i<v.size(); ++i){
    if(verb(v[i])){
      ++cnt;
      idx = i;
    }    
  }
  if(cnt != 1)return false; 
  string p, q;
  for(int i=0; i<idx; ++i){
    if(p.size())p += " ";
    p += v[i];
  }
  for(int i=idx+1; i<v.size(); ++i){
    if(q.size())q += " ";
    q += v[i];
  }
  return active_list(p) && active_list(q);
}

bool statement(string s)
{
  int i = s.rfind(" , ");
  if(i == string::npos)return action(s);
  return statement(s.substr(0, i)) && action(s.substr(i + 3));
}

set<char> valid;

void init(void)
{
  valid.clear();
  for(int i=0; i<A; ++i){
    for(int j=0; j<a[i].size(); ++j){
      valid.insert(a[i][j]);
    }
  }
  for(int i=0; i<N; ++i){
    for(int j=0; j<n[i].size(); ++j){
      valid.insert(n[i][j]);
    }
  }
  for(int i=0; i<V; ++i){
    for(int j=0; j<v[i].size(); ++j){
      valid.insert(v[i][j]);
    }
  }
  valid.insert('s');
  valid.insert(',');
  valid.insert(' ');
  sort(a, a + A);
  sort(n, n + N);
  sort(v, v + V);
  return ;
}

string reg(string s)
{
  string t, u;
  for(int i=0; i<s.size(); ++i){
    if(valid.count(s[i]) == 0)return "";
  }
  istringstream iss(s);
  while(iss >> u){
    if(t.size())t += " ";
    t += u;
  }
  return t;
}

int main(void)
{
  const string T = "YES I WILL";
  const string F = "NO I WON'T";
  string s, t;
  init();
  while(getline(cin, s)){
    t = reg(s);
    cout << (t.size() && statement(t) ? T : F) << endl;
  }
  return 0;
}
