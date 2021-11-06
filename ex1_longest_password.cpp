#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <string>

using namespace std;

//
// Start of solution()
//

int valid(int alpha, int digit) {

    if (alpha % 2 != 0)
        return -1;

    if (digit % 2 != 1)
        return -1;

    return alpha + digit;

}

int solution(string &S) {

    int alpha {0};
    int digit {0};

    int longest {0};

    auto it = S.begin();

    while (it != S.end()) {

        if (isspace(*it)) {
            // End of word.
            if (alpha + digit > 0) {
                longest = valid(alpha, digit) > longest ? valid(alpha, digit): longest;
                alpha = 0;
                digit = 0;
            }
            ++it;
        }
        else if (isalpha(*it)) {
            ++alpha;
            ++it;
        }
        else if (isdigit(*it)) {
            ++digit;
            ++it;
        }
        else {
            // Invalid character, reset counters and go to next space or end of string.
            alpha = 0;
            digit = 0;
            do {
                ++it;
            } while (!isspace(*it) && it != S.end());
        }

    }

    // Word ending at end of string.
    if (alpha + digit > 0)
        longest = valid(alpha, digit) > longest ? valid(alpha, digit): longest;

    // Done!
    return longest > 0 ? longest : -1;

}

//
// End of solution()
//

TEST_CASE("#1") {
    string S("test 5 a0A pass007 ?xy1");
    REQUIRE(solution(S) == 7);
}
