// + 10302 
// - 
// / 10302
// * 10302
// <
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <complex>
#include <cstdlib>
#include <climits>
#include <utility>
#include <sstream>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const static int LIMIT = 10000;
const static int LANGE = 4;

#define LESS -1
#define EQUAL 0
#define GREATER 1
#define FRONT "%d"
#define FORMAT "%04d"

class BigInt{
public: 
  bool negative;
  vector<int> value;

  BigInt(void){
    negative = false;
    value.resize(1);
    value[0] = 0;
  }
  BigInt(vector<int> in, bool sign){
    negative = sign;
    value = in;
  }
  BigInt(string in){
    negative = false;
    if(in[0] == '-'){
      negative = true;
      in.erase(in.begin());
    }    
    while (in.size()%LANGE != 0 )
      in.insert(in.begin(),1,'0');
    for(int i=in.size()-LANGE; i>=0; i-=LANGE)
      value.push_back(atoi(in.substr(i, LANGE).c_str()));
    regulation();
  }
  BigInt operator + (BigInt in){
    if(sign() == in.sign())
      return add(*this, in, sign());
    else if(compare(in, true) == LESS)
      return sub(in, *this, in.sign());
    else
      return sub(*this, in, sign());
  }
  BigInt operator * (BigInt in){
    return mul(*this, in, sign() != in.sign());
  }
  BigInt operator - (BigInt in){
    if(sign() != in.sign())
      return add(*this, in, sign());
    else if(compare(in, true) == LESS)
      return sub(*this, in, sign());
    else
      return sub(in, *this, !in.sign());
  }
  BigInt operator / (BigInt in){
    return div(*this, in, (sign() != in.sign()));
  } 
  bool operator == (BigInt &in){
    return compare(in, false) == EQUAL;
  }
  bool operator < (BigInt &in){
    return  compare(in, false) == LESS;
  }
  bool operator > (BigInt &in){
    return compare(in, false) == GREATER;
  }
  bool operator >= (BigInt &in){
    return (*this > in) || (*this == in);
  }
  bool operator <= (BigInt &in){
    return (*this < in) || (*this == in);
  }
  int& operator [] (int n) {
    return value[n];
  }
  string toString(void){
    char buffer[LANGE+1];
    string result;
    
    if (negative == true) result = "-";
    sprintf(buffer, FRONT, value.back()), result +=buffer;
    
    for(int i=value.size()-2; i>=0; i--)
      sprintf(buffer, FORMAT, value[i]), result += buffer;
    return result;
  }
  int size(void){
    return value.size();
  }
  void resize(int n){
    value.resize(n);
  }
  bool sign(void){
    return negative;
  }
  void test(void){
    if(negative)cout << '-';
    cout << value.back();
    for(int i=value.size()-1-1; i>=0; i--)
      printf("%04d",value[i]);
  }
  void regulation(void) {
    while(value.back() == 0 && value.size() > 1)
      value.pop_back();
    if(value.size() == 1 && value[0] == 0)
      negative = false;    
  }
  int compare(BigInt &in, bool abs){
    if(sign() != in.sign() && !abs)
      return sign()? GREATER : LESS;
    if(size() != in.size())
      return (size() > in.size())? GREATER : LESS;
    for(int i=in.size()-1; i>=0; i--){
      if(value[i] == in.value[i])continue;
      return (value[i] > in.value[i])? GREATER : LESS;
    }
    return EQUAL;
  }
  BigInt add(BigInt a, BigInt b, bool sign){
    BigInt result = BigInt(a.value, sign);
    result.value.resize(max(a.size(), b.size()) + 1, 0);
    REP(i, result.size()-1){
      if(i < b.size())
	result[i] += b[i];
      if(result[i]/LIMIT != 0){
	result[i+1]++;
	result[i] %= LIMIT;
      }
    }
    result.regulation();
    return result;
  }
  BigInt sub(BigInt a, BigInt b, bool sign){
    BigInt result = BigInt(a.value, sign);
    result.value.resize(a.size(), 0 );
    int borrow = 0;
    REP(i, result.size()){
      if(i < b.size())result[i] -= b[i] + borrow;
      else result[i] -= borrow;
      if(result[i] >= 0)borrow = 0;
      else borrow = 1,result[i] += LIMIT;
    }
    result.regulation();
    return result;
  }
  BigInt mul(BigInt a, BigInt b, bool sign){
    BigInt result;
    result.value.resize(a.size() + b.size() + 1, 0);
    REP(i, a.size())REP(j, b.size()){
      int carry = a[i] * b[j];
      for(int k=i+j; ; k++){
	result[k] += carry;
	if(result[k] < LANGE)break;
	else{
	  carry = result[k] / LIMIT;
	  result[k] %= LIMIT;
	}
      }
    }
    result.negative = sign;
    result.regulation();
    return result;
  }
  BigInt div(BigInt a, BigInt b, bool sign){
    BigInt sum("0");
    REP(i, b.size()){
      vector<int> v;
      BigInt c = a;
      for(int j=(int)c.size()-1; 0<=j; --j){
	v.push_back(c[j] / b[i]);
	if(j)c[j - 1] += c[j] % b[i] * LIMIT;
      }
      reverse(ALL(v));
      BigInt tmp(v, false);
      sum = sum + tmp;
    }    
    sum.negative = sign;
    return sum;
  }
};

string makeString(int n)
{
  string s;
  while(10 <= n){
    s += (char)('0' + n % 10);
    n /= 10;
  }    
  s += (char)('0' + n);
  reverse(ALL(s));
  return s;
}

int main(void) 
{     
  string s;
  BigInt one("1"), two("2");
  while(getline(cin, s)){
    BigInt b(s);
    b = (b + one) * b;
    b = b / two;
    b = b * b;
    cout << b.toString() << endl;
  }
  return 0;
}
