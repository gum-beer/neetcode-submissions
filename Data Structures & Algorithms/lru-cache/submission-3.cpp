class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k),value(v),prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left=nullptr;
    Node* right=nullptr;

    void remove (Node* oldNode)
    {
        Node * prv=oldNode->prev;
        Node * nxt= oldNode->next;
        prv->next=nxt;
        nxt->prev=prv;
    }

    void insert(Node* newNode)
    {
        newNode->next=right;
        newNode->prev=right->prev;
        right->prev=newNode;
        (newNode->prev)->next=newNode;

    }

public:
    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
        if(cache.find(key)!= cache.end())
        {
            Node* temp=cache[key];
            remove(temp);
            insert(temp);
            return temp->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) 
    {
        if(cache.find(key)!= cache.end())
        {
            remove(cache[key]);
        }
        Node * newCache=new Node(key,value);
        cache[key]=newCache;
        insert(newCache);
        if(cache.size()>cap)
        {
            Node* lru= left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        
    }
};
