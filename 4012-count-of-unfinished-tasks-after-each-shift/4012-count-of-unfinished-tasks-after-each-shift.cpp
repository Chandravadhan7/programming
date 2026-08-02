class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = shifts.size();
        int m = tasks.size();

        vector<long long> drelvanito(tasks.begin(), tasks.end());

        vector<long long> pre(m);
        pre[0] = tasks[0];

        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + tasks[i];

        vector<int> ans(n);

        long long carry = 0;

        for (int i = 0; i < n; i++) {
            long long available = carry + shifts[i];

            if (available >= pre.back()) {
                ans[i] = 0;
                carry = 0;
            } else {
                int id = upper_bound(pre.begin(), pre.end(), available) - pre.begin();
                ans[i] = m - id;
                carry = available;
            }
        }

        return ans;
    }
};