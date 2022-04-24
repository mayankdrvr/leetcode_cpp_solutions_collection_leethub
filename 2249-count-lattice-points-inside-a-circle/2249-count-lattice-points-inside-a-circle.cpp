class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int len=circles.size();
        set<pair<int,int>> s;
        for(int i=0;i<len;i++){
            int a=circles[i][0], b=circles[i][1], r=circles[i][2];
            for(int x=-r;x<=r;x++){
                for(int y=-r;y<=r;y++){
                    if((x*x+y*y)<=r*r)
                        s.insert({x+a,y+b});
                }
            }
        }
        return s.size();
    }
};