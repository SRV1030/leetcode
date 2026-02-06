class LFUCache {
    class Node{
    public:
        Node *prev, *next;
        int key, value, frequency;
        Node(int _key, int _value){
            prev = NULL;
            next = NULL;
            key = _key;
            value = _value;
            frequency = 1;
        }
    };
    class DoublyLinkedList{
    public:
        Node *head, *tail;
        int size;
        DoublyLinkedList(){
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addNode(Node* node){
            Node* next = head->next;
            head->next = node;
            node->prev = head;
            node->next = next;
            next->prev = node;
            ++size;
        }

        Node* deleteNode(Node* node){
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
            --size;
            return node;
        }

        Node* deleteLastNode(){
            if(size){
                return deleteNode(tail->prev);
            }
            return NULL;
        }
    };
    int capacity, minFrequency;
    unordered_map<int, Node*> nodeMap;
    unordered_map<int, DoublyLinkedList*> freToDll;

    void updateList(Node* node){
        int prevFr = node->frequency;
        DoublyLinkedList* prevList = freToDll[prevFr];
        node = prevList->deleteNode(node);
        node->frequency++;

        if(prevList->size == 0 && minFrequency == prevFr)
            ++minFrequency;
        
        if(!freToDll.count(node->frequency))
            freToDll[node->frequency] = new DoublyLinkedList();

        freToDll[node->frequency]->addNode(node);
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(nodeMap.count(key)){
            Node* node = nodeMap[key];
            updateList(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return;
        
        if(nodeMap.count(key)){
            Node* node = nodeMap[key];
            node->value = value;
            updateList(node);
            return;
        }

        if(nodeMap.size() == capacity){
            DoublyLinkedList* list = freToDll[minFrequency];
            Node* lrNode = list->deleteLastNode();
            nodeMap.erase(lrNode->key);
            delete lrNode;
        }

        Node* node = new Node(key, value);
        minFrequency = 1;
        nodeMap[key] = node;
        if(!freToDll.count(minFrequency))
            freToDll[minFrequency] = new DoublyLinkedList();
        freToDll[minFrequency]->addNode(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */