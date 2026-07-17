class Solution:
    def subarraysWithKDistinct(self, nums, k):
        def atMostK(arr, k):
            count = {}
            res = left = 0
            for right in range(len(arr)):
                count[arr[right]] = count.get(arr[right], 0) + 1
                while len(count) > k:
                    count[arr[left]] -= 1
                    if count[arr[left]] == 0:
                        del count[arr[left]]
                    left += 1
                res += right - left + 1
            return res

        return atMostK(nums, k) - atMostK(nums, k - 1)