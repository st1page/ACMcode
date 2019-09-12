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
#define N 52 
int k;
#define rp(i) for(int i=0;i<=k+1;i++)
struct Mat{
	unsigned int a[N][N];
	void clr(){	memset(a,0,sizeof(a)); }
	Mat(){ clr(); }
	void out(){
		for(int i=0;i<=k+1;i++){
			for(int j=0;j<=k+1;j++) printf("%d ",a[i][j]);
			putchar('\n');
		} putchar('\n');
	}
	friend Mat operator *(Mat x,Mat y){
		Mat z; 
		rp(i) rp(j) rp(kk)
			z.a[i][j]+=x.a[i][kk] * y.a[kk][j];
		return z;
	}
	friend Mat operator ^(Mat x,ll y){
		Mat z; z.I();
		for(;y;y>>=1,x=x*x) if(y&1) z=z*x;
		return z;
	}
	void I(){
		clr();
		rp(i) a[i][i]=1;
	}
	void a0(){
		clr();
		a[0][0]=1;
	}
	void trans(){
		clr();
		for(int i=0;i<=k;i++) a[i][0] = 1;
		for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) a[i][j]=a[i-1][j] + a[i-1][j-1];
		for(int i=0;i<=k;i++) a[k+1][i]=a[k][i]; 
		a[k+1][k+1]=1;
	}
}ans,trans;
int main(){
	int T; scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		ll n;
		scanf("%lld%d",&n,&k);
		ans.a0(); trans.trans();
		ans=(trans^n)*ans;
		printf("Case %d: %u\n",cas,ans.a[k+1][0]);
	}
	return 0;
}















