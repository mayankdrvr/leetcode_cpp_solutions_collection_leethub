class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        map<string, bool>mp;
        string ans = "";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans += to_string(board[i][j]);
            }
        }
        queue<string>q;
        q.push(ans);
        int count = 0;
        while (q.size() != 0)
        {
              count++;
            int size = q.size();
            cout<<size<<endl;
            cout<<count<<endl;
            while (size--) {
                string temp = q.front();
                q.pop();
                if (mp.find(temp) != mp.end()) continue;
                mp[temp] = true;
                for (int i = 0; i < temp.length(); i++)
                {
                    if (temp[i] == '0')
                    {
                        if (i <= 2)
                        {
                            string l = temp;
                            swap(l[i], l[i + 3]);
                              if (mp.find(l) == mp.end())
                            q.push(l);
                        }
                        if (i > 2)
                        {
                            string l = temp;
                            swap(l[i], l[i - 3]);
                            if (mp.find(l) == mp.end())
                            q.push(l);
                        }
                        if (i == 1 || i == 4)
                        {
                            string l = temp;
                            swap(l[i], l[i - 1]);
                            if (mp.find(l) == mp.end())
                            q.push(l);
                            l = temp;
                            swap(l[i], l[i + 1]);
                            if (mp.find(l) == mp.end())
                            q.push(l);
                        }
                        if (i == 0 || i == 3)
                        {
                            string l = temp;
                            swap(l[i], l[i + 1]);
                            if (mp.find(l) == mp.end())
                            q.push(l);
                        }
                        if (i == 2 || i == 5)
                        {
                            string l = temp;
                            swap(l[i], l[i - 1]);
                            if (mp.find(l) == mp.end())
                            q.push(l);
                        }
                    }
                }
                
            }
              if (mp.find("123450") != mp.end()) return count-1;
            
          
        }
        return -1;
    }
};