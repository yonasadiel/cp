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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool valid(const string& s){
	int i,j;
	int ukuran = s.size();
	vector<string> vs;
	string ss;
	for(i=0;i<ukuran-1;i++){
		ss += s[i];
		if(s[i] <= s[i+1]){
			
		}else{
			vs.pb(ss);
			// printf("push ss:"); cout <<ss<<endl;
			ss = "";
		}
	}
	ss += s[ukuran-1];
	vs.pb(ss);
	// printf("push ss:"); cout <<ss<<endl;
	
	ukuran = vs.size();
	if(ukuran == 1){return true;}
	while(vs.size() >= 2){
		string akhir = vs.back(); vs.pop_back();
		string awal = vs.back(); vs.pop_back();
		if(awal <= akhir){
			vs.pb(awal + akhir);
		}else{
			return false;
		}
	}
	
	return true;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		string s;
		cin>>s;
		if(valid(s)){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf("\n");

	return 0;
};