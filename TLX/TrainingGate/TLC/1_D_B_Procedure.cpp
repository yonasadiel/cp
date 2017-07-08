#include <bits/stdc++.h>

void tulis(int bil) {

	if(bil<10)	{
		printf("satuan\n");
	}
		else if (bil<100) {
			printf("puluhan\n");
		}
			else if (bil<1000) {
				printf("ratusan\n");
			}
				else if (bil<10000) {
					printf ("ribuan\n");
				}
					else printf("puluhribuan\n");
	
}

int main() {
	int n;
	while (scanf("%d", &n)!= EOF) {
	tulis(n);
	}
	return 0;
}



