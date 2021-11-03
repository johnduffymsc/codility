#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <string>

using namespace std;

//
// Start of solution()
//

string solution(int A, int B) {

    string S;
    
    if (A == 0 && B == 0)
        return S;

    while (A + B > 0) {

        if (A - B > 2) {
            S += "aab";
            A -= 2;
            B -= 1;
        }
        else if (B - A > 2) {
            S += "bba";
            B -= 2;
            A -= 1;
        }
        else if (A > B) {
            S += "a";
            A -= 1;
        }
        else if (B > A) {
            S += "b";
            B -= 1;
        }
        else {
            if (S.back() == 'a') {
                S += "b";
                B -= 1;
            }
            else {
                S += "a";
                A -= 1;
            }
        }
         
    }

    return S;

}

//
// End of solution()
//

TEST_CASE("#1") {
    REQUIRE(solution(0, 2) == "bb");
}

TEST_CASE("#2") {
    REQUIRE(solution(2, 0) == "aa");
}

TEST_CASE("#3") {
    REQUIRE(solution(1, 4) == "bbabb");
}

TEST_CASE("#4") {
    REQUIRE(solution(4, 1) == "aabaa");
}
