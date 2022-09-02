class Solution {
public:
    int maxArea(vector<int>& height) {
	    // Optimal Solution Time O(N) & Auxiliary Space O(1)
        int len=height.size();
        int max=0,left=0,right=len-1,area=0;
        while(left<right){
            if(height[left]<height[right]){
                area=height[left]*(right-left);
                left++;
            }
            else{
                area=height[right]*(right-left);
                right--;
            }
            if(area>max)
                max=area;
        }
        return max;
    }
};