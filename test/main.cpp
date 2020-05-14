#include <doctest.hpp>
#include <iostream>
#include <unicode/display_width.hpp>

using doctest::test_suite;

inline void print_columns(const std::string& input, const int result) {
    std::cout << "Input  : " << input << "\n";
    std::cout << "Output : " << std::string(result, '|') << "\n";
    std::cout << "Width  : " << result << "\n\n";
}

TEST_CASE("unicode::display_width correctly returns the display width of unicode strings" * test_suite("unicode::display_width")) {
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
        // Halfwidth and Fullwidth Forms
        const std::string input = u8"Ａ Ｂ Ｃ Ｄ Ｅ Ｆ Ｇ Ｈ Ｉ Ｊ Ｋ Ｌ Ｍ Ｎ Ｏ Ｐ Ｑ Ｒ Ｓ Ｔ Ｕ Ｖ Ｗ Ｘ Ｙ Ｚ";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 77);
        print_columns(input, result);
    }

    {
        // Mathematical Operators
        const std::string input = u8"∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏ ∐ ∑ − ∓ ∔ ∕ ∖ ∗ ∘ ∙ √ ∛ ∜";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 57);
        print_columns(input, result);
    }

    {
        // Amharic
        const std::string input = u8"እው ሰላም ነው. እንዴት ነህ?";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 19);
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
        // Chinese simplified
        const std::string input = u8"你好。 你好吗？";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 15);
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

    {
        // Armenian
        const std::string input = u8"Ինչպես ես?";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 10);
        print_columns(input, result);
    }

    {
        // Tamil
        const std::string input = u8"நீங்கள் எப்படி இருக்கிறீர்கள்?";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 22);
        print_columns(input, result);
    }

    {
        // Punjabi
        const std::string input = u8"ਤੁਸੀਂ ਕਿਵੇਂ ਹੋ?";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 10);
        print_columns(input, result);
    }

    {
        // Woman scientist emoji
        const std::string input = u8"👩‍🔬";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 2);
        print_columns(input, result);
    }

    {
        // "This is cool"
        const std::string input = u8"𝓽𝓱𝓲𝓼 𝓲𝓼 𝓬𝓸𝓸𝓵";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 12);
        print_columns(input, result);
    }

    {
        // Glasses of disapproval
        const std::string input = u8"(-■_■)";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 6);
        print_columns(input, result);
    }

    {
        // Right back at ya!
        const std::string input = u8"(☞ﾟ∀ﾟ)☞";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 7);
        print_columns(input, result);
    }

    {
        // Equalizer
        const std::string input = u8"█ ▄ █ ▄ ▄ █ ▄ █ ▄ █";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 19);
        print_columns(input, result);
    }

    {
        // Animal Face
        const std::string input = u8"／人 ◕ ‿‿ ◕ 人＼";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 16);
        print_columns(input, result);
    }

    {
        // Symbols
        const std::string input = u8"▣ ■ □ ▢ ◯ ▲ ▶ ► ▼ ◆ ◢ ◣ ◤ ◥";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 27);
        print_columns(input, result);
    }

    {
        // 1234
        const std::string input = "\u2081\u2082\u2083\u2084";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 4);
        print_columns(input, result);
    }

    {
        // wstring
        const std::wstring input = L"Μένω στους Παξούς";
        const auto result = unicode::display_width(input);
        REQUIRE(result == 17);
    }
}