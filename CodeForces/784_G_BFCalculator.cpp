#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[13];
	char o[13];
	memset(a,0,sizeof a);
	string s;
	int j = 0;
	cin >> s;
	for (int i=0; i<s.length(); i++) {
		if (s[i]!= '+' && s[i]!='-') {
			a[j] *= 10;
			a[j] += s[i] - '0';
		} else {
			j++;
			o[j] = s[i];
		}
	}
	for (int i=0; i<a[0]; i++) {
		printf("+");
	} printf(">\n");
	for (int m=1; m<=j; m++) {
		for (int i=0; i<a[m]; i++) {
			printf("+");
		} printf(">\n");
		printf("<[<%c>-]\n",o[m]);
		
	}
	
	printf("<\n");
	printf("[>>+>+<<<-]>>>[<<<+>>>-]<<+>[<->[>++++++++++<[->-[>+>>]>[+[-<+>]>+>>]<<<<<]>[-]\n");
	printf("++++++++[<++++++>-]>[<<+>>-]>[<<+>>-]<<]>]<[->>++++++++[<++++++>-]]<[.[-]<]<\n");
	
	
	
	//+++++++++>
	//+++++++>
	//<[<->-]<
	//++++++++++++++++++++++++++++++++++++++++++++++++.
	
}
