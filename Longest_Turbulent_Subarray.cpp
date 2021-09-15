
// Leetcode September Challenge : https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3976/
// Difficulty - Medium
// 565. Array Nesting - https://leetcode.com/problems/longest-turbulent-subarray/
// Time complexity : O(n)
// Space Complexity : o(1)

int maxTurbulenceSize(vector<int>& arr) {
	int ans = 1;
	int inc = 1;
	int dec = 1;
	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] < arr[i - 1]) {
			dec = inc + 1;
			inc = 1;
		}
		else if(arr[i] > arr[i - 1]) {
			inc = dec + 1;
			dec = 1;
		}
		else {
			inc = 1;
			dec = 1;
		}
		ans = max(ans, max(inc, dec));
	}
	return ans;
}

// Time complexity : O(n)
// Space Complexity : o(1)

int maxTurbulenceSize(vector<int>& arr) {
	int ans = 1;
	int cnt = 1;
	if(arr.size() == 1) return 1;
	int prev = arr[0] - arr[1];
	if(prev != 0) cnt = 2;
	for(int i = 1; i < arr.size() - 1; i++) {
		int temp = arr[i] - arr[i + 1];
		if((temp < 0 and prev > 0) or (temp > 0 and prev < 0)) {
			cnt++;
		}
		else if(temp != 0) cnt = 2;
		ans = max(ans, cnt);
		prev = temp;
	}
	ans = max(ans, cnt);
	return ans;
}
