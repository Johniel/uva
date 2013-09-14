#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

using namespace std;

map<string, int> rem;
set<string> mul;
bool flg;

long long pers(istringstream &iss, long long sum, long long lim, long long tmp, long long last)
{
  string s;
  if(!(iss >> s))return sum + tmp;
  if(s == "negative"){cout << '-' ;return pers(iss, sum, lim, tmp, last);}
  else if(mul.count(s)){
    if(lim > rem[s])
      return pers(iss, sum, rem[s], tmp * rem[s], last);
    else
      return pers(iss, sum + tmp * rem[s], rem[s], 0, last);
  }
  else
    return pers(iss, sum, lim, tmp + rem[s], rem[s]);
}

int main(void)
{
  rem.insert( make_pair( "zero",          0) );
  rem.insert( make_pair( "one",           1) );
  rem.insert( make_pair( "two",           2) );
  rem.insert( make_pair( "three",         3) );
  rem.insert( make_pair( "four",          4) );
  rem.insert( make_pair( "five",          5) );
  rem.insert( make_pair( "six",           6) );
  rem.insert( make_pair( "seven",         7) );
  rem.insert( make_pair( "eight",         8) );
  rem.insert( make_pair( "nine",          9) );
  rem.insert( make_pair( "ten",          10) );
  rem.insert( make_pair( "eleven",       11) );
  rem.insert( make_pair( "twelve",       12) );
  rem.insert( make_pair( "thirteen",     13) );
  rem.insert( make_pair( "fourteen",     14) );
  rem.insert( make_pair( "fifteen",      15) );
  rem.insert( make_pair( "sixteen",      16) );
  rem.insert( make_pair( "seventeen",    17) );
  rem.insert( make_pair( "eighteen",     18) );
  rem.insert( make_pair( "nineteen",     19) );
  rem.insert( make_pair( "twenty",       20) );
  rem.insert( make_pair( "thirty",       30) );
  rem.insert( make_pair( "fourty",       40) );
  rem.insert( make_pair( "fifty",        50) );
  rem.insert( make_pair( "seventy",      70) );
  rem.insert( make_pair( "eighty",       80) );
  rem.insert( make_pair( "ninety",       90) );
  rem.insert( make_pair( "hundred",     100) );
  rem.insert( make_pair( "thousand",   1000) );
  rem.insert( make_pair( "million", 1000000) );
  mul.insert("hundred");
  mul.insert("thousand");
  mul.insert("million");
  while(true){
    string in, s, buff;
    getline(cin, in);
    if(cin.eof())break;
    istringstream iss(in);
    /*
    while(tmp >> s)
      buff = s + ' ' + buff;
    //cout << buff << endl;
    istringstream iss(buff);
    */
    cout << pers(iss, 0, INT_MAX, 0, 0) << endl;
  }
  return 0;
}
