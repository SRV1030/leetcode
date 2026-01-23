class Solution {
public:

    bool areWordsConnected(string word1, string word2){
        int difference = 0;
        for(int index = 0; index < word1.size(); index++)
            difference += (word1[index] != word2[index]);
        return difference == 1; 
    }

    int calculateShortestPathDistance(vector<string>& wordList, int sourceNode, int destinationNode, int sizeOfWordList){

        vector<vector<int>>graphOfIndices(sizeOfWordList);

        for(int wordIndex = 0; wordIndex < sizeOfWordList; wordIndex++){
            for(int nextWordIndex = wordIndex + 1; nextWordIndex < sizeOfWordList; nextWordIndex++){
                if(areWordsConnected(wordList[wordIndex], wordList[nextWordIndex])){
                    graphOfIndices[wordIndex].push_back(nextWordIndex);
                    graphOfIndices[nextWordIndex].push_back(wordIndex);
                }
            }
        }

        queue<int> bfsQueue;
        bfsQueue.push(sourceNode);
        int levelOfTraversal = 1;
        vector<int> visitedNodes(sizeOfWordList);

        while(!bfsQueue.empty()){
            int loopCount = bfsQueue.size();
            while(loopCount--){
                int node = bfsQueue.front();
                bfsQueue.pop();
                visitedNodes[node] = 1;
                if(node == destinationNode)
                    return levelOfTraversal;
                for(auto& neighbour: graphOfIndices[node]){
                    if(!visitedNodes[neighbour])
                        bfsQueue.push(neighbour);
                }
            }
            levelOfTraversal++;
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int sourceNode = -1, destinationNode = -1;
        int sizeOfWordList = wordList.size();
        for(int wordIndex = 0; wordIndex < sizeOfWordList; wordIndex++){
            if(wordList[wordIndex] == beginWord)
                sourceNode = wordIndex;
            if(wordList[wordIndex] == endWord)
                destinationNode = wordIndex;
        }
        if(destinationNode == -1)
                return 0;
        if(sourceNode == -1){
            wordList.insert(wordList.begin(), beginWord);
            sizeOfWordList++;
            destinationNode++;
            sourceNode = 0;
        }
        return calculateShortestPathDistance(wordList, sourceNode, destinationNode, sizeOfWordList);
    }
};