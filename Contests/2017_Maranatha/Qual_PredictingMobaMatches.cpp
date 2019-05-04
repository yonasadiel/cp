#include<bits/stdc++.h>
using namespace std;
int t,i,j;
string s,s1;
int a[5],b[5],c[5],d[5];
int a1[5],b1[5],c1[5],d1[5];
int nilai1,nilai;
int main(){
    scanf("%d\n",&t);
    while(t--){

        //getline(cin,s);

        cin>>s;
        for(i=0;i<5;i++){
            scanf("%d",&a[i]);
          //  printf("t");
            scanf("%d",&b[i]);
            scanf("%d",&c[i]);
            scanf("%d",&d[i]);
        }
        //getline(cin,s1);
        cin>>s1;
        for(i=0;i<5;i++){
            scanf("%d",&a1[i]);
            scanf("%d",&b1[i]);
            scanf("%d",&c1[i]);
            scanf("%d",&d1[i]);
        }
        scanf("\n");
        int urut[] = {0,1,2,3,4};
        int nilai  =  a[urut[0]] +  b[urut[1]] +  c[urut[2]] +  d[urut[3]] +  d[urut[4]];
        int nilai1 = a1[urut[0]] + b1[urut[1]] + c1[urut[2]] + d1[urut[3]] + d1[urut[4]];
        do {
            int kand  =  a[urut[0]] +  b[urut[1]] +  c[urut[2]] +  d[urut[3]] +  d[urut[4]];
            int kand1 = a1[urut[0]] + b1[urut[1]] + c1[urut[2]] + d1[urut[3]] + d1[urut[4]];

            nilai  = max(nilai , kand );
            nilai1 = max(nilai1, kand1);
        } while (next_permutation(urut, urut+5));

        if(nilai>nilai1) cout<<s<<endl;
        else if(nilai1>nilai) cout<<s1<<endl;
        else cout<<"50-50\n";
    }
}
