#include <doctest.hpp>
#include <iostream>
#include <unicode/display_width.hpp>

using doctest::test_suite;

inline void print_columns(const std::string& input, const int result) {
    std::cout << "Input : " << input << "\n";
    std::cout << "Output: ";
    for(auto i = 0; i < result; ++i) {
        std::cout << "|";
    }
    std::cout << "\n\n"; 
}

TEST_CASE("unicode::display_width correctly returns the display width (columns) of unicode strings" * test_suite("utf8::display_width")) {
    {
        const std::string input = "Hello, World!";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 13);
        print_columns(input, result);
    }

    {
        const std::string input = u8"Ｈｅｌｌｏ, ｗｏｒｌｄ!";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 23);
        print_columns(input, result);
    }

    {
        // French
        const std::string input = u8"Je t’aime";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 9);
        print_columns(input, result);
    }

    {
        // Greek
        const std::string input = u8"Σ΄αγαπώ (Se agapo)";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 18);
        print_columns(input, result);
    }

    {
        // Mandarin Chinese
        const std::string input = u8"我爱你";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 6);
        print_columns(input, result);
    }

    {
        // Japanese
        const std::string input = u8"愛してる";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 8);
        print_columns(input, result);
    }

    {
        // Korean
        const std::string input = u8"사랑해 (Saranghae)";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 18);
        print_columns(input, result);
    }

    {
        // Russian
        const std::string input = u8"Я тебя люблю (Ya tebya liubliu)";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 31);
        print_columns(input, result);
    }

    {
        // Hebrew
        const std::string input = u8"אני אוהב אותך (Ani ohev otakh)";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 30);
        print_columns(input, result);
    }
}