#include <cstdio>
using namespace std;

int arr[] = {0, 
	 0,  1,  1,  2,  1,  3,  1,  4,  3,  5, // 0
	 1,  6,  1,  7,  5,  8,  1,  9,  1, 10,
	 7, 11,  1, 12,  5, 13,  9, 14,  1, 15, // 2 
	 1, 16, 11, 17,  7, 18,  1, 19, 13, 20,
	 1, 21,  1, 22, 15, 23,  1, 24,  7, 25, // 4
	17, 26,  1, 27, 11, 28, 19, 29,  1, 30,
	 1, 31, 21, 32, 13, 33,  1, 34, 23, 35, // 6
	 1, 36,  1, 37, 25, 38, 11, 39,  1, 40,
	27, 41,  1, 42, 17, 43, 29, 44,  1, 45, // 8
	13, 46, 31, 47, 19, 48,  1, 49, 33, 50
};
// 57 0 1 3 19
// 59
// 81

int main() {
	int n;
	scanf("%d", &n);
	printf("%d %d\n", arr[n], n-arr[n]);
}