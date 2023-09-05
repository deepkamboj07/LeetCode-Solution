/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* main=head;
        
        while(main!=NULL)
        {
            Node* tmp=new Node(main->val);
            Node* nex=main->next;
            main->next=tmp;
            tmp->next=nex;

            main=main->next->next;
        }
        
        main=head;
        while(main!=NULL)
        {
            Node *dummy=main->next;
            Node *rand=main->random;
            
            if(rand!=NULL)dummy->random=rand->next;
            else dummy->random=NULL;
            
        //    cout<<dummy->val<<" "<<dummy->random->val<<endl;
            main=main->next->next;
        }
        
        Node *dummy=new Node(-1);
        Node *ans=dummy;
        main=head;
        while(main!=NULL)
        {
            Node *tmp=main->next;
            dummy->next=tmp;
            main->next=main->next->next;
            
            dummy=dummy->next;
            main=main->next;
        }
        
        return ans->next;
    }
};