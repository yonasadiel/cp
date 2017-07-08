#include<bits/stdc++.h>
using namespace std;

char kal[105];

int main() {
	scanf("%s",&kal);
	int ilast=-1,ret=0,leng=strlen(kal);
	for (int i=0; i<strlen(kal); i++) {
		if (kal[i] == 'A' || kal[i] == 'E' || kal[i] == 'O' || kal[i] == 'U' || kal[i] == 'I' || kal[i] == 'Y') {
			ret=max(i-ilast,ret);
			ilast=i;
		}
	}
	ret=max(ret,(leng-ilast));
	printf("%d\n",ret);
}
