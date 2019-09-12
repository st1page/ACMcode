/*
有点麻烦的矩阵构造
An*An-1一项展开时只需要展开An即可，An-1在前一个矩阵中已求出
6*6矩阵TLE 只需要维护 An^2 An-1^2 An*An-1 Sn 四项即可 An An-1无需维护 
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
const int M = 10007;
void mmod(int &x){
	if(x>=M) x%=M;
}
int madd(int x,int y){
	mmod(x); mmod(y);
	return (x+y>=M)?x+y-M:x+y;
}
int mmul(int x,int y){
	mmod(x); mmod(y); return x*y%M;
}
struct Mat {
	int a[6][6];
	void clr(){
		memset(a,0,sizeof(a));
	}
	Mat(){
		clr();
	}
	void I(){
		clr();
		for(int i=0;i<6;i++) a[i][i]=1;
	}
	void trans(int x,int y){
		clr();
		a[0][0]=x; a[0][1]=y;
		a[1][0]=1;
		a[2][2]=mmul(x,x); a[2][3]=mmul(y,y); a[2][4]=mmul(2*x,y);
		a[3][2]=1;
		a[4][2]=x; a[4][4]=y;
		a[5][2]=mmul(x,x); a[5][3]=mmul(y,y); a[5][4]=mmul(2*x,y); a[5][5]=1;
	}
	void a0(){
		clr();
		a[0][0]=1; 
		a[1][0]=1;
		a[2][2]=1;
		a[3][2]=1;
		a[4][2]=1;
		a[5][2]=2;
	}
	void out(){
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++) printf("%d ",a[i][j]);
			putchar('\n');
 		} putchar('\n');
	}
	friend Mat operator *(Mat x,Mat y){
		Mat z;
		for(int i=2;i<6;i++) for(int j=2;j<6;j++) for(int k=2;k<6;k++) {
			z.a[i][j]=madd(z.a[i][j],mmul(x.a[i][k],y.a[k][j]));
		}
		return z;
	}
	friend Mat operator ^(Mat x,int y){
		Mat z; z.I();
		for(;y;y>>=1,x=x*x) if(y&1) z=z*x;
		return z;
	}
}trans;
int main(){
	int n,x,y;
	while(scanf("%d%d%d",&n,&x,&y)!=EOF){
		mmod(x); mmod(y);
		trans.trans(x,y);
		Mat ans; ans.a0();
		ans = (trans^(n-1))*ans;
		printf("%d\n",ans.a[5][2]);
	}
}




