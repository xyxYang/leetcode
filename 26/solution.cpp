class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int count = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != nums[count]){
                nums[count+1] = nums[i];
                count++;
            }
        }
        return count+1;
    }
};
