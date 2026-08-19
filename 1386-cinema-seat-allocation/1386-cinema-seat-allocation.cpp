class Solution {
public:
    vector<vector<int>> layoutForTwoFamilies = {{2, 3, 4, 5}, {6, 7, 8, 9}};
    vector<int> seatsForOneFamily = {4, 5, 6, 7};
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> reservedSeatsMap;
        for(auto& seat: reservedSeats)
            reservedSeatsMap[seat[0]].push_back(seat[1]);
        
        int maxFourGroups = (n - reservedSeatsMap.size()) * 2;

        for(auto& [row, seats]: reservedSeatsMap){
            bool foundInTwoFamilyLayout = false;
            vector<bool> isOccupied(11, false);
            for(auto& seat: seats)
                isOccupied[seat] = true;
            for(auto& layout: layoutForTwoFamilies){
                bool reservedSeat = false;
                for(auto& seat: layout){
                    if(isOccupied[seat]){
                        reservedSeat = true;
                        break;
                    }
                }
                if(!reservedSeat){
                    foundInTwoFamilyLayout = true; 
                    ++maxFourGroups;
                }
            }
            if(!foundInTwoFamilyLayout){
                bool reservedSeat = false;
                for(auto& seat: seatsForOneFamily){
                    if(isOccupied[seat]){
                        reservedSeat = true;
                        break;
                    }
                }
                if(!reservedSeat)
                    ++maxFourGroups;
            }   
        }
        return maxFourGroups;
    }
};