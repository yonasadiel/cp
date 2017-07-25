#include<bits/stdc++.h>
using namespace std;

int n;

string conv(int a) {
	if (a == 0) return "zero";
	if (a == 1) return "one";
	if (a == 2) return "two";
	if (a == 3) return "three";
	if (a == 4) return "four";
	if (a == 5) return "five";
	if (a == 6) return "six";
	if (a == 7) return "seven";
	if (a == 8) return "eight";
	if (a == 9) return "nine";
	if (a == 10) return "ten";
	if (a == 11) return "eleven";
	if (a == 12) return "twelve";
	if (a == 13) return "thirteen";
	if (a == 14) return "fourteen";
	if (a == 15) return "fifteen";
	if (a == 16) return "sixteen";
	if (a == 17) return "seventeen";
	if (a == 18) return "eighteen";
	if (a == 19) return "nineteen";
	if (a == 20) return "twenty";
}

int main() {
	cin >> n;
	bool cet = false;
	if (n == 0) cout<<"zero"<<endl;
	while (n > 0) {
		if (cet) cout << "-";
		if (n <= 20) {
			cout << conv(n);
			n = 0;
		} else if (n < 100) {
			if (n < 30) { cout<<"twenty"; n-=20; }
			else if (n < 40) { cout<<"thirty"; n-=30; }
			else if (n < 50) { cout<<"forty"; n-=40; }
			else if (n < 60) { cout<<"fifty"; n-=50; }
			else if (n < 70) { cout<<"sixty"; n-=60; }
			else if (n < 80) { cout<<"seventy"; n-=70; }
			else if (n < 90) { cout<<"eighty"; n-=80; }
			else if (n < 100) { cout<<"ninety"; n-=90; }
		} else {
			while (1);
		}
		cet = true;
	}
	cout<<endl;
}
