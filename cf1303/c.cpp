#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
typedef long long ll;
#define N 30
int mp[N][N];
int vis[N];
int d[N];
int v1[N];
void dfs(int x){
    putchar('a'+x);
    for(int y=0;y<26;y++){
        if(mp[x][y]&&!v1[y]) {
            v1[y]=1;
            dfs(y);
            return ;
        }
    }
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        char ch = getchar(); 
        while(ch<'a' || ch>'z') ch=getchar();
        vis[ch-'a']=1;
        char lch = ch; ch = getchar();
        while(ch>='a'&&ch<='z') {
            vis[ch-'a']=1;
            mp[ch-'a'][lch-'a']=mp[lch-'a'][ch-'a']=1;           
            lch = ch;           
            ch = getchar();
        }
        int sum=0;
        for(int x=0;x<26;x++){
            if(vis[x]) sum++;
        }
        if(sum==1){
            puts("YES");
            for(int i=0;i<26;i++) putchar('a'+i);
            putchar('\n');
            continue;
        }
        int flag=0;
        for(int x=0;x<26;x++){
            d[x] = 0;
            for(int y=0;y<26;y++) if(mp[x][y]) {
                d[x]++;
            }
            if(d[x]>2) flag = 1;
        }
        if(flag){
            puts("NO");
            continue;
        }
        flag = 1;
        for(int x=0;x<26;x++) if(d[x]==1) flag=0;
        if(flag){
            puts("NO");
            continue;
        } else puts("YES");
        int st=-1;
        for(int i=0;i<26;i++) if(d[i]==1) st=i;
        memset(v1,0,sizeof(v1));
        v1[st]=1;
        dfs(st);
        for(int i=0;i<26;i++) if(!vis[i]) putchar('a'+i);
        putchar('\n');
    }
    return 0;
}