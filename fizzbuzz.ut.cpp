#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fizzbuzz.hpp"

TEST_CASE("Test with zero", "[classic]") {
    REQUIRE(fizzbuzz(0) == "0");
}

TEST_CASE("Test positives", "[classic]") {
    SECTION("Test all up to 10") {
        REQUIRE(fizzbuzz(0) == "0");
        REQUIRE(fizzbuzz(1) == "1");
        REQUIRE(fizzbuzz(2) == "2");
        REQUIRE(fizzbuzz(3) == "fizz");
        REQUIRE(fizzbuzz(4) == "4");
        REQUIRE(fizzbuzz(5) == "buzz");
        REQUIRE(fizzbuzz(6) == "fizz");
        REQUIRE(fizzbuzz(7) == "7");
        REQUIRE(fizzbuzz(8) == "8");
        REQUIRE(fizzbuzz(9) == "fizz");
        REQUIRE(fizzbuzz(10) == "buzz");
    }

    SECTION("Test all multiples of 3 only up to 100") {
        for (int i = 3; i <= 100; i += 3) {
            if (i % 5) {
                REQUIRE(fizzbuzz(i) == "fizz");
            }
        }
    }

    SECTION("Test all multiples of 5 only up to 100") {
        for (int i = 5; i <= 100; i += 5) {
            if (i % 3) {
                REQUIRE(fizzbuzz(i) == "buzz");
            }
        }
    }

    SECTION("Test all multiples of 3 and 5 only up to 100") {
        for (int i = 15; i <= 100; i += 15) {
            REQUIRE(fizzbuzz(i) == "fizzbuzz");
        }
    }
}

TEST_CASE("Test negatives", "[classic]") {
    REQUIRE(fizzbuzz(-1) == "-1");
    REQUIRE(fizzbuzz(-2) == "-2");
    REQUIRE(fizzbuzz(-3) == "fizz");
    REQUIRE(fizzbuzz(-4) == "-4");
    REQUIRE(fizzbuzz(-5) == "buzz");
    REQUIRE(fizzbuzz(-6) == "fizz");
    REQUIRE(fizzbuzz(-7) == "-7");
    REQUIRE(fizzbuzz(-8) == "-8");
    REQUIRE(fizzbuzz(-9) == "fizz");
    REQUIRE(fizzbuzz(-10) == "buzz");
}

// BDD aproach
SCENARIO("BDD test with zero", "[bdd]") {
    WHEN("The number is 0") {
        THEN("The result is 0") {
            REQUIRE(fizzbuzz(0) == "0");
        }
    }
}

SCENARIO("BDD test with numbers", "[bdd]") {
    GIVEN("Non divisable by 3 and 5 positive numbers") {
        using Pair = std::pair<int, std::string>;
        auto [input, expected] = GENERATE(Pair{{0}, {"0"}},
                                          Pair{{1}, {"1"}},
                                          Pair{{2}, {"2"}},
                                          Pair{{4}, {"4"}},
                                          Pair{{7}, {"7"}},
                                          Pair{{8}, {"8"}});

        WHEN("The number" << input << " is given") {
            THEN("The result is number as string") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }

    GIVEN("Positive numbers divisible by 3") {
        const std::string expected = "fizz";
        auto input = GENERATE(3, 6, 9, 12, 18);
        WHEN("The number" << input << " is given") {
            THEN("The result is fizz") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }

    GIVEN("Positive numbers divisible by 5") {
        const std::string expected = "buzz";
        auto input = GENERATE(5, 10, 20, 25, 35);
        WHEN("The number" << input << " is given") {
            THEN("The result is buzz") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }

    GIVEN("Positive numbers divisible by 3 and 5") {
        const std::string expected = "fizzbuzz";
        auto input = GENERATE(15, 30, 45, 60, 75);
        WHEN("The number" << input << " is given") {
            THEN("The result is fizzbuzz") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }

    GIVEN("Non divisible by 3 and 5 negative numbers") {
        using Pair = std::pair<int, std::string>;
        auto [input, expected] = GENERATE(Pair{{-1}, {"-1"}},
                                          Pair{{-2}, {"-2"}},
                                          Pair{{-4}, {"-4"}},
                                          Pair{{-7}, {"-7"}},
                                          Pair{{-8}, {"-8"}});
        WHEN("The number" << input << " is given") {
            THEN("The result is number as string") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }

    GIVEN("Negative numbers divisible by 3") {
        const std::string expected = "fizz";
        auto input = GENERATE(-3, -6, -9, -12, -18);
        WHEN("The number" << input << " is given") {
            THEN("The result is fizz") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }

    GIVEN("Negative numbers divisible by 5") {
        const std::string expected = "buzz";
        auto input = GENERATE(-5, -10, -20, -25, -35);
        WHEN("The number" << input << " is given") {
            THEN("The result is buzz") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }

    GIVEN("Negative numbers divisible by 3 and 5") {
        const std::string expected = "fizzbuzz";
        auto input = GENERATE(-15, -30, -45, -60, -75);
        WHEN("The number" << input << " is given") {
            THEN("The result is fizzbuzz") {
                REQUIRE(fizzbuzz(input) == expected);
            }
        }
    }
}
