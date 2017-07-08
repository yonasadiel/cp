#include<bits/stdc++.h>
using namespace std;

int t;
int n;
vector<int> angka[10];
string petak[100005];

queue<int> antri;

void intialize(int a) {
  while(!antri.empty()) {
    antri.pop();
  }
  for (int i=0; i<100005; i++) {
    petak[i]="";
  }
  for (int i=0; i<10; i++) {
    while(angka[i].size()>0) {
      angka[i].pop_back();
    }
  }
  for (int j=1; j<10; j++) {
    angka[(j*a)%10].push_back(j);
  }
  for (int j=0; j<10; j++) {
  	cout<<j<<": ";
  	for (int k=0; k<angka[j].size(); k++) {
  		cout<<angka[j][k]<<" ";
  	}
  	cout<<endl;
  }
}

string kata(int b) {
  string k;
  k[0]=b+'0';
  return k;
}


int main() {
  scanf("%d",&t);
  for (int i=0; i<t; i++) {
    string hasil;
    scanf("%d",&n);
 	  intialize(n);
    for (int j=0; j<angka[0].size(); j++) {
        petak[angka[0][j]*n/10]="0";
        antri.push(angka[0][j]*n/10);
    }
    for (int j=0; j<angka[1].size(); j++) {
        petak[angka[1][j]*n/10]="1";
        antri.push(angka[1][j]*n/10);
    }
    while(!antri.empty()) {
      int kur=antri.front();
      antri.pop();
      while(kur%10==0 || kur%10==1) {
        if (kur==0) break;
        petak[kur]==kata(kur%10)+petak[kur];
      }
      if (kur==0) {
        hasil==petak[kur];
        break;
      }
      int untuknol=(10-(kur%10))%10;
      for (int j=0; j<angka[untuknol].size(); j++) {
        if (petak[angka[untuknol][j]*n/10]!="") {
          petak[angka[untuknol][j]*n/10]=kata(untuknol)+petak[kur];
          cout<<angka[untuknol][j]*n/10<<" "<<petak[angka[untuknol][j]*n/10]<<endl;
          antri.push(angka[untuknol][j]*n/10);
        }
      }
      int untuksatu=(11-(kur%10))%10;
      for (int j=0; j<angka[untuksatu].size(); j++) {
        if (petak[angka[untuksatu][j]*n/10]!="") {	
          petak[angka[untuksatu][j]*n/10]=kata(untuksatu)+petak[kur];
          cout<<angka[untuknol][j]*n/10<<" "<<petak[angka[untuknol][j]*n/10]<<endl;
          antri.push(angka[untuksatu][j]*n/10);
        }
      }
      cout<<kur<<" "<<petak[kur]<<endl;
    }
    cout<<hasil<<endl;
	}

}
