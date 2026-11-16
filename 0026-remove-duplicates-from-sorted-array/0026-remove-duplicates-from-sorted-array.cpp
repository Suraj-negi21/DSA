class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> g;

        for(int i = 0; i < nums.size(); i++) {
            g.insert(nums[i]);
        }

        int j = 0;

        for(auto x : g) {
            nums[j] = x;
            j++;
        }

        return j;
    }
};