class Solution {
public:
    long long dp[16][2][2][11];

    long long topdown(int pos, bool limit, bool leadingzero,
                      int prev, string &s, int k) {

        if (pos == s.size()) {
            return 1;
        }

        if (dp[pos][limit][leadingzero][prev] != -1) {
            return dp[pos][limit][leadingzero][prev];
        }

        long long count = 0;

        int maxDigit = limit ? s[pos] - '0' : 9;

        for (int d = 0; d <= maxDigit; d++) {

            bool newLimit = limit && (d == s[pos] - '0');

            if (leadingzero && d == 0) {

                count += topdown(
                    pos + 1,
                    newLimit,
                    true,
                    10,
                    s,
                    k
                );

            } else {

                if (leadingzero || abs(d - prev) <= k) {

                    count += topdown(
                        pos + 1,
                        newLimit,
                        false,
                        d,
                        s,
                        k
                    );
                }
            }
        }

        return dp[pos][limit][leadingzero][prev] = count;
    }

    long long solve(long long num, int k) {

        if (num < 0) return 0;

        string s = to_string(num);

        memset(dp, -1, sizeof(dp));

        return topdown(0, true, true, 10, s, k);
    }

    long long goodIntegers(long long l, long long r, int k) {

        long long right = solve(r, k);
        long long left = solve(l - 1, k);

        return right - left;
    }
};