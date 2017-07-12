/**
 * Solution by: Restu Wayu Kartiko
 */

#include <bits/stdc++.h>
using namespace std;

unsigned long long n,a,b,sum;
  
int main(){
  cin>>n>>a>>b;
  long long fpb = a*b/(__gcd(a,b));
  sum = (n/a) + (n/b) - n/fpb;
  cout<<sum<<endl;
}