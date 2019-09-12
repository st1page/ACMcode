/*

*/
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
#define M 2147493647
void mmod(ll &x){
	if(x>=M) x%=M;
}
ll madd(ll x,ll y){
	mmod(x); mmod(y);
	return x+y>=M?x+y-M:x+y;
}
ll mmul(ll x,ll y){
	mmod(x); mmod(y);
	return x*y>=M?x*y%M:x*y;
}
#define N 7
#define rep(i) for(int i=0;i<N;i++)
struct Mat{
	ll a[N][N];
	void out(){
		rep(i){
			rep(j) printf("%d ",a[i][j]); 
			putchar('\n');
		}
		putchar('\n');
	}
	void clr(){
		memset(a,0,sizeof(a));
	}
	Mat(){
		clr();
	}
	void I(){
		clr();
		rep(i) a[i][i]=1;
	}
	void trans(){
		clr();
		for(int i=0;i<=4;i++) a[i][0]=1;
		for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) a[i][j] = a[i-1][j-1] + a[i-1][j];
		a[5][4]=1; a[5][5]=1; a[5][6]=2;
		a[6][5]=1;
	}
	void a0(int aa,int bb){
		a[0][0]=1;
		for(int i=1;i<=4;i++) a[i][0] = a[i-1][0]*3;
		a[6][0]=aa;
		a[5][0]=bb;
	}
	friend Mat operator *(Mat x,Mat y){
		Mat z; 
		rep(i) rep(j) rep(k){
			z.a[i][j] = madd(z.a[i][j], mmul(x.a[i][k], y.a[k][j]));
		}
		return z;
	}
	friend Mat operator ^(Mat x,ll y){
		Mat z; z.I();
		for(;y;y>>=1,x=x*x) if(y&1) z=z*x;
		return z;
	}
}trans; 
int main(){
	int T; scanf("%d",&T);
	trans.trans();
//	trans.out();
	while(T--){
		int n;
		ll a,b;
		scanf("%d%lld%lld",&n,&a,&b);
		mmod(a); mmod(b);
		if(n==1) printf("%lld\n",a);
		else if(n==2) printf("%lld\n",b);
		else {
			Mat ans; ans.a0(a,b);
//			ans.out();
			ans = (trans^(n-2))*ans;
			printf("%lld\n",ans.a[5][0]);
		}
	}
	return 0;
}




