class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node *next, *prev;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };

    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);
    int capacity;
    unordered_map<int, Node*> nodeMap;

    void addNode(Node* node) {
        Node* headNext = head->next;
        head->next = node;
        node->next = headNext;
        node->prev = head;
        headNext->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        delete(node);
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (nodeMap.count(key)) {
            Node* node = nodeMap[key];
            int value = node->value;
            nodeMap.erase(key);
            deleteNode(node);
            addNode(new Node(key, value));
            nodeMap[key] = head->next;
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (nodeMap.count(key)) {
            Node* node = nodeMap[key];
            nodeMap.erase(key);
            deleteNode(node);
        } else if (nodeMap.size() == capacity) {
            nodeMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        nodeMap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */