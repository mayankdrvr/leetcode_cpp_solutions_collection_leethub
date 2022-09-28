class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int count=0;
        int str_len=strs.size(), min=INT_MAX, min_i=0,dummy=0;
        if(str_len==1)
            return strs[0];
        for(int i=0;i<str_len;i++){
            min_i=strs[i].length();
            if(min_i<min)
                min=min_i;
        }
        //cout<<"min="<<min<<endl;
        for(int j=0;j<min  && dummy==0;j++){
            int letter=0;
            for(int i=0;i<str_len-1  && dummy==0;i++){
                if(strs[i].at(j)==strs[i+1].at(j))
                    letter++;
                else
                    dummy=-1;
                if(letter==str_len-1)
                    count++;
            }
            //cout<<"letter="<<letter<<endl;
        }
        
    for(int i=0;i<count;i++){
        res.push_back(strs[0].at(i));
    }
    return res;
    }
};