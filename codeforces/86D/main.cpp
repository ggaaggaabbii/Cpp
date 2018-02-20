#include <iostream>
#include <cmath>
#include <algorithm>
#define maxb 100000
#define MAXQ 200010
#define MAXN 1000010
using namespace std;
int poz(maxb);
char buf[maxb];
int a,n,v[MAXQ],m,nr,r,l;
long long rez,rezultat[MAXQ];
int ap[MAXN];
struct query{
    int l;
    int r;
    int poz;
    int buc;
} w[MAXQ];
int getint()
{
    int nr=0;
    while(buf[poz]<'0'||buf[poz]>'9')
        if(++poz>=maxb)
        {
            cin.read(buf,maxb);
            poz=0;
        }
    while(buf[poz]>='0'&&buf[poz]<='9')
    {
        nr=nr*10+buf[poz]-'0';
        if(++poz>=maxb)
        {
            cin.read(buf,maxb);
            poz=0;
        }
    }
    return nr;
}
bool cmp(query a, query b)
{
    if (a.buc==b.buc)
        return a.r < b.r;
    return a.buc < b.buc;
}
void add(int poz)
{
    rez+=1ll*(2*ap[v[poz]]+1)*v[poz];
    ++ap[v[poz]];
}
void re(int poz)
{
    --ap[v[poz]];
    rez-=1ll*(2*ap[v[poz]]+1)*v[poz];
}
int main()
{
    n=getint();
    m=getint();
    for(int i=1; i<=n; ++i)
        v[i]=getint();
    nr=sqrt(n);
    for(int i=1; i<=m; ++i)
    {
        w[i].l=getint();
        w[i].r=getint();
        w[i].poz=i;
        w[i].buc=w[i].l/nr;
    }
    sort(w+1,w+m+1,cmp);
    for(int i=1;i<=m;++i)
    {
        while(r<w[i].r)
        {
            ++r;
            add(r);
        }
        while(r>w[i].r)
        {
            re(r);
            --r;
        }
        while(l>w[i].l)
        {
            --l;
            add(l);
        }
        while(l<w[i].l)
        {
            re(l);
            ++l;
        }
        rezultat[w[i].poz]=rez;
    }
    for(int i=1;i<=m;++i)
        cout<<rezultat[i]<<'\n';
    return 0;
}
