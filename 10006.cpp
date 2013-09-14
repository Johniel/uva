#include <iostream>
#include <algorithm>

using namespace std;

using namespace std;

int main(void)
{
  int n[] =  {561,
              1105,
              1729,
              2465,
              2821,
              6601,
              8911,
              10585,
              15841,
              29341,
              41041,
              46657,
              52633,
              62745,
              63973};
  const int size = sizeof( n ) / sizeof(int) ;
  int m;
  sort( n, n + size );
  while( cin >> m && m ){
    if( binary_search(n, n + size, m) ){
      cout << "The number " << m << " is a Carmichael number." << endl;
    }
    else{
      cout << m << " is normal." << endl;
    }
  }
  return 0;
}

