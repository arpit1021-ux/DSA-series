class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            // If this number was seen before
            if (mp.find(nums[i]) != mp.end()) {

                int previousIndex = mp[nums[i]];

                // Check distance between previous and current occurrence
                if (i - previousIndex <= k) {
                    return true;
                }
            }

            // Update last seen index of current number
            mp[nums[i]] = i;
        }

        return false;
    }
};