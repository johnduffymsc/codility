#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

#include <cmath>

//
// Start of solution()
//

int solution(int N) {

    // The highest power k of 2 which divides N will occur if
    // 2^k = N. Therefore, the upper bound on k is log2(N).
    for (int k = log2(N); k > -1; --k)
        if (N % (int)pow(2, k) == 0)
            return k;

    // 2^k does not divide N
    return -1;

}

//
// End of solution()
//

TEST_CASE("#1") {
    int N {24};
    REQUIRE(solution(N) == 3);
}
