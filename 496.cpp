#include <iostream>
#include <set>
#include <sstream>
using namespace std;

string compute( set<int> &A,set<int> &B )
{
  if( A.size() == B.size() ){
    set<int> :: iterator itr1 = A.begin();
    set<int> :: iterator itr2 = B.begin();
    bool flg = true;
    for( ; itr1 != A.end() && flg; itr1++, itr2++){
      if(*itr1 != *itr2)
	flg = false;
    }
    if(flg)
      return "A equals B" ;
  }

  if( includes(A.begin(),A.end(),B.begin(), B.end()) ){
    return "B is a proper subset of A";
  }
  if( includes(B.begin(), B.end(),A.begin(),A.end()) ){
    return "A is a proper subset of B";
  }

  set<int> tmp;
  set<int> :: iterator itr1 = A.begin();
  set<int> :: iterator itr2 = B.begin();
  for( ; itr1 != A.end(); itr1++)
    tmp.insert(*itr1);
  for( ; itr2 != B.end(); itr2++)
    tmp.insert(*itr2);
  if(tmp.size() == ( A.size() + B.size() ) )
     return "A and B are disjoint";


  return "I'm confused!";
}

int main(void)
{
  string AA;
  string BB;

  while( getline(cin,AA) && getline(cin,BB) ){
    set<int> A;
    set<int> B;

    stringstream sinA(AA);
    int n;
    while( sinA >> n ){
      A.insert(n);
    }
    stringstream sinB(BB);
    while( sinB >> n ){
      B.insert(n);
    }
    cout << compute(A,B) << endl;
  }
  return 0;
} 
