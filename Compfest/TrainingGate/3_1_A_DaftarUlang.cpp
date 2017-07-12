/**
 * Solution by: Ensof Barhami
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    string s[103];
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    string x;
    bool cek=false;
    for(int i=0;i<q;i++){
        cin>>x;
        for(int j=0;j<n;j++){
            if(x==s[j]){
                cout<<j+1<<endl;
                cek=true;
            }
        }
        if(!cek) cout<<"-1\n";
        cek=false;
    }
}