class Solution {
public:
    class Node{
        vector<Node*>bits;
        public:
        Node(){
            bits.resize(2);
        }
        void put(int bit,Node* node){
            bits[bit]=node;
        }
        Node* getKey(int bit){
            return bits[bit];
        }
        bool checkKey(int bit){
            return bits[bit]!=NULL;
        }
    };

    class Trie{
        Node* root;
        public:
        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node *node = root;
            for(int i=31;i>=0;i--){
                int bit = (num&(1<<i))!=0;
                if(!node->checkKey(bit))node->put(bit , new Node());
                node = node->getKey(bit);
            }
        }

        int getMaximumXor(int num){
            int res = 0;
            Node *node = root;
            for(int i=31;i>=0;i--){
                int bit = (num&(1<<i))!=0;
                if(node->checkKey(1-bit)){
                    res|=(1<<i);
                    node = node->getKey(1-bit);
                }
                else node = node->getKey(bit);
            }
            return res;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        int mx=0;
        Trie trie;
        for(auto&num:nums)trie.insert(num);
        for(auto&num:nums)mx=max(trie.getMaximumXor(num),mx);
        return mx;
    }
};