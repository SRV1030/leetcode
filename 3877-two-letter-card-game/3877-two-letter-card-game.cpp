class Solution {
public:
    int getPoints(unordered_map<string, int>& frequencyMap,int& frequencyLeft){
        priority_queue<int> maxHeap; 
        for(auto& [card, frequency] : frequencyMap)
            maxHeap.push(frequency);
        int points = 0;
        while(maxHeap.size() >= 2){
            int freqA = maxHeap.top();
            maxHeap.pop();
            int freqB = maxHeap.top();
            maxHeap.pop();
            ++points;
            if(freqA > 1){
                maxHeap.push(freqA - 1);
            }
            if(freqB > 1){
                maxHeap.push(freqB - 1);
            }
        }
        while(maxHeap.size()){
            frequencyLeft += maxHeap.top();
            maxHeap.pop();
        }
        return points;
    }
    int score(vector<string>& cards, char x) {
        unordered_map<string, int> frequencyMapXY, frequencyMapYX;
        int xxFrequency = 0;

        for(auto& card : cards){
            if((card[0] == x && card[1] == x))
                ++xxFrequency;
            else if(card[0] == x)
                frequencyMapXY[card]++;
            else if(card[1] == x)
                frequencyMapYX[card]++;
        }
        int leftFrequency = 0, rightFrequency = 0;
        int answer = getPoints(frequencyMapXY, leftFrequency);
        answer += getPoints(frequencyMapYX, rightFrequency);
        int tempAns = answer;
        
        int canBeAdded = min(xxFrequency, leftFrequency);
        answer += canBeAdded;
        xxFrequency -= canBeAdded;

        if(xxFrequency){
            canBeAdded = min(xxFrequency, rightFrequency);
            answer += canBeAdded;
            xxFrequency -= canBeAdded;
        }

        if(xxFrequency){
            answer += min(tempAns, xxFrequency / 2);
        }

        return answer;
    }
};