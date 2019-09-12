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
#define N 11234
int prime[N],tot;
bool mark[N];
int decode(int x){
	return x&0xf+((x>>4)&0xf)*10+((x>>8)&0xf)*100+((x>>12)&0xf)*1000;
}
int encode(int x){
	int res = x%10; x/=10;
	res|=(x%10)<<4; x/=10;
	res|=(x%10)<<8; x/=10;
	res|=(x%10)<<12;
	return res;
}
#define M 65540
int b[M];
void INIT(){  
	for(int i=2;i<=N;i++){
		if(!mark[i])  prime[++tot]=i;
		for(int j=1;j<=tot;j++){
			if(i*prime[j]>=N) break;
			mark[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	for(int i=1;i<=tot;i++) 
		if(prime[i]>=1000&&prime[i]<=9999) 
			b[encode(prime[i])] = 1;
}
int q[M];
int d[M];
int fp,rp;
void init(){
	memset(d,0,sizeof(d));
	fp=rp=0;
}
void release(int x,int y){
	if(!d[y]&&b[y]) {
		d[y] = d[x] + 1;
		q[rp++] = y;
	} 
}
int main(){
	INIT();
	int ttt; scanf("%d",&ttt);
	while(ttt--){
		init();
		int st,ed; scanf("%d%d",&st,&ed);
		st = encode(st); 
		ed = encode(ed);
		int ans = -1;
		q[rp++] = st; d[st] = 1;
		while(fp!=rp){
			int x = q[fp++], y;
			if(x==ed) {
				ans = d[x] - 1;
				break;
			}
			for(int i=0;i<10;i++) {
				release(x,(x&0xfff0)|i);
				release(x,(x&0xff0f)|(i<<4));
				release(x,(x&0xf0ff)|(i<<8));
				release(x,(x&0x0fff)|(i<<12));
			}
		}
		if(ans==-1) puts("Impossible");
		else printf("%d\n",d[ed]-1);
	}
	return 0;
}




