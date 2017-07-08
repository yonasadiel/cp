#include<bits/stdc++.h>
using namespace std;

int main() {
	int dua,tiga,lima,enam;
	cin>>dua>>tiga>>lima>>enam;
	int ret = min(dua,min(lima,enam));
	dua -= ret;
	ret *= 256;
	ret += 32*min(dua,tiga);
	cout<<ret<<endl;
}
