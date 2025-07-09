class Solution {
    public :
        vector<int> twoSum(Vector<int>& nums,int target){
            vector<int> ans;
            unorderd<int, int> mpp;
            for(int i = 0; i < num.size();i++){
                if(mpp.find(target - nums[i])!= mpp.end()){
                    ans.push_back(mpp[target - nums[i]]);
                    ans.push_back(i);
                }
                mpp[nums[i]] = i;
            }
            return ans; 
        }
}