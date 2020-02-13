#include<cstdio>
#include<iostream>

using namespace std;
int a[200];
int top;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        char ch=getchar();
        while(ch!='0'&&ch!='1') ch=getchar();
        while(ch=='0') ch=getchar();
        top=0;
        while(ch=='0'||ch=='1') {
            a[++top]=ch-'0';
            ch=getchar();
        }
        while(a[top]==0&&top) top--;
        int ans=0;
        for(int i=1;i<=top;i++) if(!a[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}