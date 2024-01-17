#include <bits/stdc++.h>
using namespace std;
int n,tot=1;
bool vis[1000005]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n){
        cout<<"Test case #"<<(tot++)<<"\n";
        string tmp;
        cin>>tmp;
        for(int i=0;i<n;i++)vis[i]=0;
        for(int i=1;i<=n&&!vis[n-1];i++){
            for(int j=i;j<n;j++){
                if(tmp[j]==tmp[j%i]){
                    if((j+1)%i==0&&(j+1)/i>1&&!vis[j]){
                        vis[j]=1;
                        cout<<(j+1)<<" "<<(j+1)/i<<"\n";
                    }
                }else break;
            }
        }
    }
    return 0;
}