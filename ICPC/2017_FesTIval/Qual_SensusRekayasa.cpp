#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

pair<int,int> data[5010];
long long C[5010][5010],mod=1000000007;
int m,n,k,o,r,sisa,range,x;

int main(){
    for(int i=0;i<=5005;i++){
        for(int j=0;j<=i;j++){
            (i==j) || (j==0) ? C[i][j]=1 : C[i][j]=C[i-1][j]+C[i-1][j-1]% mod;
        }
    }
  //  cout<<"halo";
   // cout<<C[5][2]<<endl;
    int t;
    cin>>t;
    while(t--){
        scanf("%d%d%d",&m,&n,&k);
        for(int i=0;i<k;i++){
            scanf("%d%d",&o,&r);
            data[i]=mp(r,o);
        }
        data[k]=mp(1,0);
        data[k+1]=mp(n,m+1);
        k+=2;
        sort(data,data+k);

    long long ans=1;
    for(int i=0;i<k-1;i++){
        //cout<<"lala;a\n";
        ///case kalo orangnya lebih gede dari rumah selanjutnya
        if(data[i].se>data[i+1].se || (data[i+1].se-data[i].se-1 < data[i+1].fi-data[i].fi-1)){
            ans=0;
            break;
        }
        ///case kalo orangnya ada di rumah yang sama
        else if(data[i].fi==data[i+1].fi){
            ans*=1;
           //. cout<<"case 2\n";
        }
        ///case umum
        else{
            sisa=data[i+1].se-data[i].se-1;
            range=data[i+1].fi-data[i].fi+1;
            if(data[i].se==0)
                sisa--;
            if(data[i+1].se==m+1)
                sisa--;
            ans=ans*C[sisa+2-1][range-1]%mod;
            //cout<<"case 3\n";
        }
    }
    x++;
    printf("Case #%d: %lld\n",x,ans);
    }
}
