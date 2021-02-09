//https://codeforces.com/contest/1455/problem/0
#include<bits/stdc++.h>
using namespace std;
#define ll long double
ll fun(ll num)
{
  ll count=0;
  string s = to_string(num);
  ll i=s.size()-1;
  while(s[i]=='0')
  {
    count++;
    i--;
  }
  return s.size()-count;
}
int main()
{
  ll tc;
  cin>>tc;
  while(tc--)
  {
    ll n;
    cin>>n;
    cout<<fun(n)-1<<endl;
  }
}