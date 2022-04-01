class Solution {
public:
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>mp;
    string s;
    for(auto &a: strs){
        s=a;
        sort(s.begin(),s.end());
        mp[s].push_back(a);}
    vector<vector<string>>vec;
    for(auto &a: mp)
        vec.push_back(a.second);
    return vec;
}
};