#include <iostream>

using namespace std;

typedef unsigned long long int lli;

int main(void)
{
  for(lli i=6; i<=200; ++i){
    lli a = i *i * i;
    for(lli j=2; j<=200; ++j){
      lli b = j * j * j;
      if(a <= b)continue;
      for(lli k=j + 1; k<=200; ++k){
	lli c = k * k *k;
	if(a <= b + c)continue;
	for(lli l=k + 1; l<=200; ++l){
	  lli d = l * l * l;
	  if(a == b + c + d){
	    cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")" << endl;
	    //j = k = l = 300;
	  }
	}
      }
    }
  }
  return 0;
}
