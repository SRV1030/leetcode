class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size(), shift1 = 0;
        vector<int> product(size1 + size2 + 1);
        for (int i = size1 - 1; i >= 0; i--) {
            int val1 = num1[i] - '0', shift2 = 0, c = 0;
            for (int j = size2 - 1; j >= 0; j--) {
                int val2 = num2[j] - '0';
                int tempProduct = val1 * val2 + product[shift1 + shift2] + c;
                product[shift1 + shift2] = tempProduct % 10;
                c = tempProduct / 10;
                shift2++;
            }
            if (c)
                product[shift1 + shift2] += c;
            ++shift1;
        }
        string ans = "";
        int i = size1 + size2;
        while (i >= 0 && product[i] == 0)
            i--;
        if (i == -1)
            return "0";
        while (i >= 0)
            ans += to_string(product[i--]);
        return ans;
    }
};