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
#define N 21234567
int val[112345];
struct data{
	int x,id;
}aa[112345];
bool cmp1(data x,data y){
	return x.x<y.x;
}
bool cmp2(data x,data y){
	return  x.id<y.id;
}
int ntot=0;
int ls[N],rs[N],cnt[N];
int root[112345];
int ins(int p,int l,int r,int y){
	int x=++ntot; 
	cnt[x] = cnt[p] + 1; 
	ls[x] = ls[p]; rs[x] = rs[p];
	if(l==r) return x;
	int mid=(l+r)/2;
	if(y<=mid) ls[x]=ins(ls[x],l,mid,y);
	else rs[x]=ins(rs[x],mid+1,r,y);
	return x;
}
int a[200];
int an;
//<=p mxk
int q1(int x,int y,int l,int r,int p,int k){
	if(cnt[y]-cnt[x]==0) return 0;
	if(l==r) {
		a[an++]=p-val[l];
		return 1;
	}
	int mid=(l+r)/2;
	if(p<val[mid+1]) return q1(ls[x],ls[y],l,mid,p,k);
	else {
		int res = q1(rs[x],rs[y],mid+1,r,p,k);
		if(k>res) res += q1(ls[x],ls[y],l,mid,p,k-res);
		return res;
	}
}
int b[200];
int bn;
// >p k
int q2(int x,int y,int l,int r,int p,int k){
	if(cnt[y]-cnt[x]==0) return 0;
	if(l==r) {
		b[bn++]=val[l]-p;
		return 1;
	}
	int mid=(l+r)/2;
	if(p>val[mid]) return q2(rs[x],rs[y],mid+1,r,p,k);
	else {
		int res = q2(ls[x],ls[y],l,mid,p,k);
		if(k>res) res += q2(rs[x],rs[y],mid+1,r,p,k-res);
		return res;
	}
}
//int a,b;
//int q2(int x,int y,int xl,int xr,int yl,int yr,,int xd,int yd,int p,int k){	
//}
int n,m;
void init(){
	ntot=0;
}

void solve(){
	n=gn(); m=gn();
	for(int i=1;i<=n;i++) aa[i].x=gn(), aa[i].id=i;
	sort(aa+1,aa+1+n,cmp1);
	for(int i=1;i<=n;i++) {
		val[i]=aa[i].x;
		aa[i].x=i;
	}
	sort(aa+1,aa+1+n,cmp2);
	for(int i=1;i<=n;i++) root[i]=ins(root[i-1],1,n,aa[i].x);
	int ans=0;
	while(m--){
		int l=gn()^ans; 
		int r=gn()^ans;
		int p=gn()^ans;
		int k=gn()^ans;
		an=bn=0;
		q1(root[l-1],root[r],1,n,p,k);
		q2(root[l-1],root[r],1,n,p,k);
		for(int i=0,j=0;i+j<k;){
			if((j==bn)||(i<an&&j<bn&&a[i]<b[j])) ans=a[i++];
			else ans=b[j++];
		}
		printf("%d\n",ans);
	}
}
int main(){
	int T = gn();
	while(T--){
		init();
		solve();
	}
}




