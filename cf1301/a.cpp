#include<cstdio>
#include<iostream>
#include<cstring>

#define N 112345
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int n;
int t;
char a[N],b[N],c[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s%s%s",a,b,c);
        n = strlen(a);
        int ans=1;
        for(int i=0;i<n;i++){
            if(a[i]!=c[i]&&b[i]!=c[i]) ans=0; 
        }
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}