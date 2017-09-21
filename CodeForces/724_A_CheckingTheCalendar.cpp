#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string,int> ang;

int main() {
	ang["monday"]=1;
	ang["tuesday"]=2;
	ang["thursday"]=4;
	ang["wednesday"]=3;
	ang["friday"]=5;
	ang["saturday"]=6;
	ang["sunday"]=7;
	
	string a,b;
	cin>>a>>b;
	int selisih = (ang[b]-ang[a]+7)%7;
	
	if (selisih == 3 || selisih == 2 || selisih==0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}
