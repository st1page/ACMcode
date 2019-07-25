#include<cstdio>
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
#define N 112345
int n,k;
int q[N],d[N];
int fp,rp;
void init(){
	memset(d,0,sizeof(d));
	fp=rp=0;
}
bool inmp(int x){
	return x>=0&&x<N;
}
void solve(){
	q[rp++] =n; d[n]=1; 
	while(fp<rp){
		int x=q[fp++];
		if(x==k){
			printf("%d\n",d[x]-1);
			return ;
		}
		if(inmp(x+1)&&!d[x+1]){
			d[x+1]=d[x]+1;
			q[rp++]=x+1;
		} 
		if(inmp(x-1)&&!d[x-1]){
			d[x-1]=d[x]+1;
			q[rp++]=x-1;
		}
		if(inmp(x*2)&&!d[x*2]){
			d[x*2]=d[x]+1;
			q[rp++]=x*2;
		}
	}
}
int main(){ 
	while(scanf("%d%d",&n,&k)!=EOF){
		init();
		solve();
	}
	return 0;
} 

