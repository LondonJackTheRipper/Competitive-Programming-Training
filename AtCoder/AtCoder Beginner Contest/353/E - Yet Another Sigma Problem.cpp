#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

// main program
struct Trie
{
    struct Node
    {
        Node *child[26];
        int prefix;

        Node()
        {
            prefix = 0;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node *root;
    Trie() { root = new Node(); }

    void add(string s)
    {
        Node *p = root;
        for (char c : s)
        {
            int num = c - 'a';

            if (p->child[num] == nullptr)
                p->child[num] = new Node();

            p = p->child[num];
            p->prefix++;
        }
    }

    ll count_prefix(string s)
    {
        Node *p = root;
        vector<pair<int, int>> tmp;
        int l = 0;

        for (char c : s)
        {
            int num = c - 'a';

            if (p->child[num] == nullptr)
                p->child[num] = new Node();

            p = p->child[num];

            if (p->prefix == 0) break;
            l++;
            tmp.push_back({p->prefix, l});
        }

        int accu = 0;
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            tmp[i].first -= accu;
            accu += tmp[i].first;
        }
        ll res = 0;
        for (int i = 0; i < tmp.size(); i++)
            res += 1ll * tmp[i].second * tmp[i].first;

        return res;
    }
};

void solve()
{
    int n; cin >> n;

    ll res = 0;
    Trie T;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;

        res += T.count_prefix(s);
        T.add(s);
    }

    cout << res << '\n';
}
