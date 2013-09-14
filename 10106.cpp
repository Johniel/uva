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

#define REP(i, n) for(int i=0; i<(int)n; i++)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const static int LIMIT = 10000;
const static int LANGE = 4;

#define LESS -1
#define EQUAL 0
#define GREATER 1
#define FRONT "%d"
#define FORMAT "%04d"

class BigInt {
public:
  BigInt(void){
    negative = false;
    value.resize(1);
    value[0] = 0;
  }
  BigInt(vector<int> &in, bool sign){
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
  BigInt operator + (BigInt &in){
    if(sign() == in.sign())
      return add(*this, in, sign());
    else if(compare(in, true) == LESS)
      return sub(in, *this, in.sign());
    else
      return sub(*this, in, sign());
  }
  BigInt operator * (BigInt &in){
    return mul(*this, in, sign() != in.sign());
  }
  BigInt operator - (BigInt &in){
    if(sign() != in.sign())
      return add(*this, in, sign());
    else if(compare(in, true) == LESS)
      return sub(*this, in, sign());
    else
      return sub(in, *this, !in.sign());
  }
  BigInt operator / (BigInt &in){
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
  int &operator [] (int n) {
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
    if(negative)
      cout << '-';
    cout << value.back();
    for(int i=value.size()-1-1; i>=0; i--)
      printf("%04d",value[i]);
  }
private:
  bool negative;
  vector<int> value;

  void regulation(void) {
    while(value.back() == 0 && value.size() > 1)
      value.pop_back();
    if(value.size() == 1 && value[0] == 0)
      negative = false;
  }
  int compare(BigInt &in, bool abs){
    if(sign() != in.sign() && !abs)
      return (sign())? GREATER : LESS;
    if(size() != in.size())
      return (size() > in.size())? GREATER : LESS;
    for(int i=in.size()-1; i>=0; i--){
      if(value[i] == in.value[i])continue;
      return (value[i] > in.value[i])? GREATER : LESS;
    }
    return EQUAL;
  }
  BigInt add(BigInt &a, BigInt &b, bool sign){
    BigInt result = BigInt(a.value, sign);
    result.value.resize( max( a.size(), b.size() )+1, 0 );
    for(int i=0; i<(int)result.size()-1; i++){
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
  BigInt mul(BigInt &a, BigInt &b, bool sign){
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
  BigInt sub(BigInt &a, BigInt &b, bool sign){
    BigInt result = BigInt(a.value, sign);
    result.value.resize(a.size(), 0 );
    int borrow = 0;
    for(int i=0; i<result.size(); i++){
      if(i < b.size())result[i] -= b[i] + borrow;
      else result[i] -= borrow;
      if(result[i] >= 0)borrow = 0;
      else borrow = 1,result[i] += LIMIT;
    }
    result.regulation();
    return result;
  }
  BigInt div(BigInt &a, BigInt &b, bool sign){
    BigInt result = BigInt(a.value, a.sign());
    result.value.resize(a.size(), 0);
    
    return result;
  }
};

int main(void) 
{     
  string s, t;
  while(getline(cin, s) && getline(cin, t)){
    BigInt a(s), b(t);
    BigInt c = a * b;
    cout << c.toString() << endl;
  }
  return 0;
}
