#include<iostream>
#include<stack>
#include<cassert>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode * it = head;
        int count = 0;
        int stride = 1;
        ListNode * h = new ListNode(0);
        h->next = head;
        while(it != NULL){
            it = it->next;
            count++;
        }
        while(stride < count){
            it = h;
            while(it != NULL){
                it = merge(it, stride);
            }
            stride *= 2;
        }
        return h->next;


    }
    //return the jitem before start of next stride
    ListNode* merge(ListNode * it_before, int stride){
        assert(it_before != NULL);
        ListNode *first = it_before->next;
        ListNode *second = it_before->next;
        if(first == NULL)
            return NULL;
        int i = 0;
        for(i = 0; i < stride; i++){
            second = second->next;
            if(second == NULL){
                return NULL;
            }
        }
        ListNode *middle = second;
        ListNode *end = second;
        ListNode *re = second;
        for(i = 0; i < stride; i++){
            end = end->next;
            if(end == NULL){
                break;
            }
        }
        
        ListNode *it = it_before;
        while(first != middle && second != end){
            if(first->val > second->val){
                it->next = second;
                it = it->next;
                second = second->next;
                //it->next = NULL;
            }
            else{
                it->next = first;
                it = it->next;
                first = first->next;
                //it->next = NULL;
            }
        }
        if(first == middle){
            it->next = second;
            while(it->next != end){
                it = it->next;
            }
            re = it;
            it->next = end;
        }
        else if(second == end){
            it->next = first;
            while(it->next != middle){
                it = it->next;
            }
            re = it;
            it->next = end;
        }
        return re;
    }
};

int main(int argc, char const* argv[])
{
    ListNode *head;
    ListNode *it;
    int n;
    /*bool isHead = true;
    while(cin>>n)
    {
        if(cin.eof())
            return 0;
        cout<<n<<endl;
        if(isHead){
            head = new ListNode(n);
            it = head;
            isHead = false;
        }
        it->next = new ListNode(n);
        it = it->next;

    }*/
    head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(7);
    //head->next->next->next->next->next->next = new ListNode(1);
    //head->next->next->next->next = NULL;

    Solution solution;
    head = solution.sortList(head);

    it = head;
    while(it != NULL){
        cout<<it->val<<" ";
        it = it->next;
    }
    cout<<endl;
    return 0;
}
