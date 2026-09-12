class Solution {
private:
    int fact(int n) {
        int fact = 1;

        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        return fact;
    }

public:
    int totalNumbers(vector<int>& digits) {

        int freq[10] = {0};

        if (digits.size() < 3) {
            return 0;
        }

        for (int digit : digits) {
            freq[digit]++;
        }

        int count = 0;

        for (int i = 0; i < 10; i++) {
            if (freq[i] > 0) {
                count++;
            }
        }
        if(count==1 && freq[0]>0){
            return 0;
        }
        if (count == 1) {
            return (freq[0] > 0 || freq[2] > 0 ||
                    freq[4] > 0 || freq[6] > 0 ||
                    freq[8] > 0) ? 1 : 0;
        }

        int out = 0;

        for (int e = 0; e <= 8; e += 2) {

            if (freq[e] == 0)
                continue;

            freq[e]--;

            for (int h = 1; h <= 9; h++) {

                if (freq[h] == 0)
                    continue;

                freq[h]--;

                for (int t = 0; t <= 9; t++) {
                    if (freq[t] > 0) {
                        out++;
                    }
                }

                freq[h]++;
            }

            freq[e]++;
        }

        return out;
    }
};