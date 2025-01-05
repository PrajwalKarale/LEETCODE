auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
#define MOD 1000000007
typedef long long ll;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> powers;
        vector<int> result;
        int exponent = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                powers.push_back(exponent);
            }
            exponent++;
            n /= 2;
        }
        vector<ll> prefix(powers.size(), 0);
        prefix[0] = powers[0];
        for (int i = 1; i < powers.size(); i++) {
            prefix[i] = prefix[i - 1] + powers[i];
        }
        for (vector<int>& query : queries) {
            int left = query[0];
            int right = query[1];
            ll power;

            if (left == 0) {
                power = prefix[right];
            } else {
                power = prefix[right] - prefix[left - 1];
            }
            result.push_back((int)modExp(2, power, MOD));
        }

        return result;
    }

private:
    ll modExp(ll base, ll exp, ll mod) {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};
