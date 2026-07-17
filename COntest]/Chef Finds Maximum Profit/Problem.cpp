#include <vector>
#include <algorithm>

using namespace std;

class Solution {
struct Job {
    int start, end, profit;
};

public:
    long long calculateMaxProfit(vector<int>& jobStartTimes,
                                 vector<int>& jobEndTimes,
                                 vector<int>& jobProfits)
    {
        int n = jobStartTimes.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {jobStartTimes[i], jobEndTimes[i], jobProfits[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.end < b.end;
        });

        vector<long long> dp(n);
        dp[0] = jobs[0].profit;

        for (int i = 1; i < n; ++i) {
            long long inclProfit = jobs[i].profit;
            int l = 0, r = i - 1;
            int lastNonOverlapping = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (jobs[mid].end <= jobs[i].start) {
                    lastNonOverlapping = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (lastNonOverlapping != -1) {
                inclProfit += dp[lastNonOverlapping];
            }

            dp[i] = max(inclProfit, dp[i - 1]);
        }

        return dp[n - 1];
    }
};