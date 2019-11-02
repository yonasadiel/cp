#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	string a[3] = {"x.--.", "|xxoo|", "|/\\/\\|"};
	string b[3] = {"x.--.", "|ooxx|", "|/\\/\\|"};
	for(i=0;i<n;i++){
		for(int k=0;k<3;k++){
			for(j=0;j<n;j++){
				if(i % 2 == 0){
					cout<<a[k];
				}else{
					cout<<b[k];
				}
				if (j < n-1 && k == 0) {
					cout << "x";
				}
			}
			cout<<endl;
		}
		
	}
	return 0;
};