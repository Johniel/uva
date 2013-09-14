#include <iostream>

using namespace std;

int main(void)
{
  int n, m, cnt = 0;
  while(cin >> n >> m && (n | m)){
    cin.ignore();
    string t;
    for(int i=0; i<n; ++i)getline(cin, t);
    string name, _name;
    double value, _value;
    int item, _item = -1;    
    for(int i=0; i<m; ++i){
      getline(cin, name);
      cin >> value >> item;
      cin.ignore();
      for(int j=0; j<item; ++j)getline(cin, t);
      if(item > _item){
        _item = item; _name = name; _value = value;
      }
      else if(item == _item && _value > value){
        _item = item; _name = name; _value = value;
      }
    }
    if(cnt)cout << endl;
    cout << "RFP #" << ++cnt << endl;
    cout << _name << endl;
  }
  return 0;
}  
