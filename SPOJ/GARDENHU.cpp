#include<bits/stdc++.h>
using namespace std;

struct titik {
	double x,y; 
	titik() { }; 
	titik(double a, double b) {
		x=a;
		y=b;
	}
};
titik pohon[10003];

// TRUE kalau KIRI atau LURUS
bool belok(titik a, titik b, titik c) {
	double sinn=(b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
	return (sinn>=0);
}

// komparator untuk sort
bool komparator(titik a, titik b) {
	if (a.x!=b.x) {
		return (a.x<b.x);
	} else {
		return (a.y<b.y);
	}
}

stack<titik> tumpukan;

int main() {
	int angka;
	double eks,ye;
	scanf("%d",&angka);
	for (int i=0; i<angka; i++) {
		scanf("%lf %lf", &eks, &ye);
		pohon[i]=titik(eks,ye);
	}
	sort(pohon, pohon+angka, komparator);
	for (int i=0; i<angka; i++) {
	}
	titik temp;
	for (int i=0; i<angka; i++) {
		if (tumpukan.size()<2) {
			tumpukan.push(pohon[i]);
		} else {
			temp=tumpukan.top();
			tumpukan.pop();
			while ( belok(tumpukan.top(),temp,pohon[i]) && tumpukan.size()>=1) {
				temp=tumpukan.top();
				tumpukan.pop();
			}
			tumpukan.push(temp);
			tumpukan.push(pohon[i]);
		}
		
	}
	for (int i=angka-2; i>=0; i--) {
		if (tumpukan.size()<2) {
			tumpukan.push(pohon[i]);
		} else {
			temp=tumpukan.top();
			tumpukan.pop();
			while ( belok(tumpukan.top(),temp,pohon[i]) && tumpukan.size()>=1) {
				temp=tumpukan.top();
				tumpukan.pop();
			}
			tumpukan.push(temp);
			tumpukan.push(pohon[i]);
		}
		
	}
	double jarak=0,jaraksemen;
	titik sebelum=tumpukan.top();
	tumpukan.pop();
	while (!tumpukan.empty()) {
		titik kuren=tumpukan.top();
		jaraksemen=sqrt((kuren.x-sebelum.x)*(kuren.x-sebelum.x)+(kuren.y-sebelum.y)*(kuren.y-sebelum.y));
		jarak+=jaraksemen;
		sebelum=kuren;
		tumpukan.pop();
	}
	printf("%.0lf\n",jarak);
}
