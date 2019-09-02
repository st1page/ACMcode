#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int gn(){
	int x; scanf("%d",&x); return x;
	/*int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;*/
}
#define N 300
#define rp(i) for(int i=0;i<n;i++)
ll mp[N][N];
ll f[N][N]; 
int n,m;
int main(){
	int T=gn();
	while(T--){
		n=gn(); m=gn();
		rp(i) rp(j) mp[i][j]=(1ll<<60);
		for(int i=0;i<m;i++){
			int x=gn(), y=gn(), z=gn();
			mp[x][y]=z;
		}
		for(int t=0;t<6;t++){
			int x=gn(),y=gn();
			rp(i) rp(j) f[i][j]=mp[i][j];
			rp(k) rp(i) rp(j) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			mp[x][y]=-f[y][x];
			printf("%lld\n",mp[x][y]);
		}
	}
	return 0;
}




