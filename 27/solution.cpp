class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        int i = 0;
        int j = nums.size() - 1;
        while(i != j){
            if(nums[i] == val){
                if(nums[j] == val){
                    j--;
                }else{
                    swap(nums[i], nums[j]);
                    i++;
                }
            }else{
                i++;
            }
        }
        if(nums[i] == val){
            return i;
        }else{
            return i + 1;
        }
    }
    
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};
