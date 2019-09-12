#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 312345
char s[N];
char a[N*2];
int p[N*2];
int n,m;
int lst[30];
int ln[N*2][30], rn[N*2][30];
int mn[N*2][30];
long long ans=0;
int gtnum(int l,int r){
	if(a[l]=='#'&&a[r]!='#') return (r-l+1)/2; 
	else if(a[l]!='#'&&a[r]=='#') return (r-l+1)/2;
	else if(a[l]=='#'&&a[r]=='#') return (r-l+1-1)/2;
	else return (r-l+1+1)/2;
}
void init(){
	m=2*n+1;
	for (int i=1;i<=n;i++){
		a[i*2]=s[i];a[i*2+1]='#';
	}
	a[0]='+'; a[1]='#'; a[m+1]='-';
	int mx=0,id=0;
	for (int i=1;i<=m;i++){
		if (mx>i) p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while (a[i-p[i]]==a[i+p[i]]) p[i]++;
		if (i+p[i]>mx){
			mx=i+p[i];
			id=i;
		}
	}
	for(int i=0;i<26;i++) lst[i] = m*2;
	for(int i=1;i<=m;i++){
		if(a[i]>='a'&&a[i]<='z') lst[a[i]-'a']=i;
		for(int j=0;j<26;j++) ln[i][j]=lst[j];
	}
	for(int i=0;i<26;i++) lst[i] = m*2;	
	for(int i=m;i>=1;i--){
		if(a[i]>='a'&&a[i]<='z') lst[a[i]-'a']=i;
		for(int j=0;j<26;j++) rn[i][j]=lst[j];
	}
	for(int i=1;i<=m;i++) 
		for(int j=0;j<26;j++){
			int r1=p[i];
			if(ln[i][j]>m||rn[i][j]>m) continue;
			int r2=min(i-ln[i][j],rn[i][j]-i)+1;
			if(r2>r1) continue;
			if(i+r1-1>m) ans+=gtnum(i-r1+1,i-r2+1);
			else ans+=gtnum(i+r2-1,i+r1-1);
//			printf("%d,%c %d,%d    %d\n",i,j+'a',r1,r2,ans);
		}
}

int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	init();
//	for(int i=1;i<=m;i++) printf("%c",a[i]); putchar('\n');
//	for(int i=1;i<=m;i++) printf("%d ",p[i]); putchar('\n');
printf("%lld\n",ans);
	return 0;
}
