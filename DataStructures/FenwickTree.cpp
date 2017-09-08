// Wsl_F
#include <bits/stdc++.h>


using namespace std;

typedef long long LL;


class FenwickTree
{
private:
    vector<LL> t;
    int size;

public:
    FenwickTree() {}

    FenwickTree(int n)
    {
        init(n);
    }

    void init(int n)
    {
        size = n;
        t.assign(size, 0);
    }

    LL sum(int r)
    {
        LL result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            result += t[r];
        return result;
    }

    void inc(int i, LL delta)
    {
        for (; i < size; i = (i | (i+1)))
            t[i] += delta;
    }

    LL sum(int l, int r)
    {
        return sum (r) - sum (l-1);
    }

    LL val(int i)
    {
        return sum(i, i);
    }
};

void example1() // https://www.e-olymp.com/en/problems/2941
{
    int n, q;
    cin >> n >> q;

    FenwickTree ft(n+1);
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        ft.inc(i, t);
    }

    for (int qr = 0; qr < q; qr++)
    {
        char c;
        cin >> c;
        if (c == '=')
        {
            int ind, newVal;
            cin >> ind >> newVal;
            int oldVal = ft.val(ind);
            ft.inc(ind, newVal - oldVal);
        }
        else
        { // c == '?'
            int from, to;
            cin >> from >> to;
            cout << ft.sum(from, to) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    example1();

    return 0;
}
