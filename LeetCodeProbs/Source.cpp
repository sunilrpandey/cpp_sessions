#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vec_out(2);
		for (auto i = 0; i < nums.size() - 1; i++) {
			vec_out[0] = i;
			auto to_find = target - nums[i];
			for (auto j = i + 1; j < nums.size(); j++) {
				if (to_find == nums[j]) {
					vec_out[1] = j;
					return vec_out;
				}
			}
		}
		return vec_out;
	}
	vector<int> productExceptSelf(vector<int>& nums) {
		int prod = 1;
		int num_zero = 0;
		int zero_index = 0;
		int i = 0;
		for (auto n : nums) {
			if (n)
				prod *= n;
			else {
				num_zero++;
				zero_index = i;
			}
			i++;
		}

		cout << "prod = " << prod << "\n num zero : " << num_zero << endl;
		vector<int> vec_out(nums.size(), 0);
		if (num_zero > 1) {
			return vec_out;
		}
		else if (num_zero == 1) {
			vec_out[zero_index] = prod;
		}
		else {
			vec_out = nums;
			for (auto& n : vec_out) {
				n = prod / n;
			}
		}

		return vec_out;
	}
};

void test()
{
	Solution sln;
#if 0
	vector<int> vec_in{ 2,3,4 };
	auto vec_out = sln.productExceptSelf(vec_in);
	cout << "output vec " << endl;

	for (auto n : vec_out) {
		cout << n << "\t";
	}
#endif 

	vector<int> vec_in{ 2,7,11,15 };
	auto vec_out = sln.twoSum(vec_in, 9);

	cout << "[ " << vec_out[0] << " " << vec_out[1] << " ]" << endl;

	return;

}


int main()
{
	test();

	return 0;
}
