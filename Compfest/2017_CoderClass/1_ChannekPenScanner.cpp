#include <cstdio>
#include <iostream>
using namespace std;

string baris[10];

int main() {
  int n;
  for (int i=0; i<9; i++) {
    cin>>baris[i];
  }
  n = baris[0].length();

  bool pertama = true;

  for (int i=2; i<n; i+=5) {
    bool tengah = (baris[4][i] == '0');
    bool bawah  = (baris[7][i] == '0');
    if (tengah && bawah) {
      printf("B");
    } else if (tengah) {
      printf("A");
    } else if (bawah) {
      printf("C");
    } else {
      printf(" ");
    }
  }

  printf("\n");
}