class Solution {
private:
    const long long MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    Matrix multiplyMatrices(const Matrix& first,
                            const Matrix& second) {

        int rows = first.size();
        int cols = second[0].size();
        int common = first[0].size();

        Matrix result(rows, vector<long long>(cols, 0));

        for (int row = 0; row < rows; row++) {
            for (int mid = 0; mid < common; mid++) {

                long long currentValue = first[row][mid];

                if (currentValue == 0)
                    continue;

                for (int col = 0; col < cols; col++) {
                    result[row][col] =
                        (result[row][col] +
                         currentValue * second[mid][col]) % MOD;
                }
            }
        }

        return result;
    }

    Matrix matrixExponentiation(Matrix transitionMatrix,
                                long long exponent,
                                Matrix currentState) {

        while (exponent > 0) {

            if (exponent & 1)
                currentState =
                    multiplyMatrices(currentState,
                                     transitionMatrix);

            transitionMatrix =
                multiplyMatrices(transitionMatrix,
                                 transitionMatrix);

            exponent >>= 1;
        }

        return currentState;
    }

public:
    int zigZagArrays(int n, int l, int r) {

        int numberOfValues = r - l + 1;

        if (n == 1)
            return numberOfValues;

        /*
            State layout:

            0 ... m-1
                Last move was DOWN
                (next value must be larger)

            m ... 2m-1
                Last move was UP
                (next value must be smaller)
        */

        int totalStates = 2 * numberOfValues;

        Matrix transitionMatrix(
            totalStates,
            vector<long long>(totalStates, 0)
        );

        for (int currentValue = 0;
             currentValue < numberOfValues;
             currentValue++) {

            /*
                Need a larger value next.
            */
            for (int largerValue = currentValue + 1;
                 largerValue < numberOfValues;
                 largerValue++) {

                transitionMatrix
                    [currentValue + numberOfValues]
                    [largerValue]
                    = 1;
            }

            /*
                Need a smaller value next.
            */
            for (int smallerValue = 0;
                 smallerValue < currentValue;
                 smallerValue++) {

                transitionMatrix
                    [currentValue]
                    [smallerValue + numberOfValues]
                    = 1;
            }
        }

        /*
            Length 1:
            Any value can be chosen initially.
        */
        Matrix stateCount(
            1,
            vector<long long>(totalStates, 1)
        );

        stateCount =
            matrixExponentiation(
                transitionMatrix,
                n - 1,
                stateCount
            );

        long long answer = 0;

        for (int state = 0;
             state < totalStates;
             state++) {

            answer =
                (answer + stateCount[0][state]) % MOD;
        }

        return (int)answer;
    }
};