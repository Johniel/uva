#include <iostream>
#include <algorithm>

using namespace std;

bool isLeap(int y)
{
  if(y%4 == 0){
    if(y%100 == 0 && y%400 != 0)return false;
    return true;
  }
  return false;
}

int main(void)
{
  int tc, no = 0;
  for(cin >> tc; tc--; ){
    int d1, m1, y1;
    int d2, m2, y2;
    char c;
    cin >> d1 >> c >> m1 >> c >> y1;
    cin >> d2 >> c >> m2 >> c >> y2;
    
    //cout << m1 << c << d1 << c << y1 << endl;
    //cout << m2 << c << d2 << c << y2 << endl;
    
    cout << "Case #" << ++no << ": ";
    if(y1 < y2){
      cout << "Invalid birth date" << endl;
      continue;
    }
    else if(y1 == y2){
      if(m1 < m2){
	cout << "Invalid birth date" << endl;
	continue;
      }
      if(m1 == m2 && d1 < d2){
	cout << "Invalid birth date" << endl;
      continue;
      }
    }
    int cnt = y1 - y2;
    if(m1 < m2){
      --cnt;
    }
    else if(m1 == m2 && d1 < d2){
      --cnt;
    }
    if(cnt <= 130)cout << cnt << endl;
    else cout << "Check birth date" << endl;
  }
  return 0;
}
