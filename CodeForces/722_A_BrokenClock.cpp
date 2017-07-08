#include<bits/stdc++.h>
using namespace std;

int main() {
  int f;
  string jam;

  scanf("%d",&f);
  cin>>jam;

  /**PERBAIKI MENIT**/
  if (jam [3] > '5') jam[3] = '2';
  /**PERBAIKI JAM 01..12**/
  if (f == 12 && jam[0] > '1' && jam[1] > '0') jam[0] = '0';
  if (f == 12 && jam[0] > '1' && jam[1] == '0') jam[0] = '1';
  if (f == 12 && jam[0] == '1' && jam[1] > '2') jam[1] = '0';
  if (f == 12 && jam[0] == '0' && jam[1] == '0') jam[1] = '1';
  /**PERBAIKI JAM 00..23**/
  if (f == 24 && jam[0] > '2') jam[0] = '0';
  if (f == 24 && jam[0] == '2' && jam[1] > '3') jam[1] = '0';

  cout<<jam<<endl;

}
