#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 31
char mp[N][N][N]; 
int d[N][N][N];
struct node{
	int x,y,z;
	node(){};
	node(int a,int b,int c){
		x=a;y=b;z=c;
	}
}q[N*N*N];
int fp,rp;
int L,R,C;
const int dx[6]={0,0,0,0,1,-1};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={1,-1,0,0,0,0};
void init(){
	memset(d,0,sizeof(d));
	fp=rp=0;
}
char str[N];
int inmp(int x,int y,int z){
	return 0<=x&&x<R&&0<=y&&y<C&&0<=z&&z<L;
}
void solve(){
	for(int z=0;z<L;z++) 
		for(int x=0;x<R;x++){
			scanf("%s",str);
			for(int y=0;y<C;y++) mp[x][y][z] = str[y];
		}
	for(int x=0;x<R;x++)	
		for(int y=0;y<C;y++)
			for(int z=0;z<L;z++) if(mp[x][y][z]=='S'){
				d[x][y][z]=1;
				q[rp++]=node(x,y,z);
			}
	while(fp!=rp){
		node cur = q[fp++];
		int x = cur.x, y = cur.y, z = cur.z;
		for(int i=0;i<6;i++){
			int nx = x+dx[i], ny = y+dy[i], nz= z+dz[i];
			if(inmp(nx,ny,nz)&&mp[nx][ny][nz]!='#'&&!d[nx][ny][nz]){
				d[nx][ny][nz] = d[x][y][z] + 1;
				q[rp++] = node(nx,ny,nz);
			}
		}
	}
	for(int x=0;x<R;x++)	
		for(int y=0;y<C;y++)
			for(int z=0;z<L;z++) if(mp[x][y][z]=='E'){
				if(d[x][y][z]) printf("Escaped in %d minute(s).\n",d[x][y][z]-1);
				else printf("Trapped!\n");
			}
}

int main(){
	scanf("%d%d%d",&L,&R,&C);
	while(L!=0&&R!=0&&C!=0){
		init();
		solve();
		scanf("%d%d%d",&L,&R,&C);
	}
	return 0;
}




