class Solution {
public:
    string addStrings(string num1, string num2) {
     int i=num1.size()-1, j=num2.size()-1;
        int l=(i>=j)?i:j, sum=0;
        string str;
        int k=l;
        str.resize(l+1);
        while(i>=0 || j>=0){
            if(i>=0){
                sum+=(num1[i--]-'0');
            }
            if(j>=0){
                sum+=(num2[j--]-'0');
            }
            str[k]=(sum%10)+'0';
            sum/=10;k--;
        }
        if(sum)
            str.insert(0,"1");
        return str;
    }
};