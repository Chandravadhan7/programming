/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return {-1,-1};
        }
        int id = 2;
        ListNode *ptr = head->next;
        ListNode *prev = head;
        vector<int> critical;

        while(ptr->next != NULL){
            if((ptr->val > prev->val && ptr->val > ptr->next->val) || (ptr->val < prev->val && ptr->val < ptr->next->val)){
               critical.push_back(id);
            }
            id++;
            prev = prev->next;
            ptr = ptr->next;
        }
        if(critical.size() < 2){
            return {-1,-1};
        }
        int mx = critical[critical.size()-1] - critical[0];
        int mn = INT_MAX;

        for(int i=1;i<critical.size();i++){
            mn = min(mn,critical[i]-critical[i-1]);
        }
        return {mn,mx};
    }
};