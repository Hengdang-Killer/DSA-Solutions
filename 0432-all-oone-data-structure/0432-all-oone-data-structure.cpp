struct Node
{
    string key;
    int cnt;
    Node *next;
    Node *prev;
    Node(string _key)
    {
        key = _key;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node("?");
        tail = new Node("?");
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // O(1)
    void add(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    // O(1)
    void removeNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }

};

class AllOne 
{
private:
    int minFreq, maxFreq;
    unordered_map<string, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    map<int, int> freq;

    // O(1)
    void incrementFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
            minFreq++;
        List *nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end())
            nextHigherFreqList = freqListMap[node->cnt+1];
        node->cnt += 1;
        maxFreq = max(maxFreq, node->cnt);
        nextHigherFreqList->add(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    // O(1)
    void decrementFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == maxFreq && freqListMap[node->cnt]->size == 0)
            maxFreq--;
        if(node->cnt == minFreq && minFreq >= 2)
            minFreq--;
        else
        {
            minFreq = 0;
            for(auto itr : freq)
            {
                minFreq = itr.first;
                break;        
            }
        }
        if(node->cnt-1 == 0)
        {
            return;
        }
        List *nextLowerFreqList = new List();
        if(freqListMap.find(node->cnt-1) != freqListMap.end())
            nextLowerFreqList = freqListMap[node->cnt-1];
        node->cnt -= 1;
        nextLowerFreqList->add(node);
        freqListMap[node->cnt] = nextLowerFreqList;
        keyNode[node->key] = node;
    }

public:
    AllOne() 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        minFreq = maxFreq = 0;
    }
    
    // O(log N)
    void inc(string key) 
    {
        if(keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            freq[node->cnt]--;
            if(freq[node->cnt] == 0)
                freq.erase(node->cnt);
            freq[node->cnt+1]++;
            incrementFreqListMap(node);
        }    
        else
        {
            minFreq = 1;
            freq[1]++;
            maxFreq = std::max(maxFreq, 1);
            List *listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key);
            listFreq->add(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
    
    // O(log N)
    void dec(string key) 
    {
        Node *node = keyNode[key];
        freq[node->cnt]--;
        if(freq[node->cnt] == 0)
            freq.erase(node->cnt);
        if(node->cnt-1 > 0)
            freq[node->cnt-1]++;
        decrementFreqListMap(node);
    }
    
    // O(log 1)
    string getMaxKey() 
    {
        if(maxFreq == 0)
            return "";
        return freqListMap[maxFreq]->head->next->key;
    }
    
    // O(log 1)
    string getMinKey() 
    {
        if(minFreq == 0)
            return "";
        return freqListMap[minFreq]->tail->prev->key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */