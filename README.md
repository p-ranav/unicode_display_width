# utf8_width
Displayed width of unicode strings

## Quick Start

```cpp
#include <unicode/display_width.hpp>

int main() {
    const std::string input = u8"Я тебя люблю (Ya tebya liubliu)";
    const auto result = unicode::display_width(input);
    // result is 31
}
```

## Samples:

```bash
Input : Hello, World!
Output: |||||||||||||
Result: 13

Input : Ｈｅｌｌｏ, ｗｏｒｌｄ!
Output: |||||||||||||||||||||||
Result: 23

Input : Ａ Ｂ Ｃ Ｄ Ｅ Ｆ Ｇ Ｈ Ｉ Ｊ Ｋ Ｌ Ｍ Ｎ Ｏ Ｐ Ｑ Ｒ Ｓ Ｔ Ｕ Ｖ Ｗ Ｘ Ｙ Ｚ
Output: |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Result: 77

Input : ∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏ ∐ ∑ − ∓ ∔ ∕ ∖ ∗ ∘ ∙ √ ∛ ∜
Output: |||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Result: 57

Input : እው ሰላም ነው. እንዴት ነህ?
Output: |||||||||||||||||||
Result: 19

Input : Je t’aime
Output: |||||||||
Result: 9

Input : Σ΄αγαπώ (Se agapo)
Output: ||||||||||||||||||
Result: 18

Input : 我爱你
Output: ||||||
Result: 6

Input : 你好。 你好吗？
Output: |||||||||||||||
Result: 15

Input : 愛してる
Output: ||||||||
Result: 8

Input : 사랑해 (Saranghae)
Output: ||||||||||||||||||
Result: 18

Input : Я тебя люблю (Ya tebya liubliu)
Output: |||||||||||||||||||||||||||||||
Result: 31

Input : אני אוהב אותך (Ani ohev otakh)
Output: ||||||||||||||||||||||||||||||
Result: 30

Input : Ինչպես ես?
Output: ||||||||||
Result: 10

Input : நீங்கள் எப்படி இருக்கிறீர்கள்?
Output: ||||||||||||||||||||||
Result: 22

Input : ਤੁਸੀਂ ਕਿਵੇਂ ਹੋ?
Output: ||||||||||
Result: 10

Input : 👩‍🔬
Output: ||
Result: 2

Input : 𝓽𝓱𝓲𝓼 𝓲𝓼 𝓬𝓸𝓸𝓵
Output: ||||||||||||
Result: 12

Input : (-■_■)
Output: ||||||
Result: 6

Input : (☞ﾟ∀ﾟ)☞
Output: |||||||
Result: 7

Input : █ ▄ █ ▄ ▄ █ ▄ █ ▄ █
Output: |||||||||||||||||||
Result: 19

Input : ／人 ◕ ‿‿ ◕ 人＼
Output: ||||||||||||||||
Result: 16

Input : ▣ ■ □ ▢ ◯ ▲ ▶ ► ▼ ◆ ◢ ◣ ◤ ◥
Output: |||||||||||||||||||||||||||
Result: 27

Input : ₁₂₃₄
Output: ||||
Result: 4
```