class Solution {
public:
    int minimumTeachings(int numberOfLanguage, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int numberOfPeople = languages.size();
        vector<bitset<501>> knowLang(numberOfPeople);

        for(int index = 0; index < numberOfPeople; ++index){
            for(auto& language : languages[index])
                knowLang[index][language] = 1;
        }

        bitset<501> needToKnow;
        for(auto& friendship : friendships){
            int friendA = friendship[0] - 1, friendB = friendship[1] - 1;
            if((knowLang[friendA] & knowLang[friendB]).any())
                continue;
            needToKnow[friendA] = needToKnow[friendB] = 1;
        }
        if (needToKnow.count() == 0) 
            return 0;
        int minPeopleToTeach = INT_MAX;
        for(int lang = 1; lang <= numberOfLanguage; ++lang){
            int count = 0;
            for(int people = 0; people < numberOfPeople; ++people){
                if(needToKnow[people] & !knowLang[people][lang])
                    ++count;
            }
            minPeopleToTeach = min(minPeopleToTeach, count);
        }
        return minPeopleToTeach;
    }
};