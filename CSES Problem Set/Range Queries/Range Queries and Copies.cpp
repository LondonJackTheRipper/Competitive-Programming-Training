#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 2e5 + 9;
const int segsize = 40 * maxn;
 
class Segment_Tree
{
public:
	struct Node
	{
		ll sum;
		int l, r;
		Node *left, *right;
		
		Node(int l = 0, int r = 0) : l(l), r(r), sum(0ll), left(0), right(0) {}
		Node(Node *node) : sum(node->sum), l(node->l), r(node->r), left(node->left), right(node->right) {}
		
		bool isleaf() { return l == r; }
		int middle() { return l + r >> 1; }
		void addsum() { sum = left->sum + right->sum; }
		bool notcover(int pos) { return pos < l || r < pos; }
		bool cover(int pos) { return l <= pos && pos <= r; }
		bool notIntersect(int u, int v) { return l > v || r < u; }
		bool nested(int u, int v) { return u <= l && r <= v; }
		
		void SummonChild()
		{
			left = new Node(l, middle());
			right = new Node(middle() + 1, r);
		}
		
		void CloneChild()
		{
			if (left) left = new Node(left);
			if (right) right = new Node(right);
		}
	};	
	
	static Node st[segsize];
	static int cnt;
	
	static Node* newNode(int l, int r)
	{
		st[cnt] = Node(l, r);
		return &st[cnt++];
	}
	
	static Node* newNode(Node *node)
	{
		st[cnt] = Node(node);
		return &st[cnt++];
	}
	
	vector<Node*> roots;
	int n;
	int t = 0;
	
	Segment_Tree(int n) : n(n) {}
	
	void build(Node *cur, ll *arr)
	{
		if (cur->isleaf())
		{
			cur->sum = arr[cur->l];
			return;
		}
		
		cur->SummonChild();
		
		build(cur->left, arr);
		build(cur->right, arr);
		
		cur->addsum();
	}
	
	Node* update(Node *cur, int pos, int val)
	{
		if (cur->notcover(pos)) return cur;
		Node *clone = newNode(cur);
		if (cur->isleaf())
		{
			clone->sum = val;
			return clone;
		}
		
		clone->left = update(clone->left, pos, val);
		clone->right = update(clone->right, pos, val);
		
		clone->addsum();
		
		return clone;
	}
	
	ll query(Node *cur, int u, int v)
	{
		if (cur->notIntersect(u, v)) return 0ll;
		if (cur->nested(u, v)) return cur->sum;
		
		return query(cur->left, u, v) + query(cur->right, u, v);
	}
	
	void build(ll *arr)
	{
		roots.push_back(newNode(1, n));
		build(roots.back(), arr);
	}
	
	void update(int k, int pos, int val)
	{
		roots[k - 1] = update(roots[k - 1], pos, val);
	}
	
	void query(int k, int u, int v)
	{
		cout << query(roots[k - 1], u, v) << '\n';
	}
	
	void copy(int k)
	{
		roots.push_back(newNode(roots[k - 1]));
	}
};
 
Segment_Tree::Node Segment_Tree::st[segsize];
int Segment_Tree::cnt = 0;
 
ll arr[maxn];
int n, q;
 
int main()
{
	faster();
 
	cin >> n >> q;
	
	Segment_Tree seg(n);
	
	for (int i = 1; i <= n; i++) cin >> arr[i];
	seg.build(arr);
	
	while (q--)
	{
		int type; 
		cin >> type;
		
		if (type == 1)
		{
			int k, a, x;
			cin >> k >> a >> x;
			seg.update(k, a, x);
		} else 
		if (type == 2)
		{
			int k, a, b; 
			cin >> k >> a >> b;
			seg.query(k, a, b);
		} else 
		{
			int k;
			cin >> k;
			seg.copy(k);
		}
	}
 
	return 0;
}
