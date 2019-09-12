#include<cstdio>
#include<cstring>
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
#define N 210
int a[N],b[N];
int f[N][10][10];
int d[N][10][10];
int n;
void dfs(int i,int j,int k){
	if(!i) return ;
	if(d[i][j][k]==1) dfs(i-1,j,k);
	else if(d[i][j][k]==2) {
		dfs(i-1,j-1,k);
		printf("%d %d %d %d\n",i,a[i],b[i],1);
	}
	else if(d[i][j][k]==3) {
		dfs(i-1,j,k-1);
		printf("%d %d %d %d\n",i,a[i],b[i],2);
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		if(!n) break;
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++)
			for(int j=0;j<=8;j++)
				for(int k=0;k<=8;k++){
					f[i][j][k]=f[i-1][j][k]; 
					d[i][j][k]=1;
					if(j!=0&&f[i-1][j-1][k]+a[i] > f[i][j][k]) {
						f[i][j][k]=f[i-1][j-1][k]+a[i];
						d[i][j][k]=2;
					}
					if(k!=0&&f[i-1][j][k-1]+b[i] > f[i][j][k]) {
						f[i][j][k]=f[i-1][j][k-1]+b[i];
						d[i][j][k]=3;
					}
					
				}
		printf("%d\n",f[n][8][8]);
		dfs(n,8,8);
	} 
	return 0;
}




