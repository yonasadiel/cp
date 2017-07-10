#include<bits/stdc++.h>
using namespace std;

int main() {
	string utama,hapus,letak,sisip;
	
	cin >> utama >> hapus >> letak >> sisip;
	
	utama.erase(utama.find(hapus),hapus.length());
	utama.insert(utama.find(letak)+letak.length(),sisip);
	
	cout << utama << endl;
	
	return 0;
}
