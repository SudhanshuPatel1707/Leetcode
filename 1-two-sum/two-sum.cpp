class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        multimap<int, int> mpp;
        for(int i = 0; i < n; i++)
        {
            mpp.insert(pair<int, int>(nums[i], i));
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = 0, j = n-1;
        while(i < j)
        {
            if(nums[i]+nums[j] < target)
            {
                i++;
            }
            else if(nums[i]+nums[j] == target)
            {
                auto itI = mpp.lower_bound(nums[i]);
                auto itJ = mpp.upper_bound(nums[j]);
                itJ--;
                ans.push_back(itI->second);
                ans.push_back(itJ->second);
                break;
            }
            else if(nums[i]+nums[j] > target)
            {
                j--;
            }
        }
        mpp.erase(mpp.begin(), mpp.end());
        return ans;
    }
};