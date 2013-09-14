#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  while(1){
    int n,m;
    cin >> n;
    if( n == 0 )break;
    vector<int> num;
    for(int i=0; i<n; i++){
      cin >> m;
      if( m != 0 )num.push_back(m);
    }
    if( num.size() == 0 )cout << '0' << endl;
    else{
      for(int i=0; i<num.size(); i++){
	cout << num[i] ;
	if(i != num.size()-1)cout << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
