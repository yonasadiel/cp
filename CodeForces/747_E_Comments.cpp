#include<bits/stdc++.h>
using namespace std;

int n;
char kal[1000005];
vector<string> v[10000];
int dm = 0;

int input(int pos, int d, int e) {
//	cout<<"input "<<pos<<" "<<d<<" "<<e<<endl;
	dm = max(d,dm);
	string s="";
	int g = 0;
	while(pos < n && g < e) {
		if (kal[pos]!=',') {
			s+=kal[pos];
			pos++;
		} else {
			v[d].push_back(s);
//			cout<<"get "<<s<<endl;
			s="";
			g++;
			
			int a =0;
			pos++;
			while(kal[pos]!=',') {
				a*=10;
				a+=kal[pos]-'0';
				pos++;
			}
			pos++;
			pos = input(pos,d+1,a);
			
		}
	}
	return pos;
}

int main() {
	scanf("%s",&kal);
	n = strlen(kal);
	input(0,0,1e9);
	printf("%d\n",dm);
	for (int i=0; ; i++) {
		if (v[i].size()!=0) {
			for (int j=0; j< v[i].size(); j++) {
				if (j!=0) printf(" ");
				cout<<v[i][j];
			} cout<<"\n";
		} else {
			break;
		}
	}
}
