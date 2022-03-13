class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size();
        int dir=1, l=0, r=n-1, t=0, b=m-1;
        vector<int> o;
        while(l<=r && t<=b){
            if(dir==1){
                for(int i=l;i<=r;i++)
                    o.push_back(a[t][i]);
                    t++;
                dir=2;
            }
            else if(dir==2){
                for(int i=t;i<=b;i++)
                    o.push_back(a[i][r]);
                    r--;
                dir=3;
            }
            else if(dir==3){
                for(int i=r;i>=l;i--)
                    o.push_back(a[b][i]);
                    b--;
                dir=4;
            }
            else if(dir==4){
                for(int i=b;i>=t;i--)
                    o.push_back(a[i][l]);
                    l++;
                dir=1;
            }
        }
        return o;
    }
};