#include<bits/stdc++.h>
using namespace std;

int n,m;
char kal[105][105];
int kall[105];
int arr[105];

void checkString() {
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			printf("%c",kal[i][j]);
		}
		cout<<"\n";
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			kal[i][j] = '!';
		}
	}
	for (int i=0; i<n; i++) {
		scanf("%s",&kal[i]);
		kall[i] = strlen(kal[i]);
		kal[i][kall[i]] = '!';
	}
	int leng = 0;
	for (int i=0; i<m; i++) {
		scanf("%d",&arr[i]);
		arr[i]--;
		leng = max(leng,kall[arr[i]]);
	}
	
	bool bisa=true;
	char ret[105];
	for(int i = 0; i < leng; i++) {
		if (kal[arr[0]][i] == '!') {
			bisa = false;
		}
		ret[i] = kal[arr[0]][i];
		for (int j = 1; j < m; j++) {
			if (ret[i] != kal[arr[j]][i]) {
				ret[i] = '?';
			}
			if (kal[arr[j]][i] == '!') {
				bisa=false;
			}
		}
	}
	
	bool included=true;
	for (int i=0, j=0; i<n; i++) {
		included=true;
		if (j >= m || i != arr[j]) {
			if (kall[i] != leng) continue;
			for (int k=0; k<leng; k++) {
				if (kal[i][k] != ret[k] && ret[k]!='?') {
//					cout<<i<<j<<k<<endl;
					included=false;
				}
			}
//			cout<<included<<endl;
			if (included) {
//				cout<<"h"<<endl;
				bisa=false;
			}
		} else {
			j++;
		}
	}
	
	if (bisa) {
		printf("Yes\n");
		for (int i=0; i<leng; i++) {
			printf("%c",ret[i]);
		}
		printf("\n");
	} else {
		printf("No\n");
	}
}
