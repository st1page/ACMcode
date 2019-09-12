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
#define N 1123456
int m;
int madd(int x,int y){
	x+=y; if(x>=m) x-=m;
	return x;
}
int mmul(int x,int y){
	if(x>=m)x%=m;
	if(y>=m)y%=m;
	return x*y%m;
}
struct Mat{
	int a[3][3];
	void clr(){
		memset(a,0,sizeof(a));
	}
	void out(){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++) printf("%d ",a[i][j]);
			putchar('\n');
 		} putchar('\n');
	}
	void I(){
		clr();
		for(int i=0;i<3;i++) a[i][i]=1;
	}
	void trans(){
		clr();
		a[0][0]=1; a[0][1]=1; a[0][2]=1;
		a[1][0]=1;
							  a[2][2]=1;
	}
	void a0(){
		clr();
		a[0][0]=1;
		a[1][0]=1;
		a[2][0]=1;
	}
	Mat(){
		clr();
	}
	friend Mat operator *(Mat x, Mat y){
		Mat z;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++){
			z.a[i][j]=madd(z.a[i][j],mmul(x.a[i][k],y.a[k][j]));
		}
		return z;
	}
	friend Mat operator ^(Mat x, ll y){
		Mat z; z.I();
		for(;y;y>>=1,x=x*x) if(y&1) z=z*x;
		return z;
	}
}trans;
int main(){
	trans.trans();
	ll n; int cas=1; 
	for(scanf("%lld%d",&n,&m);n||m;cas++,scanf("%lld%d",&n,&m)){
		if(n==0) printf("Case %d: %lld %d %d\n",cas,n,m,1%m);
		else {
			Mat ans; ans.a0();
			ans=(trans^(n-1))*ans;
			printf("Case %d: %lld %d %d\n",cas,n,m,ans.a[0][0]);
		}
	}
	
}




