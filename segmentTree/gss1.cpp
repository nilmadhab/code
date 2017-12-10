#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 50001
 
class Data
{
public:
	int sum, prefix, middle, suffix, best;
	Data()
	{
		sum = prefix = middle = suffix = best = -15008;
	}
};
 
int ar[MAXN];
Data tree[MAXN<<2];
 
class SegmentTree
{
	int n;
 
	void set(int node, int val)
	{
		tree[node].sum = 
		tree[node].prefix = 
		tree[node].middle = 
		tree[node].suffix = 
		tree[node].best = val;
	}
 
	void calc(int node, Data &d, Data &lChild, Data &rChild)
	{
		d.sum = lChild.sum + rChild.sum;
		d.prefix = max(lChild.prefix, lChild.sum + rChild.prefix);
		d.suffix = max(rChild.suffix, lChild.suffix + rChild.sum);
		d.middle = lChild.suffix + rChild.prefix;
		d.best = max({d.sum, d.prefix, d.middle, d.suffix, lChild.best, rChild.best});
	}
 
	void build(int s, int e, int node)
	{
		if(s==e) //leaf
			set(node,ar[s]);
		else
		{
			int m = s + (e-s)/2;
			build(s, m, 2*node);
			build(m+1, e, 2*node+1);
			calc(node, tree[node], tree[2*node], tree[2*node+1]);
		}
	}
 
	Data query(int l, int r, int s, int e, int node)
	{
		Data d;
		if(s>r || e<l)
			return d;
		else if(s>=l && e<=r)
			return tree[node];
 
		int m = s+(e-s)/2;
		if(l>m)
			return query(l,r,m+1,e,2*node+1);
		else if(r<=m)
			return query(l,r,s,m,2*node);
		else
		{
			Data lQuery = query(l,r,s,m,2*node);
			Data rQuery = query(l,r,m+1,e,2*node+1);
			calc(node,d,lQuery,rQuery);
			return d;
		}
	}
 
public:
	SegmentTree(int n)
	{
		this->n = n;
		build(1,n,1);
	}
 
	int query(int l, int r)
	{
		return query(l,r,1,n,1).best;
	}
 
};
 
int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&ar[i]);
 
	SegmentTree st(n);
	int q; scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",st.query(l,r));
	}
	return 0;
}
 