


/*23. Merge k Sorted Lists */

#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

    void add_node(ListNode**head,int data)
    {
        if(*head==nullptr)
        {
            *head=new ListNode(data);
        }
        else
        {
            ListNode*temp=*head;
        }

    }
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {

       ListNode *list=nullptr;
       ListNode**pointer=new ListNode*[lists.size()];

       for(int i=0;i<lists.size();i++)
       {
        pointer[i]=lists[i];
       }





        return list;
        
    }
};