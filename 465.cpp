//add uva424, uva495
//mlt uva623, uva748
//sub uva11448
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

const static int LIMIT = 10000;
const static int LANGE = 4;

#define LESS -1
#define EQUAL 0
#define GREATER 1
#define FRONT "%d"
#define FORMAT "%04d"

class BigInteger {
public:
  BigInteger(void){
    negative = false;
    value.resize(1);
    value[0] = 0;
  }
  BigInteger(vector<int> &in){
    negative = false;
    value = in;
  }
  BigInteger(char sign, vector<int> &in){
    if(sign == '+')
      negative = false;
    else if(sign == '-')
      negative = true;
    value = in;
  }
  BigInteger(vector<int> &in, bool sign){
    negative = sign;
    value = in;
  }
  BigInteger(string &in){
    negative = false;
    if(in[0] == '-'){
      negative = true;
      in.erase(in.begin());
    }    
    while (in.size()%LANGE != 0 )in.insert(in.begin(), 1, '0');
    for(int i=in.size()-LANGE; i>=0; i-=LANGE)
      value.push_back(atoi(in.substr(i, LANGE).c_str()));
  }
  BigInteger(char sign, string &in){
  }
  BigInteger(string &in, bool sign){
  }
  BigInteger operator + (BigInteger &in){
    if(sign() == in.sign())
      return add(*this, in, sign());
    else if(compare(in, true) == GREATER)
      return sub(in, *this, in.sign());
    else
      return sub(*this, in, sign());
  }
  BigInteger operator * (BigInteger &in){
    bool s = (sign() == in.sign())? false : true;
    return mul(*this, in, s);
  }
  BigInteger operator - (BigInteger &in){
    if(sign() != in.sign())
      return add(*this, in, sign());
    else if(compare(in, true) == LESS){
      // cout << toString() << " > " << in.toString() << endl;
      return sub(*this, in, sign());
    }
    else{
      //cout << toString() << " < " << in.toString() << endl;
      return sub(in, *this, !in.sign());
    }
  }
  BigInteger operator / (BigInteger &in){
    bool s = (sign() == in.sign())? false : true;
    return div(*this, in, s);
  }
  bool operator == (BigInteger &in){
    if(compare(in, false) == EQUAL)
      return true;
    else
      return false;
  }
  bool operator < (BigInteger &in){
    if(compare(in, false) == GREATER)
      return true;
    else
      return false;
  }
  bool operator > (BigInteger &in){
    if(compare(in, false) == LESS)
      return true;
    else
      return false;
  } 
  int &operator [] (int n) {
    return value[n];
  }
  string toString(void){
    char buffer[LANGE+1];
    string result;
    
    if (negative == true) result = "-";
    sprintf(buffer, FRONT, value.back()), result += buffer;
    
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
  bool compAbs(BigInteger &in){
    return true;
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
  int compare(BigInteger &in, bool abs){
    if(sign() != in.sign() && !abs)
      return (sign())? LESS : GREATER;
    if(size() != in.size())
      return (size() > in.size())? LESS : GREATER;
    for(int i=in.size()-1; i>=0; i--){
      if(in[i] == value[i])
	continue;
      return (value[i] > in.value[i])? LESS : GREATER;
    }
    return EQUAL;
  }
  BigInteger add(BigInteger &a, BigInteger &b, bool sign){
    BigInteger result = BigInteger(a.value, sign);
    result.value.resize( max( a.size(), b.size() )+1, 0 );
    for(int i=0; i<result.size()-1; i++){
      if(i < b.size() )
	result[i] += b[i];
      if(result[i]/LIMIT != 0){
	result[i+1]++;
	result[i] %= LIMIT;
      }
    }
    result.regulation();
    return result;
  }
  BigInteger mul(BigInteger &a, BigInteger &b, bool sign){
    BigInteger result;
    result.value.resize(a.size() + b.size() + 1, 0);
    for(int i=0; i<a.size(); i++){
      for(int j=0; j<b.size(); j++){
	int carry = a[i] * b[j];
	for(int k=i+j; ; k++ ){
	  result[k] += carry;
	  if(result[k] < LANGE)
	    break;
	  else{
	    carry = result[k] / LIMIT;
	    result[k] %= LIMIT;
	  }
	}
      }
    }
    result.negative = sign;
    result.regulation();
    return result;
  }
  BigInteger sub(BigInteger &a, BigInteger &b, bool sign){
    BigInteger result = BigInteger(a.value, sign);
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
  BigInteger div(BigInteger &a, BigInteger &b, bool sign){
    BigInteger result = BigInteger(a.value, a.sign());
    result.value.resize(a.size(), 0 );
    
    return result;
  }
};

int main(void) 
{
  string lmax = "2147483647";
  string lmin = "-2147483648";
  BigInteger Lmax(lmax);
  BigInteger Lmin(lmin);
  while(true){
    string S;
    char c = 'n';
    string a, b;
    getline(cin, S);
    for(int i=0; i<S.size(); i++){
      if( !(isdigit(S[i])) && a.size() == 0 )
	a = S.substr(0, i);
      if(S[i] == '+' || S[i] == '*'){
	c = S[i];
	i++;
	while(S[i] == ' ')i++;
	b = S.substr(i, S.size() - i);
	i = INT_MAX;
	break;
      }
    }
    if(cin.eof() == true)
      break;
    //cout << a << endl  << b << endl;exit(1);
    BigInteger A(a);
    BigInteger B(b);
    BigInteger C(b);
    if(c =='*')
      C = A * B;
    else
      C = A + B;
    cout << S << endl;
    cout << A.toString() << endl;
    if(A.sign())cout << "negative" << endl;
    cout << B.toString() << endl; 
    if(B.sign())cout << "negative" << endl;
    cout << C.toString() << endl;
    if(C.sign())cout << "negative" << endl;
    
    //cout << A.toString() << ' ' << c << ' '<< B.toString() << endl;
    if(A > Lmax && !A.sign())
      cout << "first number too big" << endl;
    else if(A > Lmin && A.sign())
      cout << "first number too big" << endl;       
    if(B > Lmax && !B.sign())
      cout << "second number too big'" << endl;
    else if(B > Lmin && B.sign())
      cout << "second number too big'" << endl;       
    if(C > Lmax && !C.sign())
      cout << "result too big" << endl;
    else if(C > Lmin && C.sign())
      cout << "result too big" << endl;       

  }
  return 0;
}
