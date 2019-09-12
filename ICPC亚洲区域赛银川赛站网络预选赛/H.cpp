#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 1123456
char s[N];
ll f[N][10];
int vis[10];
ll w[N];

int n;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) {
		char c = s[i];
		for(int j=0;j<5;j++) f[i][j]=f[i-1][j];
		if(c=='w'){
			f[i][0]+=w[i];
			vis[1]=1;
		} else if(c=='r') {
			if(vis[1]){
				vis[2]=1;
				f[i][1]=f[i-1][1]+w[i]; 
			}
		} else if(c=='o') {
			if(vis[2]){
				vis[3]=1;
				f[i][2]=f[i-1][2]+w[i];
			}
		} else if(c=='n') {
			if(vis[3]){
				vis[4]=1;
				f[i][3]=f[i-1][3]+w[i];
			}	
		} else if(c=='g') {
			if(vis[4]){
				vis[5]=1;
				f[i][4]=f[i-1][4]+w[i];
			}
		} else {
		}
	}
	ll ans=(1ll<<60);
	for(int i=0;i<5;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}




