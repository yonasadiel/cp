#define tinggi first
#define mulai second
#include <stack>
#include <utility>
#include <cstdio>
using namespace std;

int n,h,luastemp,luasmaks=-1;
stack <pair<int,int> > stak;
pair<int,int> staktemp;

int main() {
	while (true) {
		while (!stak.empty()) {
			stak.pop();
		}
		luasmaks=0;
		scanf("%d",&n);
		stak.push(make_pair(0,0));
		if (n==0) {
			break;
		}
		for (int i=0; i<n; i++) {
//			cout<<i;
			staktemp=stak.top();
			scanf("%d",&h);
			if (h>staktemp.tinggi) {
				stak.push(make_pair(h,i));
//				cout<<" push "<<h<<" "<<i;
			}
			while (h<staktemp.tinggi) {
				luastemp=(i-staktemp.mulai)*staktemp.tinggi;
//				cout<<" luas "<<staktemp.mulai<<" sampe "<<i<<" luasnya "<<luastemp;
				if (luastemp>luasmaks) {
					luasmaks=luastemp;
//					cout<<" dipake ";
				}
				stak.pop();
				if (h>stak.top().tinggi) {
					stak.push(make_pair(h,staktemp.mulai));
				}
				staktemp=stak.top();
			}
//			cout<<endl;
		}
		while (!stak.empty()) {
			luastemp=(n-staktemp.mulai)*staktemp.tinggi;
//			cout<<luastemp;
			if (luastemp>luasmaks) {
				luasmaks=luastemp;
			}
			stak.pop();
		}
		printf("%d\n",luasmaks);
	}
}
