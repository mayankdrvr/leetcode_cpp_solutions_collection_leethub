class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Optimal Solution
        // Product of left and right subarray method
        int len=nums.size();
        vector<int> res;
        if(len<1)
            return res;
        int prod=1; // prod will store the product of all 
                    // the elements to the right of nums[i]
        for(int i=0;i<len;++i)
        {   // Create left product array(res) where each element
            // is the product of the current element(nums[i]) and  
            // all the elements that came before it 
            prod*= nums[i];
            res.push_back(prod);            
        }
        prod=1;
        for(int i=len-1;i>0;--i)
        {   // Traverse res array from the end to the beginnng
            // and update each element(res[i]) by multiplying the previous
            // left product array element(res[i-1]) with the 
            // product of all the elements to the right of nums[i].
            // Store the result in res[i]
            res[i]=res[i-1]*prod;
            // Multiply nums[i] with prod as
            // prod will be the variable storing product of
            // all the elements to the right of current nums[i]
            prod*=nums[i];
        }
        // res[0] has no elements to the left. So,
        // it will store the product of all elements 
        // to the right of nums[0]
        res[0]=prod;
        return res;
    }
};