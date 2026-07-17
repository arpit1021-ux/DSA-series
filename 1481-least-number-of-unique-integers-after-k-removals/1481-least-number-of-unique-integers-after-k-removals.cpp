class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        // Step 1: Count frequency
        unordered_map<int, int> mp;

        for(int x : arr) {
            mp[x]++;
        }


        // Step 2: Min heap
        // {frequency, number}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        for(auto it : mp) {
            int number = it.first;
            int freq = it.second;

            minHeap.push({freq, number});
        }


        // Step 3: Remove numbers with smallest frequency
        while(!minHeap.empty() && k >= minHeap.top().first) {

            int freq = minHeap.top().first;

            k -= freq;

            minHeap.pop();
        }


        // Whatever remains in heap = unique numbers remaining
        return minHeap.size();
    }
};