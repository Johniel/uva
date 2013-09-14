//multiplicaton
#include <iostream>
#include <sstream>

using namespace std;

static const int N = 20000000;

int num[N];
int x[N];

int main(void)
{
  while(true){
    string in;
    getline(cin, in);
    if(cin.eof())break;
    istringstream ss(in);
    int size = 0;
    while(ss >> num[size++]);
    size--;
    getline(cin, in);
    istringstream iss(in);
    bool flg = false;
    x[0] = 1;
    while(iss >> x[1]){
      if(flg)cout << ' ';
      for(int i=1; i<size; i++){
	x[i] = x[i-1] * x[1];
      }
      int sum = 0;
      for(int i=0; i<size; i++){
	sum += x[i] * num[size-1-i];
      }
      printf("%d",sum);
      flg = true;
    }
    cout << endl;
  }
  return 0;
}
