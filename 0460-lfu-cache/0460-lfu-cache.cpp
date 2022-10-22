class Node
{
    public:
    Node *next, *prev;
    int key,value,cnt;
    Node(int k,int v)
    {
        cnt=1;
        key=k;
        value=v;
    }
    
};

class List
{
    public:
    Node *head, *tail;
    int size;
    List()
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size=0;
    }
    
    void addnode(Node *n)
    {
        Node *temp = head->next; 
        head->next= n;
        n->next = temp;
        temp->prev = n; 
        n->prev = head;
        size++;
    }
    
    void deletenode(Node *n)
    {
        Node *left,*right;
        left = n->prev;
        right= n->next;
        left->next = right;
        right->prev= left;
        size--;
    }
};

class LFUCache {
public:
    int maxSize, minFreq, size;
    
    unordered_map<int , Node*> keymp;
    unordered_map<int , List*> freqmp;
    
    LFUCache(int capacity) {
        maxSize = capacity;
        size=0;
        minFreq = 0;
    }
    
    void updateFreq(Node *n)
    {
        keymp.erase(n->key);
        freqmp[n->cnt]->deletenode(n);
        if(n->cnt == minFreq and freqmp[minFreq]->size == 0) 
        {
            minFreq++;
        }
        
        List *nextHigherList = new List();
        if(freqmp.find(n->cnt + 1) != freqmp.end())
        {
            nextHigherList = freqmp[n->cnt + 1];
        }
        n->cnt++;
        nextHigherList->addnode(n);
        freqmp[n->cnt] = nextHigherList;
        keymp[n->key] = n;
    }
    
    int get(int key) {
        if(keymp.find(key) == keymp.end())
            return -1;
        int val = keymp[key]->value;
        updateFreq(keymp[key]);
        return val;
    }
    
    void put(int key, int value) {
        if(maxSize == 0)
            return;
        if(keymp.find(key)== keymp.end())
        {
            if(size == maxSize)
            {
                List *list = freqmp[minFreq];
                Node *prevNode = list->tail->prev;
                keymp.erase(prevNode->key);
                freqmp[minFreq]->deletenode(prevNode);
                size--;
            }
            size++;          
            minFreq=1;
            
            List *listFreq = new List();
            if(freqmp.find(minFreq) != freqmp.end())
            {
                listFreq = freqmp[minFreq];
            }
            
            Node *n = new Node(key,value);
            listFreq->addnode(n);
            keymp[key] = n;
            freqmp[minFreq] = listFreq;
        }
        else
        {
            Node *n = keymp[key];
            n->value=value;
            updateFreq(n);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */