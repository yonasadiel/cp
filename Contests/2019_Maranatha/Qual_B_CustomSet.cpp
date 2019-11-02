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

bool isNum(char c) {
	return c >= '0' && c <= '9';
}

ii getInside(const string& s, int idx, int n) {
	int ans = 0;
	int satu = -1;
	int dua = -1;
	for(int i=idx;i<n;i++){
		if(s[i] == ')'){
			dua = ans;
			break;
		}else if(s[i] == ','){
			satu = ans;
			ans = 0;
		}else if(isNum(s[i])){
			ans *= 10;
			ans += s[i] - '0';
		}
	}
	return ii(satu, dua);
}

ii merge(ii a, ii b){
	// printf("want to merge %d %d with %d %d\n",a.first, a.second, b.first, b.second);
	if(a.second == 50 && b.first == 0){
		return ii(a.first, b.second);
	}
	if(a.second < b.first){return ii(-1,-1);}
	else{
		int minim = min(a.first, b.first);
		int maks = max(a.second, b.second);
		return ii(minim, maks);
	}
	// ii ans = ii(max(a.first, b.first), min(a.second, b.second));
	// if(ans.first > ans.second){return ii(-1,-1);}
	// return ans;
}

int main(){
	string s;

	getline(cin, s);
	int n = s.length();
	int i,j;
	bool lagi = false;
	vii listBil, ans;
	for(i=0;i<n;i++){
		if(s[i] == '('){
			ii pas = getInside(s, i+1, n);
			if(pas.first > pas.second){
				listBil.pb(ii(pas.first, 50));
				listBil.pb(ii(0, pas.second));
			}else{
				listBil.pb(pas);
			}
			
			lagi = true;
		}else{
			if(s[i] == ','){
				lagi = false;
				continue;
			}
			if(lagi){continue;}

		}
	}
	int ukuran = listBil.size();
	if(ukuran == 0){
		printf("[]\n");
		return 0;
	}
	ii cur = listBil[0];
	for(i=0;i<ukuran;i++){
		ii pas = listBil[i];
		// printf("pas: %d %d\n",pas.first, pas.second);
		ii jawab = merge(cur, pas);
		// printf("jawab: %d %d  cur: %d %d\n",jawab.first, jawab.second, cur.first, cur.second);
		
		if(jawab == ii(-1,-1)){
			// printf("dipush %d %d\n",cur.first, cur.second);
			ans.pb(cur);
			
			cur = pas;
			
		}else{
			cur = jawab;

		}
		// printf("cur jd: %d %d\n",cur.first, cur.second);
	}
	if(cur!=ii(-1,-1)){
		ans.pb(cur);
	}
	int idx = 0;
	bool printed[55];
	memset(printed, true, sizeof printed);
	ii last = ans[ans.size() - 1];
	// printf("last: %d %d\n", last.first, last.second);
	bool proses = false;
	if(last.first > last.second){
		// printf("halo\n");
		
		ii hasil = merge(ii(1, last.second), ans[idx]);
		while(hasil != ii(-1,-1)){
			proses = true;
			ans[ans.size()-1] = ii(last.first, hasil.second);
			last = ans[ans.size() - 1];
			idx++;
			// if(idx >= ans.size()){
			// 	break;
			// }
			hasil = merge(ii(1, last.second), ans[idx]);
		}
	}
	

	printf("[");
	bool sudah = false;
	for(i=0;i<ans.size();i++){
		// printf("%d %d\n",ans[i].first, ans[i].second);
		if(printed[i]){
			if(sudah){printf(", ");}
			printf("(%d, %d)",ans[i].first, ans[i].second);
			sudah = true;
		}
	}
	printf("]\n");


	return 0;
};