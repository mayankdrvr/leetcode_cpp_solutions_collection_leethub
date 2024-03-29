class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		// Optimal Solution Time O(N^2) & Auxiliary Space O(1)
        int n=matrix.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};