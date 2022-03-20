class Solution {
public:
    int pairs(string str1, string str2, int size){
        // Counting the frequency of numbers in str1 and str2.
        int f1[10] = { 0 };
        int f2[10] = { 0 };
        int i, c = 0;
        
        for (i = 0; i < size; i++)
          f1[str1[i] - '0']++;
        
        for (i = 0; i < size; i++)
          f2[str2[i] - '0']++;
        
        // Counting common characters in  the strings.
        for (i = 0; i < 10; i++)
          c += (min(f1[i], f2[i]));
        
        return c;
    }
    string getHint(string secret, string guess) {
        int a=0,b,n = secret.size();
        
        b=pairs(secret,guess,n); // Common characters 
        
        for(int i=0;i<n;i++) // Common characters with correct positions.
            if(secret[i]==guess[i])
                a++;
        
        // b contains all the common characters, so removing bulls.
        string res=to_string(a)+'A'+to_string(b-a)+'B'; 
        return res;
    }
};