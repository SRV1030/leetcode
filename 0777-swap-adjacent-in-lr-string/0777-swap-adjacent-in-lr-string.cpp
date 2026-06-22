class Solution {
public:
    bool canTransform(string start, string result) {
        int indStart = 0, indResult = 0, size = result.size();
        while (indStart < size || indResult < size) {
            while (indStart < size && start[indStart] == 'X')
                indStart++;
            while (indResult < size && result[indResult] == 'X')
                indResult++;
            if (indStart >= size || indResult >= size)
                break;
            if (start[indStart] != result[indResult])
                return false;
            if (start[indStart] == 'L' && indStart < indResult)
                return false;
            if (start[indStart] == 'R' && indStart > indResult)
                return false;
            indStart++;
            indResult++;
        }
        return indStart==indResult;
    }
};