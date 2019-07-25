#include<cstdio>

using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 20
int n,m;
int mp[N][N];
int ans[N][N];
void init(){
	
}
const int dx[5]={0,0,1,-1,0};
const int dy[5]={0,1,0,0,-1};
bool inmp(int x,int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}
void flip(int x,int y){
	for(int i=0;i<5;i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(inmp(nx,ny)) mp[nx][ny]^=ans[x][y];
	}
}
void flipline(int x){
	for(int j=0;j<m;j++) flip(x,j);
}
int dfs(int i){

	if(i==-1) {
		for(int j=0;j<m;j++) if(mp[0][j]) return 1e9;
		int sum=0;
		for(int ii=0;ii<n;ii++)
			for(int jj=0;jj<m;jj++) sum+=ans[ii][jj];
		return sum;
	}
	for(int j=0;j<m;j++) 
		if(mp[i+1][j]) ans[i][j] = 1;
		else ans[i][j] = 0;
	flipline(i);
	int tmp = dfs(i-1);
	flipline(i);
	return tmp;
}
void solve(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) scanf("%d",&mp[i][j]);
	int anss = 1e9;
	int ansk = 0;
	for(int k=0;k<(1<<m);k++){
		for(int j=m-1;j>=0;j--)
			if((1<<j)&k) ans[n-1][j]=1; else ans[n-1][j]=0;
		flipline(n-1);
		int x = dfs(n-2);
		if(x<anss) {
			anss = x;
			ansk = k;
		}
		flipline(n-1);
	}
	if(anss==1e9) puts("IMPOSSIBLE");
	else{
		for(int j=m-1;j>=0;j--)
			if((1<<j)&ansk) ans[n-1][j]=1; else ans[n-1][j]=0;
		flipline(n-1);
		dfs(n-2);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) printf("%d ",ans[i][j]);
			putchar('\n');
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
		init();
		solve();

	return 0;
}




