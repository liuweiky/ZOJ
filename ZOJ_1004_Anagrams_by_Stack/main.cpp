#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string src, tgt;
int len;
vector<string> ans;

void dfs(stack<char> stk, string seq, int src_ptr, int tgt_ptr)
{
    //cout << seq << " " << src_ptr << " " << tgt_ptr << endl;
    if (src_ptr == len && tgt_ptr == len && stk.size() == 0)
    {
        ans.push_back(seq);
        return;
    }
    if (stk.size() != 0 && stk.top() == tgt[tgt_ptr])
    {
        if (tgt_ptr < len)
        {
            stack<char> tmp = stk;
            tmp.pop();
            dfs(tmp, seq + "o", src_ptr, tgt_ptr + 1);
        }

        if (src_ptr < len)
        {
            stk.push(src[src_ptr]);
            dfs(stk, seq + "i", src_ptr + 1, tgt_ptr);
        }
    }
    else if (src_ptr < len)
    {
        stk.push(src[src_ptr]);
        dfs(stk, seq + "i", src_ptr + 1, tgt_ptr);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> src)
    {
        ans.clear();
        cin >> tgt;
        len = tgt.size();
        stack<char> stk;
        dfs(stk, "", 0, 0);
        int sz = ans.size();
        sort(ans.begin(), ans.end());
        cout << '[' << endl;
        for (int i = 0; i < sz; i++)
        {
            int l = ans[i].size();
            for (int j = 0; j < l; j++)
                cout << ans[i][j] << ' ';
            cout << endl;
        }
        cout << ']' << endl;
    }
    return 0;
}
