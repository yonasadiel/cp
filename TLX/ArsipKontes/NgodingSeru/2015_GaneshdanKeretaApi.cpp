#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int A[105];
	scanf("%d",&N);
	for (int i=0; i<N; i++) {
		scanf("%d",&A[i]);
	}
	printf("%d",A[N-1]);
	for (int i=N-2; i>=0; i--) {
		printf(",%d",A[i]);
	}
	cout<<endl;
}
