#include<bits/stdc++.h>
using namespace std;
long long a[50][50];
int x,y,z,i,j;
int main(){
    for(i=0;i<=43;i++){
        for(j=0;j<=i;j++){
            if(j=0 || j==i) a[i][j]=1;
            else a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }
    cin>>x>>y>>z;
    cout<<a[x+y+z][x]*a[y+z][y]<<endl;
}
