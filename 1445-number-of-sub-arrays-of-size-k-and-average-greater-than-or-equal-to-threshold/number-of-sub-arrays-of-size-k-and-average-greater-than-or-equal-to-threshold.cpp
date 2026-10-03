class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int n = arr.size();
        int sum = 0;

        for(int i = 0;i<k;i++){
            sum += arr[i];
        }
        int count  = 0;
        if(sum/k >=t) count++;
        for(int i  = k;i<n;i++){
            sum += arr[i];
            sum -= arr[i-k];
             if(sum/k >=t) count++;
        }
        return count;
    }
};