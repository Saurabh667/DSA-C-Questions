class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                    mid = start + (end - start) / 2;
                } else {
                    start = mid + 1;
                    mid = start + (end - start) / 2;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                    mid = start + (end - start) / 2;
                } else {
                    end = mid - 1;
                    mid=start+(end-start)/2;
                }
            }
        }
        return -1;
    }
};