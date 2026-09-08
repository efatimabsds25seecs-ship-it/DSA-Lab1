#include <string>
using namespace std;

int findPattern(const string& text, const string& pattern) {

    if (pattern.empty()) {
        return 0;
    }

    if (pattern.length() > text.length()) {
        return -1;
    }

    for (int i = 0; i <= text.length() - pattern.length(); i++) {

        int j = 0;

        while (j < pattern.length() && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == pattern.length()) {
            return i;
        }
    }

    return -1;
}