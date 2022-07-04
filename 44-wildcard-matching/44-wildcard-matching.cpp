class Solution {
public:
    bool isMatch(string s, string p) {
        bool star = 0;
        return isMatch(star,0,0,s,p);    
    }
    bool isMatch(bool& star, int i, int j, string& s, string& p) {
        int sn = s.size();
        if(j==p.size()) return i==sn;
        if(p[j]=='*') {
            for(int k=i;k<=sn;k++) {
                if(isMatch(star,k,j+1,s,p)) return 1;
                if(star) return 0;
            }
            star = 1;
            return 0;
        }
        if(i<sn && (p[j]=='?'||s[i]==p[j])) return isMatch(star,i+1,j+1,s,p);
        return 0;
    }
};