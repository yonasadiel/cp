/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
using namespace std;

long long a,b,c;

int main(){
  cin>>a>>b;
  c = __gcd(a,b);
  c = (a*b)/c;
  cout<<c<<endl;
}