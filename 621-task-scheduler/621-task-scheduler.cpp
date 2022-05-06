class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        for(char ch: tasks){
            count[ch]++;
        }
        priority_queue<int> pq;
        for(auto c:count)
            pq.push(c.second);
        int result=0;
        while(!pq.empty()){
            vector<int> tmp;
            int time=0;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t:tmp){
                if(t)
                    pq.push(t);
            }
            result+=pq.empty()?time:n+1;
        }
        return result;
    }
};