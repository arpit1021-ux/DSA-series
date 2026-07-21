class Solution {
public:
// use maxheap so we dont have to sort(based on profit to take max profit) again and again 
// maxheap will store top profit values which can be added to w
// Algorithm
// 1. vector= which will store {capital,profit}
// 2. sort based on capital because w will slowly increment so accordingly sort capital
// 3. iterate on vector and see which property we can buy add in heap(uska profit)
// 4. add top value from heap w will inc by profit------>again check can we buy more capital if yes put in heap--------->so go to point 3

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={capital[i],profits[i]};
        }
        sort(begin(vec),end(vec)); // by default sorts based on first element which is capital[i]
        int i=0; // to iterate in this vector vec
        priority_queue<int>pq;
        while(k--){
            while(i<n && vec[i].first<=w){ // means we can buy that property
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty()) break; // if already empty then break otherwise runtime error comes 
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};