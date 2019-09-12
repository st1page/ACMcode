#include <cstdio>
#include <iostream>
#include <cstring>
 
using namespace std;
typedef long long ll;
 
int getint(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 212345
#define getmid int mid=(l+r)>>1; 
#define ls (i<<1)
#define rs (i<<1|1)
#define lm (mid)
#define rm (mid+1)
const int inf=1e9;
int nxt[]={2,0,1,9};
int tr[N<<2][5][5];
void init(int a[5][5],int x){
	for(int i=0;i<5;i++) for(int j=i;j<5;j++) a[i][j]=1e9;
	for(int i=0;i<4;i++){
		if(x==nxt[i]) a[i][i+1]=0,a[i][i]=1;
		else a[i][i]=0;
	}
	if(x==8){
		a[4][4]=1; a[3][3]=1; 
	}else a[4][4]=0;
	return ;
}
void merge(int a[5][5],int b[5][5],int c[5][5]){
	int z;
	for(int i=0;i<5;i++)
		for(int k=i;k<5;k++){
			z=1e9;
			for(int j=i;j<=k;j++) z=min(z,a[i][j]+b[j][k]);
			c[i][k]=z;
		}
	return ;
}
char t[N];
char s[N];
void build(int i,int l,int r){
	if(l==r) {
		init(tr[i],s[l]-'0');
		return ;
	}
	getmid
	build(ls,l,lm); build(rs,rm,r);
	merge(tr[ls],tr[rs],tr[i]);
	return ;
}
int ans[5][5];
int tmp[5][5];
void query(int l,int r,int i,int fl,int fr){
	if(fl<=l&&r<=fr) {
		if(fl==l){
			for(int ii=0;ii<5;ii++) for(int j=0;j<5;j++) ans[ii][j]=tr[i][ii][j];	
		}
		else {
			merge(ans,tr[i],tmp);
			swap(ans,tmp);
		}
		return ;
	}
	getmid
	if(fr<=lm) query(l,lm,ls,fl,fr);
	else if(fl>=rm) query(rm,r,rs,fl,fr);
	else {
		query(l,lm,ls,fl,fr); query(rm,r,rs,fl,fr);	
	}
}
int main(){
	int n=getint(),m=getint();	
	scanf("%s",t+1);
	for(int i=1;i<=n;i++) s[i]=t[n-i+1];
	build(1,1,n);
	while(m--){
		int fr=n-getint()+1,fl=n-getint()+1;
		query(1,n,1,fl,fr);
		int x=ans[0][4];
		if(x>n) printf("-1\n");
		else printf("%d\n",x);
	}
}

