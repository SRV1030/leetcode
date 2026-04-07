class Robot {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<string> dirStrings = {"East", "North", "West", "South"};
    int dirIndex = 0, x = 0, y = 0;
    int height, width;

public:
    Robot(int width, int height) {
        this->height = height;
        this->width = width;
    }

    void step(int num) {
        while (num > 0) {
            int nx = x + directions[dirIndex][0];
            int ny = y + directions[dirIndex][1];

            // If next move is invalid → turn
            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                dirIndex = (dirIndex + 1) % 4;
                continue;
            }

            // Move
            x = nx;
            y = ny;
            num--;
        }

        // Special case: back at origin after movement
        if (x == 0 && y == 0 && num == 0) {
            dirIndex = 3; // South
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() { return dirStrings[dirIndex]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */