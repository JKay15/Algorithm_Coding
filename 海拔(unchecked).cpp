#include <bits/stdc++.h>
using namespace std;
const int maxn=405;
int h[maxn][maxn],n,m,vis[maxn][maxn];
#define check(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
bool avai(int mid){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int> > q;
    q.push({1,1});
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx=cur.first+dx[i];
            int yy=cur.second+dy[i];
            if(xx==n&&yy==m)return 1;
            if(check(xx,yy)&&!vis[xx][yy]){
                if(abs(h[xx][yy]-h[cur.first][cur.second])<=mid){
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int l=2000000000,r=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>h[i][j];
        l=min(l,h[i][j]);
        r=max(r,h[i][j]);
    }
    r=r-l,l=0;
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(avai(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<res;
    return 0;
}