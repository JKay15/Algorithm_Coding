//超时了
#include <bits/stdc++.h>
using namespace std;
struct sset{
    priority_queue<string,vector<string>,greater<string>> ele;
    int num[26]={0};
    sset(string x){
        for(auto y:x)num[y-'a']++;
        ele.push(x);
    }
    bool operator<(const sset& x)const{
        if(ele.size()==x.ele.size())return ele.top()<x.ele.top();
        return ele.size()>x.ele.size();
    }
    bool check(string &x){
        int num1[26]={0};
        for(auto y:x)num1[y-'a']++;
        for(int i=0;i<26;i++)if(num1[i]!=num[i])return 0;
        return 1;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<sset> cont;
    string tmp;
    while(cin>>tmp){
        bool ok=0;
        for(auto& x:cont){
            if(x.check(tmp)){
                x.ele.push(tmp);
                ok=1;
                break;
            }
        }
        if(!ok)cont.push_back({tmp});
    }
    sort(cont.begin(),cont.end());
    int ss=cont.size();
    for(int i=0;i<5&&i<ss;i++){
        cout<<"Group of size "<<cont[i].ele.size()<<": ";
        while(!cont[i].ele.empty()){
            cout<<cont[i].ele.top()<<" ";
            cont[i].ele.pop();
        }
        cout<<".\n";
    }
    return 0;
}