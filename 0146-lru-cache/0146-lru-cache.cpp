class LRUCache {
    class Node{
    public:
        int key, value;
        Node *previous, *next;
        Node(int _key, int _value){
            key = _key;
            value = _value;
        }
    };

    class DoublyLinkedList{
    public:
        Node *head, *tail;
        DoublyLinkedList(){
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->previous = head;
        }

        void addNode(Node* node){
            Node* next = head->next;
            node->next = next;
            next->previous = node;
            head->next = node;
            node->previous = head;
        }

        void removeNode(Node* node){
            Node *next = node->next;
            Node *previous = node->previous;
            previous->next = next;
            next->previous = previous;
        }

        Node* removeLastNode(){
            Node* node = tail->previous;
            removeNode(node);
            return node;
        }

        void updateList(Node* node){
            removeNode(node);
            addNode(node);
        }
    };

    int capacity;
    DoublyLinkedList *list;
    unordered_map<int, Node*> nodeMap;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        list = new DoublyLinkedList();
    }
    
    int get(int key) {
        if(nodeMap.count(key)){
            Node* node = nodeMap[key];
            list->updateList(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(nodeMap.count(key)){
            Node* node = nodeMap[key];
            node->value = value;
            list->updateList(node);
            return;
        }
        if(nodeMap.size() == capacity){
            Node* leastRecentlyUsedNode = list->removeLastNode();
            nodeMap.erase(leastRecentlyUsedNode->key);
            delete leastRecentlyUsedNode;
        }
        Node* node = new Node(key, value);
        list->addNode(node);
        nodeMap[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */