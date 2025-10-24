typedef long long ll;
class Solution {
public:
    int dim;
    static const int mod = (int)(1e9 + 7);
    typedef vector<vector<ll>> mat;
    mat tmp;
    mat& mul(mat& a, mat& b)
    {
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
            {
                tmp[i][j] = 0;
                for (int k = 0; k < dim; k++)
                    tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
            }
        return tmp;
    }

    mat exp(mat& a, int e)
    {
        int bit =  1;
        mat ans =  vector<vector<ll>>(dim, vector<ll>(dim, 0));
        for (int i = 0; i < dim; i++) ans[i][i] = 1;
        mat base = a;
        while (bit <= e)
        {
            if ((bit & e) == bit) ans = mul(ans, base);
            bit = bit << 1;
            base = mul(base, base);
        }
        return ans;
    }

    int zigZagArrays(int n, int l, int r) {
        int R = r - l + 1;
        dim = R * 2;
        tmp = vector<vector<ll>>(dim, vector<ll>(dim, 0));
        mat cur = vector<vector<ll>>(dim, vector<ll>(dim, 0));
        for (int i = 0; i < R; i++)
        {
            for (int k = 0; k < i; k++) cur[i][k + R] = 1;
            for (int k = i + 1; k < R; k++) cur[R + i][k] = 1;
        }

        mat m = exp(cur, n - 1);
        ll ans = 0;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                ans = (ans + m[i][j]) % mod;
        return ans;
    }
};