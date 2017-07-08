#include<bits/stdc++.h>
using namespace std;

vector<string>v;
vector<string>vk;
vector<string>vl;

int main() {
	string kalimat;
	cin>>kalimat;
	int le=kalimat.length();
	for (int i=5; i+1<le; i++) {
		if (i==le-3) continue;
		string coba1="";
		coba1+=kalimat[i];
		coba1+=kalimat[i+1];
		if (!binary_search(v.begin(),v.end(),coba1)) {
			v.push_back(coba1);
			sort(v.begin(),v.end());
		} else {
			if (!binary_search(vk.begin(),vk.end(),coba1)) {
				vk.push_back(coba1);
				sort(vk.begin(),vk.end());	
			}
		}
	}
	for (int i=5; i+2<le; i++) {
		if (i==le-4) continue;
		string coba1="";
		coba1+=kalimat[i];
		coba1+=kalimat[i+1];
		coba1+=kalimat[i+2];
		if (!binary_search(v.begin(),v.end(),coba1)) {
			v.push_back(coba1);
			sort(v.begin(),v.end());
		} else {
			if (!binary_search(vk.begin(),vk.end(),coba1)) {
				vk.push_back(coba1);
				sort(vk.begin(),vk.end());	
			}
		}
	}
	sort(v.begin(),v.end());
	long long si=v.size();
	for (long long i=0; i<si; i++) {
		if (!binary_search(vk.begin(),vk.end(),v[i])) {
			vl.push_back(v[i]);
		}
	}
	si=vl.size();
	printf("%d\n",si);
	for (long long i=0; i<si; i++) {
		cout<<vl[i]<<'\n';
	}
}
