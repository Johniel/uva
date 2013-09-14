#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

deque<int> f1(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  int s = 0;
  while(a <= b){
    if(s % 2){
      q.push_front(num[a++]);
      if(a > b)break;
      q.push_back(num[b--]);
    }
    else{
      q.push_back(num[a++]);
      if(a > b)break;
      q.push_front(num[b--]);
    }
    ++s;
  }
  return q;
}

deque<int> f2(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  int s = 0;
  while(a <= b){
    if(s % 2 == 0){
      q.push_front(num[a++]);
      if(a > b)break;
      q.push_back(num[b--]);
    }
    else{
      q.push_back(num[a++]);
      if(a > b)break;
      q.push_front(num[b--]);
    }
    ++s;
  }
  return q;
}

deque<int> f3(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  int s = 0;
  while(a <= b){
    if(s % 2){
      q.push_back(num[b--]);
      if(a > b)break;
      q.push_front(num[a++]);
    }
    else{
      q.push_front(num[b--]);
      if(a > b)break;
      q.push_back(num[a++]);
    }
    ++s;
  }
  return q;
}

deque<int> f4(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  int s = 0;
  while(a <= b){
    if(s % 2 == 0){
      q.push_back(num[b--]);
      if(a > b)break;
      q.push_front(num[a++]);
    }
    else{
      q.push_front(num[b--]);
      if(a > b)break;
      q.push_back(num[a++]);
    }
    ++s;
  }
  return q;
}

deque<int> f5(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  while(a <= b){
    q.push_back(num[b--]);
    if(a > b)break;
    q.push_front(num[a++]);
  }
  return q;
}

deque<int> f6(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  while(a <= b){
    q.push_back(num[a++]);
    if(a > b)break;
    q.push_front(num[b--]);
  }
  return q;
}

deque<int> f7(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  while(a <= b){
    q.push_front(num[b--]);
    if(a > b)break;
    q.push_back(num[a++]);
  }
  return q;
}

deque<int> f8(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  while(a <= b){
    q.push_front(num[a++]);
    if(a > b)break;
    q.push_back(num[b--]);
  }
  return q;
}

deque<int> f9(int num[], int size)
{
  deque<int> q;
  int a = 0, b = size-1;
  int s, t;
  q.push_front(num[a++]);  
  q.push_front(num[b--]);
  while(a <= b){

    s = abs(q.front() - num[a]);
    t = abs(q.back() - num[a]);

    if(s < t)q.push_back(num[a++]);
    else if(s == t){
      if(q.front() < q.back()){
        q.push_back(num[a++]);
      }
      else{
        q.push_front(num[a++]);
      }
    }
    else if(s > t)q.push_front(num[a++]);

    if(a > b)break;

    s = abs(q.front() - num[b]);
    t = abs(q.back() - num[b]);

    if(s < t)q.push_back(num[b--]);
    else if(s == t){
      if(q.front() > q.back()){
        q.push_back(num[b--]);
      }
      else{
        q.push_front(num[b--]);
      }
    }
    else if(s > t)q.push_front(num[b--]);
  }
  return q;
}

deque<int> f10(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q; 
  int s, t;
  q.push_front(num[a++]);  
  q.push_front(num[b--]);
  while(a < b){
    s = abs(q.front() - num[a]) + abs(q.back() - num[b]);
    t = abs(q.front() - num[b]) + abs(q.back() - num[a]);
    if(s > t){
      q.push_back(a);
      q.push_front(b);
    }
    else{
      q.push_back(b);
      q.push_front(a);
    }
    ++a;
    --b;
  }
  if(a == b){
    s = abs(q.front() - num[a]);
    t = abs(q.back() - num[a]); 
    if(s > t){
      q.push_back(a);
    }
    else{
      q.push_front(a);
    }
  }
  return q;
}

deque<int> f11(int num[], int size)
{
  int a = 0, b = size-1;
  deque<int> q;
  q.push_front(num[a++]);  
  q.push_front(num[b--]);
  while(a <= b){
    int s = abs(q.front() - num[a]);
    int t = abs(q.front() - num[b]);
    int u = abs(q.back() - num[a]);
    int v = abs(q.back() - num[b]);
    int mx = max(max(s, t), max(u, v));
    if(mx == s){
      q.push_front(num[a++]);
    }
    else if(mx == t){
      q.push_front(num[b--]);
    }
    else if(mx == u){
      q.push_back(num[a++]);
    }
    else if(mx == v){
      q.push_back(num[b--]);
    }
  }
  return q;
}

int calc(deque<int> q)
{
  const int size = q.size();
  int tmp[size], sum = 0;
  
  for(int i=0; i<size; ++i){
    tmp[i] = q.front();
    q.pop_front();
  }

  //cout << endl;  for(int i=0; i<size; ++i)cout << tmp[i] << ' ';cout << endl;

  for(int i=1; i<size; ++i){
    sum += abs(tmp[i] - tmp[i - 1]);
  }
  return sum;
}

int main(void)
{
  int num[56], tc, n, cnt = 0;
  cin >> tc;
  while(tc--){
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> num[i];
    }
    sort(num, num + n);
    cout << "Case " << ++cnt << ": " << flush;     
    int mx = -1;
    /*
    mx = max(mx, calc(f1(num, n)));
    mx = max(mx, calc(f2(num, n)));
    mx = max(mx, calc(f3(num, n)));
    mx = max(mx, calc(f4(num, n)));
    mx = max(mx, calc(f5(num, n)));
    mx = max(mx, calc(f6(num, n)));
    mx = max(mx, calc(f7(num, n)));
    mx = max(mx, calc(f8(num, n)));
    */
    //mx = max(mx, calc(f9(num, n)));
    //mx = max(mx, calc(f10(num, n)));
    mx = max(mx, calc(f11(num, n)));
    cout << mx << endl;
  }
  return 0;
}
