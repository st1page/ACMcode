#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
typedef long long ll;
int a[112345];
ll c[62];
ll n;
int m;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        cin>>n>>m;
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        memset(c,0,sizeof(c));
        for(int j=0;j<30;j++)
            for(int i=0;i<m;i++) c[j] += (a[i]==(1<<j));
        
        int ans=0;
        for(int i=0;i<60;i++){
    //        printf("cur %d %d\n",i,c[i]);
            if(n&(1ll<<i)){
                if(c[i]){
                    c[i]--;
                } else {
                    for(int j=i+1;j<60;j++){
                        if(c[j]){
                            for(int k=j;k>i;k--) {
                                c[k]--; c[k-1]+=2; ans++;
                            }
                            break;
                        } 
                    }
                    if(c[i]) c[i]--;
                    else {
                        ans=-1;
                        break;
                    }
                }
            }
            c[i+1] += c[i]/2;
        }
        printf("%d\n",ans);
    }
    return 0;
}