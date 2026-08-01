class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        // No elements left
        if (i > j)
            return 0;

        // Only one element left
        if (i == j)
            return nums[i];

        // If player chooses the left element
        int take_i = nums[i] + min(
            solve(i + 2, j, nums),      // Opponent picked i+1
            solve(i + 1, j - 1, nums)   // Opponent picked j
        );

        // If player chooses the right element
        int take_j = nums[j] + min(
            solve(i, j - 2, nums),      // Opponent picked j-1
            solve(i + 1, j - 1, nums)   // Opponent picked i
        );

        // Choose the better option
        return max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int total_score = accumulate(nums.begin(), nums.end(), 0);

        int player1_score = solve(0, n - 1, nums);

        int player2_score = total_score - player1_score;

        return player1_score >= player2_score;
    }
};