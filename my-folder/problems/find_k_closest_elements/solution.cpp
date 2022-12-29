class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        auto ipointer = upper_bound(arr.begin(), arr.end(), x);
        int i = static_cast<int>(ipointer - arr.begin());
        
        int j = i - 1;
        
        // cout << *ipointer << " " << i << " " << j << endl;
        
        while (i < n && j >= 0 && k>0){
            if (arr[i] - x < x - arr[j]){
                ans.push_back(arr[i]);
                i++;
            }
            else{
                ans.push_back(arr[j]);
                j--;
            }
            k--;
        }
        
        // cout << i << " " << n << endl;
        
        while (i < n && k>0){
            ans.push_back(arr[i]);
            i++; k--;
        }
        
        while (j >= 0 && k>0){
            ans.push_back(arr[j]);
            j--; k--;
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};