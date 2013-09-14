#include <iostream>
#include <algorithm>

using namespace std;

bool sim(double dist, double pos[], int acc, int home)
{
 double last = pos[0] + dist;
 --acc;

 for(int i=1; i<home && acc; ++i){
   if( dist < pos[i] - last ){
     last = pos[i] + dist;
     --acc;
   }
 }
 return max( dist, pos[home-1] - last ) <= dist;
}

#include <cstdio>
int main(void)
{
 int tc;
 cin >> tc;
 while( tc-- ){
   int n, m;
   cin >> n >> m;
   double pos[m];
   for(int i=0; i<m; ++i){
     cin >> pos[i];
   }
   sort( pos, pos + m );

   int s = 0;
   int b = 1000000000;
   while( s + 1 < b ){
     int c = (s + b) / 2;

     bool flg = sim( c / 100.0, pos, n, m );

     //if( c == 10 )cout << flg << endl;

     if( !flg )s = c;
     else b = c;
   }

   //cout << b / 100.0 << endl;
   printf("%.1lf\n", b / 100.0);
 }
 return 0;
}
