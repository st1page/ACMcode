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
int mod;
void mmod(int &x){
	if(x>=mod) x%=mod;
}
int madd(int x,int y){
	mmod(x); mmod(y);
	return (x+y)>=mod?x+y-mod:x+y;
}
int mmul(int x,int y){
	mmod(x); mmod(y);
	return x*y%mod;
}
#define N 2
#define rp(i) for(int i=0;i<N;i++)
struct Mat{
	int a[N][N];
	void clr(){	memset(a,0,sizeof(a)); }
	Mat(){ clr(); }
	friend Mat operator *(Mat x,Mat y){
		Mat z; 
		rp(i) rp(j) rp(k)
			z.a[i][j]=madd(z.a[i][j],mmul(x.a[i][k], y.a[k][j]));
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
		a[0][0]=x; a[0][1]=y;
		a[1][0]=1; a[1][1]=x;
	}
}ans,trans;
int main(){
	int a,b,n;
	while(scanf("%d%d%d%d",&a,&b,&n,&mod)!=EOF){
		mmod(a); mmod(b);
		trans.trans(a,b);
		ans.a0(a,b);
		ans=(trans^n)*ans;
		printf("%d\n",madd(ans.a[0][0],ans.a[0][0]));
	}
	return 0;
}















