
// Leetcode September Challenge : https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/
// Difficulty - Medium
// 565. Array Nesting - https://leetcode.com/problems/array-nesting/
// Time complexity : O(n)
// Space Complexity : o(n)

int arrayNesting(vector<int>& nums) {
	vector<bool> vis(nums.size(), false);
	int ans = 0;
	for(int i = 0; i < nums.size(); i++) {
		int cnt = 0;
		int start = nums[i];
		while(!vis[start]) {
			vis[start] = true;
			cnt++;
			start = nums[start];
		}
		ans = max(ans, cnt);
	}
	return ans;
}

// Time complexity : O(n)
// Space Complexity : o(1)

int arrayNesting(vector<int>& nums) {
	int ans = 0;
	for(int i = 0; i < nums.size(); i++) {
		int cnt = 0;
		int start = nums[i];
		nums[i] = -1;
		while(start >= 0) {
			cnt++;
			int temp = start;
			start = nums[start];
			nums[temp] = -1;
		 }
		ans = max(ans, cnt);
	}
	return ans;
}
