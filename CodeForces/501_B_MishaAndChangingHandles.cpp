using namespace std;

string lama[2015], baru[2015];
string masuklama, masukbaru;
int n,indeks;
bool sudah;

int main() {
	indeks=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		cin>>masuklama>>masukbaru;
		sudah=false;
		for (int j=0; j<indeks; j++) {
			if (baru[j]==masuklama) {
				baru[j]=masukbaru;
				sudah=true;
			}
		}
		if (!sudah) {
			lama[indeks]=masuklama;
			baru[indeks]=masukbaru;
			indeks++;
		}
	}
	
	printf("%d\n",indeks);
	for (int i=0; i<indeks; i++) {
		cout<<lama[i]<<" "<<baru[i]<<endl;
	}
}
