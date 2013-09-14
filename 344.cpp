#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

char* roman( const char* pbuf )
{
  const char* tbl[ ][ 10 ] = {
    { "", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix", },
    { "", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc", },
    { "", "c", "cc", "ccc", "cd", "d", "dc", "dcc", "dccc", "cm", },
    { "", "m", "mm", "mmm", "mmmm", "", "", "", "", "", },
  };
	
	int len;
	static char szRoman[100] = "";
	char buf[10];
	int i;
	
	
	if( !pbuf ){
		return NULL;
	}
	i = atoi( pbuf );
	
	if( i >= 5000 || 0 >= i ){
		return NULL;
	}
	sprintf( buf, "%d", i );

	szRoman[ 0 ] = '\0';
	
	len = strlen( buf );
	
	i = 0;
	switch( len ){
		default:
			return NULL;
		case 4:	// down through
			strcat( szRoman, tbl[ len - i - 1 ][ (buf[ i ] - '0') ] );
			i++;
		case 3:	// down through
			strcat( szRoman, tbl[ len - i - 1 ][ (buf[ i ] - '0') ] );
			i++;
		case 2:	// down through
			strcat( szRoman, tbl[ len - i - 1 ][ (buf[ i ] - '0') ] );
			i++;
		case 1:
			strcat( szRoman, tbl[ len - i - 1 ][ (buf[ i ] - '0') ] );
	}
	
	return szRoman;

}

#include <map>

int main(void)
{
  static char buff[20];
  map<char, int> cnt[100];
  cnt[1]['i'] = 1;
  for(int i=2; i<100; ++i){
    cnt[i] = cnt[i-1];    
    sprintf((char*)buff, "%d", i);
    string s(roman(buff));
    for(int j=0; j<s.size(); ++j){
      ++cnt[i][s[j]];
    }
  }
  int n;
  while(cin >> n && n){
    cout << n << ": " 
         << cnt[n]['i'] << " i, " 
         << cnt[n]['v'] << " v, "
         << cnt[n]['x'] << " x, "
         << cnt[n]['l'] << " l, "
         << cnt[n]['c'] << " c" << endl;
  }
  return 0;
}
