#include <cstdio>
#include <cstring>
using namespace std;

char str[1005];

int main() {
	scanf("%s",str);
	if (strlen(str) == 1 && str[0] == '0') {
		printf("nol\n");
	} else {
		bool cek = true;
		for (int i=0; i<strlen(str); i++) {
			if(str[i] < 'a' || str[i] > 'z') {
				cek = false;
			}
		}

		if (cek) {
			printf("kata\n");
		} else {
			if (str[0] == '-') {
				printf("bilangan bulat negatif\n");
			} else {
				printf("bilangan bulat positif\n");
			}
		}
	}
}