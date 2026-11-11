class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        vector<int> out;
        int n = arr.size();

        for(int i = 0; i < n; i++) {

            if(arr[i] == 0) {
                out.push_back(0);
                out.push_back(0);
            }
            else {
                out.push_back(arr[i]);
            }

            if(out.size() >= n)
                break;
        }

        for(int i = 0; i < n; i++) {
            arr[i] = out[i];
        }
    }
};