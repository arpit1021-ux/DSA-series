class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int possibleZeroDups = 0;
        int lastIdx = arr.size() - 1;

        // Find how many zeros can actually be duplicated
        for (int i = 0; i <= lastIdx - possibleZeroDups; i++) {

            if (arr[i] == 0) {

                // Edge case: this zero cannot be fully duplicated
                if (i == lastIdx - possibleZeroDups) {

                    arr[lastIdx] = 0;
                    lastIdx--;
                    break;
                }

                possibleZeroDups++;
            }
        }

        // Last index of the part we actually need to process
        int newLastIdx = lastIdx - possibleZeroDups;

        // Work backwards and duplicate zeros
        for (int i = newLastIdx; i >= 0; i--) {

            if (arr[i] == 0) {
                arr[i + possibleZeroDups] = 0;
                possibleZeroDups--;
            }

            arr[i + possibleZeroDups] = arr[i];
        }
    }
};