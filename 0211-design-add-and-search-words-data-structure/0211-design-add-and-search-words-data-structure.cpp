struct Node{
    Node* link[26];
    bool flag=false;
    
    bool isThere(char ch)
    {
        return (link[ch-'a']!=NULL);
    }
    
    void put(char ch, Node* node)
    {
        link[ch-'a']=node;
    }
    
    Node* get(char ch)
    {
        return link[ch-'a'];
    }
    Node* get(int key)
    {
        return link[key];
    }
    
    void makeEnd()
    {
        flag=true;
    }
    
    bool isEnd()
    {
        return flag;
    }
    
};
class WordDictionary {
private:
    Node* root;
public:

    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->isThere(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->makeEnd();
    }
    
    bool search(string &word, Node* node, int idx)
    {
        if(!node)return false;
        if(idx==word.length()) return node->isEnd();
        
        if(word[idx]!='.')
        {
            return search(word,node->get(word[idx]),idx+1);
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                if(search(word,node->get(i),idx+1))
                    return true;
            }
        }
        
        return false;
    }
  
    bool search(string word) {
        
        return search(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */