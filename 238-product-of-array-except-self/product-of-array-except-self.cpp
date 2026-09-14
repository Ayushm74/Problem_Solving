class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> answer(n);

        int product = 1;
        int zero = 0;

        // Find total product and count zero
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero++;
            }
            else {
                product *= nums[i];
            }
        }

        // More than one zero
        if (zero > 1) {
            for (int i = 0; i < n; i++) {
                answer[i] = 0;
            }
            return answer;
        }

        // Exactly one zero
        if (zero == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    answer[i] = product;
                }
                else {
                    answer[i] = 0;
                }
            }
            return answer;
        }

        for (int i = 0; i < n; i++) {
            answer[i] = product / nums[i];
        }

        return answer;
    }
};