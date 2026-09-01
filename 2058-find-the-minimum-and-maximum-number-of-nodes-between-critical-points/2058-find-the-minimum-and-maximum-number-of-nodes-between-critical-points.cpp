class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // We need at least 3 nodes
        // because a critical point needs previous and next node
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};


        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        // Position of first critical point
        int first = -1;

        // Position of previous critical point
        int last = -1;

        int minDist = INT_MAX;


        while (curr->next != nullptr) {

            // Check whether curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);


            if (isCritical) {

                // First critical point
                if (first == -1) {
                    first = index;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - last);
                }

                // Current critical point becomes previous
                last = index;
            }


            prev = curr;
            curr = curr->next;
            index++;
        }


        // Fewer than 2 critical points
        if (first == last)
            return {-1, -1};


        // Distance between first and last critical points
        int maxDist = last - first;

        return {minDist, maxDist};
    }
};