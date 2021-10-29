#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <string>

using namespace std;

//
// Start of Codility solution()
//

int solution(string &E, string &L) {

    // Entry time E "HH:MM"
    int E_HH = stoi(string(E, 0, 2));
    int E_MM = stoi(string(E, 3, 2));

    // Leave time L "HH:MM"
    int L_HH = stoi(string(L, 0, 2));
    int L_MM = stoi(string(L, 3, 2));

    int elapsed_minutes = (L_HH * 60 + L_MM) - (E_HH * 60 + E_MM);

    int fee {0};

    // Add entry fee
    fee += 2;

    // Add fee for first full or partial hour
    if (elapsed_minutes > 0) {
        fee += 3;
        elapsed_minutes -= 60;
    }

    // Add fee for subsequent full of partial hours
    while (elapsed_minutes > 0) {
        fee += 4;
        elapsed_minutes -= 60;
    }

    return fee;

}

//
// End of Codility solution()
//


TEST_CASE("#1") {
    string E("10:00");
    string L("13:21");
    REQUIRE(solution(E, L) == 17);
}

TEST_CASE("#2") {
    string E("09:42");
    string L("11:42");
    REQUIRE(solution(E, L) == 9);
}
