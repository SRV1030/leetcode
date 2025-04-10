class Solution {
public:
    vector<string> postThousands = {"", "", "Thousand", "Million", "Billion"};
    vector<string> ones = {"",     "One", "Two",   "Three", "Four",
                           "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> specials = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                               "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                               "Eighteen", "Nineteen"};
    vector<string> tens = {"","Ten",   "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    const string HUNDRED = "Hundred";

    string postThousandString(int num){
        if(!num) return "";
        if(num>=1 && num<=9) return ones[num];
        if(num>=10 && num<=19) return specials[num%10];
        if (num<=99) return tens[num/10]+(num%10?" "+ones[num%10]:"");
        return ones[num/100]+" "+HUNDRED+(num%100?" "+postThousandString(num%100):"");
    }
    string preThousandString(int num, int comma) {
        if (num == 0)
            return "";
        string prefix = preThousandString(num / 1000, comma + 1);
        int remainder = num % 1000;
        if(remainder){
            prefix = prefix + (prefix.empty()?"":" ") + postThousandString(remainder) + ((comma<=1)?"":" "+postThousands[comma]);
        } 
        return prefix; 
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        return preThousandString(num, 1);
    }
};