#include <iostream>
using namespace std;

    string removeNonAlphabets(string s) {
        string result = "";
        for (char c : s) {
            
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                result += c;
            }
        }
        return result;
    }

int main() {
    string s = "He!!llo World123";
   
    cout << "Original String: " << s << endl;
    cout << "Filtered String: " << removeNonAlphabets(s) << endl;
    return 0;
}