#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    cin.ignore();
    string ind, num;
    getline(cin, ind);
    getline(cin, num);
    istringstream a(ind);
    istringstream b(num);
    //cout << ind << ' ' << num << endl;
    map<int, string> result;
    int i;
    string n;
    while(a >> i && b >> n){
      result.insert(make_pair(i, n));
    }
    for(int i=0+1; i<result.size()+1; i++)
      cout << result[i] << endl;
    if(tc)
      cout << endl;
  }
  return 0;
}
