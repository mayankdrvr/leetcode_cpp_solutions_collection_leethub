class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==1){
            return (gas[0]>=cost[0])?0:-1;
        }
        int tempsum=0,startind=-1,totsum=0;
        for(int i=0;i<gas.size();i++){
            int d=gas[i]-cost[i];
            if(startind<0){
                if(d>0){
                    tempsum+=d;
                    startind=i;
                }
            }
            else{
                tempsum+=d;
                if(tempsum<0){
                    tempsum=0;
                    startind=-1;
                }
            }
            totsum+=d;
        }
        if(totsum>=0)
            return startind;
        else
            return -1;
    }
};