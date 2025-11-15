#include <iostream>
#include<unordered_map>
using namespace std;

    char getMaxOccurringChar(string s) {
       
        unordered_map<char, int> freq;

        
        for (char c : s) {
            freq[c]++;
        }

        int maxFreq = 0;
        char maxChar ;

        for (auto it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                maxChar = it.first;
            }
        }

        return maxChar;
    }


int main() {
    string s = "samplestring";

    char ans = getMaxOccurringChar(s);

    cout << "Max occurring character: " << ans << endl;
    return 0;
}