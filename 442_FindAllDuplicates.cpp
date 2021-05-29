//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
     vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1] < 0)
                    res.push_back(abs(nums[i]));
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]; 
//moves to an index at first sight, and is made negative. if the number is found again, then the absolute number is pushed to result vector.
        }
            return res;
    }
};
