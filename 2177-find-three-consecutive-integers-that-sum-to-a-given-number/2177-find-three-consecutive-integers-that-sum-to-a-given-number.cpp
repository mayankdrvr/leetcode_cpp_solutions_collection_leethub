class Solution {
public:
	vector<long long> sumOfThree(long long num) {
		if (num%3) return {};
		long long no = num/3;
		return {no-1, no,no+1};
	}
};