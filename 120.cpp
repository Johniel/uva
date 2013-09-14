#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

void output(vector<int> v)
{
  cout << ":::::   " ;
  for(int i=0; i<v.size(); ++i){
    cout << v[i] << ' ';
  }
  cout << endl;
}

bool fin(vector<int> v)
{
  for(int i=0; i+1<v.size(); ++i){
    if(v[i] + 1 != v[i + 1])return false;
  }
  return true;
}

vector<int> solve(vector<int> v)
{
  vector<int> u;
  int mx = v.size();
  if(v.size() == 1){
    u.push_back(0);
    return u;    
  }
  if(v.size() == 2){
    if(v[0] < v[1]);
    else{
      u.push_back(1);
    }
    u.push_back(0);
    return u;    
  }
  for(int i=0; i<mx; ++i){
    int n = mx - i - 1;
    int idx;
    for(int j=0; j<mx; ++j){
      if(n == v[j]){
        idx = j;
        break;
      }
    } 
    /*
    cout << "reverse : " << n << endl;
    output(v);
    */

    if(idx == 0){
      u.push_back(mx - n);
      reverse(v.begin(), v.begin() + n + 1);
      //output(v);
    }
    else{
      u.push_back(mx - idx);
      u.push_back(mx - n);
      
      reverse(v.begin(), v.begin() + idx + 1);
      //output(v);
      reverse(v.begin(), v.begin() + n + 1);
      //output(v);
    }
    if(fin(v))break;
  }
  u.push_back(0);
  return u;
}

int main(void)
{
  string s;
  while(getline(cin, s)){
    int n, m;
    vector<int> v, u;
    istringstream iss(s);
    map<int, int> o;
    cout << s << ' ' << endl;    
    while(iss >> n)v.push_back(n);
    u = v;
    sort(u.begin(), u.end());
    for(int i=0; i<u.size(); ++i){      
      o[u[i]] = i;
    }
    for(int i=0; i<v.size(); ++i){
      v[i] = o[v[i]];
    }    
    vector<int> r = solve(v);
    for(int i=0; i<r.size(); ++i){
      if(i)cout << ' ';
      cout << r[i];
    }
    cout << endl;
  }
  return 0;
}

