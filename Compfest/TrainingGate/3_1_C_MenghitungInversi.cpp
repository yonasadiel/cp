/**
 * Solution by: Ensof Barhami
 */

#include<bits/stdc++.h>
using namespace std;
int n,a[1111];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int temp = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) temp++;
        }
    }
    cout<<temp<<endl;
}