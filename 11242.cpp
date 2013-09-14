#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  while(true){
    int n, m;
    cin >> n;
    if( n == 0 )
      break;
    cin >> m;
    int fmin = INT_MAX, fmax = INT_MIN, rmin = INT_MAX, rmax = INT_MIN;
    for(int i=0; i<n; i++){
      int in;
      cin >> in;
      fmax = max(in, fmax);
      fmin = min(in, fmin);
    }
    for(int j=0; j<m; j++){
      int in;
      cin >> in;
      rmax = max(in, rmax);
      rmin = min(in, rmin);
    }
    cout << fmax << ' ' << rmax << ' ' << fmin << ' ' << rmin << endl;
    cout << (fmin*rmin) << ' ' << fmax*rmax << endl;
    printf("%.2f\n",(double)fmax/((double)(fmax/rmin)*rmin));
  }
  return 0;
}
