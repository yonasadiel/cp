#include <string>
#include <iostream>
using namespace std;

int main() {
	string in,out;
	bool cek = true;
	bool sudah = false;

	cin >> in;
	int inl = in.length();

	for (int i=0; i<inl; i++) {
		if (in[i] == '@') {
			cek = false;
		} else {
			if (i+1 < inl && in[i+1] == '@') {
				if (out[out.length()-1]  == '@') {
					cek = false;
				} else {
					if (sudah) {
						out += ',';
					}
					out += in[i];
					out += in[i+1];
					i++;
					sudah = true;	
				}
			} else {
				out += in[i];
			}
		}
	}

	if (cek && sudah && out[out.length()-1] != '@') {
		cout<<out<<endl;
	} else {
		cout<<"No solution"<<endl;
	}
}