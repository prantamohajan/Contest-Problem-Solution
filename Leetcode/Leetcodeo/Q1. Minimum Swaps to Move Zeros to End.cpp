class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // Count number of non-zero elements
        int non_zeros = 0;
        for (int x : nums) {
            if (x != 0) {
                non_zeros++;
            }
        }
        
        // If no zeros or all zeros, no swaps needed
        if (non_zeros == 0 || non_zeros == n) {
            return 0;
        }
        
        // Count zeros in the first 'non_zeros' positions
        int zeros_in_prefix = 0;
        for (int i = 0; i < non_zeros; i++) {
            if (nums[i] == 0) {
                zeros_in_prefix++;
            }
        }
        
        return zeros_in_prefix;
    }
};