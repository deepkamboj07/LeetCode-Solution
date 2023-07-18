class LRUCache {
public:
    struct Node{
        public:
        int data;
        int k;
        Node* next;
        Node* prev;

        Node(int key,int v)
        {
            k=key;
            data=v;
            next=prev=NULL;
        }
    };
    
    unordered_map<int,Node*> mp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int size=0;
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(int x, int d)
    {
        Node* newNode=new Node(x,d);
        Node* tmp=head->next;
        newNode->next=tmp;
        newNode->prev=head;
        head->next=newNode;
        tmp->prev=newNode;
       
        mp.insert({x,newNode});
    }
    
    void deleteNode(Node* nd)
    {
        Node* ndnext=nd->next;
        Node* ndprev=nd->prev;
        
        ndprev->next=ndnext;
        ndnext->prev=ndprev;
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end())
        {
            Node *node=mp[key];
            int res=node->data;
            mp.erase(key);
            deleteNode(node);
            addNode(key,res);
            return res;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            deleteNode(node);
            mp.erase(key);
        }
        if(mp.size()==size)
        {
            mp.erase(tail->prev->k);
            deleteNode(tail->prev);
        }
        addNode(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */