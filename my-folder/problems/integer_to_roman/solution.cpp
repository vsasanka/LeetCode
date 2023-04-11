class Solution {
public:
    string ones(int num, unordered_map<int, string> &intRomanMap){
        intRomanMap[2] = "II";
        intRomanMap[3] = "III";
        intRomanMap[4] = "IV";
        // intRomanMap[5] = "V";
        intRomanMap[6] = "VI";
        intRomanMap[7] = "VII";
        intRomanMap[8] = "VIII";
        intRomanMap[9] = "IX";

        return intRomanMap[num%10];
    }

    string tens(int num, unordered_map<int, string> &intRomanMap){
        intRomanMap[20] = "XX";
        intRomanMap[30] = "XXX";
        intRomanMap[40] = "XL";
        // intRomanMap[5] = "V";
        intRomanMap[60] = "LX";
        intRomanMap[70] = "LXX";
        intRomanMap[80] = "LXXX";
        intRomanMap[90] = "XC";

        return intRomanMap[num%100 - num%10];
    }

    string hundreds(int num, unordered_map<int, string> &intRomanMap){
        intRomanMap[200] = "CC";
        intRomanMap[300] = "CCC";
        intRomanMap[400] = "CD";
        // intRomanMap[5] = "V";
        intRomanMap[600] = "DC";
        intRomanMap[700] = "DCC";
        intRomanMap[800] = "DCCC";
        intRomanMap[900] = "CM";

        return intRomanMap[num%1000 - num%100];
    }

    string thousands(int num, unordered_map<int, string> &intRomanMap){
        intRomanMap[2000] = "MM";
        intRomanMap[3000] = "MMM";

        return intRomanMap[num%10000 - num%1000];
    }

    string intToRoman(int num) {
        string ans = "";
        unordered_map<int, string> intRomanMap;

        intRomanMap[1] = "I";
        intRomanMap[5] = "V";
        intRomanMap[10] = "X";
        intRomanMap[50] = "L";
        intRomanMap[100] = "C";
        intRomanMap[500] = "D";
        intRomanMap[1000] = "M";

        ans.append(thousands(num, intRomanMap));
        ans.append(hundreds(num, intRomanMap));
        ans.append(tens(num, intRomanMap));
        ans.append(ones(num, intRomanMap));

        return ans;
    }
};