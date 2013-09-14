#include <iostream>
#include <algorithm>

using namespace std;

static const int N = 200000;

int num[N];
bool used[N];
bool visited[N];

void check(int ind)
{
  if(num[ind] >= 0 && used[ind] == true){
    visited[ind] = true;
    check(ind*2);
    check(ind*2+1);
  }
}

int main(void)
{
  while(true){
    fill(num, num + N, -1);
    fill(visited, visited + N , false);
    fill(used, used + N, false);
    while(true){
      string in;
      cin >> in;
      if(cin.eof() == true)return 0;
      if(in == "()")
	break;
      string tmp;
      int ind = 1;
      for(int i=0; i<in.size(); i++){
        if(isdigit(in[i]))tmp += in[i];
        if(in[i] == 'L')ind *= 2;
        if(in[i] == 'R')ind = 2 *ind + 1;
      }
      if(tmp.size() == 0){
	visited[0] = true;
	continue;
      }
      int n = atoi(tmp.c_str());
      if(num[ind] == -1)num[ind] = n;
      else num[ind] = -2;
      used[ind] = true;
    }
    check(1);
    bool flg = true;
    int cnt = 0;
    for(int i=0; i<N && flg; i++){
      if(visited[i] != used[i])flg = false;
      if(visited[i]
	 && i != 0
	 )cnt++;
    }
    if(flg && cnt){
      for(int i=1; i<N; i++){
	//cout << "cnt : " << cnt << endl;
        if(num[i] >= 0){
	  //cout << "cnt : " << cnt << endl;
          cout << num[i];// << ' ';
          if(cnt>1){cout << ' ';cnt--;}
        }
      }
      cout << endl;
    }
    else cout << "not complete" << endl;
  }
  return 0;
}
