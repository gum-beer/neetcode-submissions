class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int x, int y): key(x),value(y), next(nullptr), prev(nullptr) {}

};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node)
    {
        Node* prv=node->prev;
        Node* nxt=node->next;
        prv->next= nxt;
        nxt->prev=prv;
    }
    void insert(Node*node)
    {
        node->next=right;
        node->prev=right->prev;
        right->prev=node;
        (node->prev)->next=node;

    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        left =new Node(0,0);
        right= new Node(0,0);
        left->next=right;
        right->prev=left;
        
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;        
    }
    
    void put(int key, int value) {

        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        
    }
};
