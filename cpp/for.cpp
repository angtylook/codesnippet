#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

constexpr int kPrime1 = 9431;
constexpr int kPrime2 = 9433;
constexpr int kSalt = 0;
constexpr int kCodeLen = 8;
constexpr int kCodeSize = 52;
constexpr std::array<char, kCodeSize> alphabets = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'
};

int indexOf(char c) {
    for (int i = 0; i < alphabets.size(); i++) {
        if (alphabets[i] == c) {
            return i;
        }
    }
    return -1;  // unreachable code
}

std::string GenCode(int id) {
    id = id * kPrime1;
    id = id + kSalt;
    std::array<int, kCodeLen> numbers = {};
    numbers[0] = id;
    for (int i = 0; i < kCodeLen - 2; i++) {
        numbers[i + 1] = numbers[i] / kCodeSize;
        numbers[i] = (numbers[i] + numbers[0] * i) % kCodeSize;
    }
    int halfSize = kCodeLen / 2;
    for (int i = 0; i < halfSize; i++) {
        numbers[kCodeLen - 2] += numbers[i];
    }
    numbers[kCodeLen - 2] = (numbers[kCodeLen - 2] * kPrime1) % kCodeSize;
    for (int i = halfSize; i < kCodeLen-1; i++) {
        numbers[kCodeLen - 1] += numbers[i];
    }
    numbers[kCodeLen - 1] = (numbers[kCodeLen - 1] * kPrime1) % kCodeSize;

    std::string result;
    result.reserve(kCodeLen);
    for (int i = 0; i < kCodeLen; i++) {
        int index = i * kPrime2 % kCodeLen;  // src i ==> dst index (ÏÂ±ê×ª»»)
        result.append(1, alphabets[numbers[index]]); 
    }
    return result;
}

int DeCode(std::string code) {
    if (code.size() != kCodeLen) {
        return -1;
    }
    int res = 0;

    std::array<int, kCodeLen> index = {};
    for (int i = 0; i < kCodeLen; i++) {
        index[i * kPrime2 % kCodeLen] = i;  // dst index ==> src i
    }
    std::array<char, kCodeLen> chars;
    for (int i = 0; i < kCodeLen; i++) {
        chars[i] = code[index[i]];
    }

    for (int i = 0; i < kCodeLen; i++) {
        index[i] = indexOf(chars[i]);
    }

    std::array<int, kCodeLen> numbers = {};

    int halfSize = kCodeLen / 2;
    for (int i = 0; i < halfSize; i++) {
        numbers[kCodeLen - 2] += index[i];
    }
    numbers[kCodeLen - 2] = (numbers[kCodeLen - 2] * kPrime1) % kCodeSize;
    for (int i = halfSize; i < kCodeLen-1; i++) {
        numbers[kCodeLen - 1] += index[i];
    }
    numbers[kCodeLen - 1] = (numbers[kCodeLen - 1] * kPrime1) % kCodeSize;
    
    if (numbers[kCodeLen - 2] != index[kCodeLen - 2] ||
        numbers[kCodeLen - 1] != index[kCodeLen - 1]) {
        return -1;
    }
    for (int i = kCodeLen - 3; i >= 0; i--) {
        numbers[i] = (index[i] - index[0] * i + kCodeSize * i) % kCodeSize;
    }
    for (int i = kCodeLen - 3; i > 0; i--) {
        res += numbers[i];
        res *= kCodeSize;
    }
    res = (res + numbers[0] - kSalt) / kPrime1;
    return res;
}

int main()
{
    auto code = GenCode(9999);
    std::cout << 9999 << " -> " << code << std::endl;
    std::cout << code << " -> " << DeCode(code) << std::endl;
    std::vector<std::string> codes;
    for (int i = 1000000; i < 1000010; i++) {
        auto code = GenCode(i);
        std::cout << i << " -> " << code << std::endl;
        codes.push_back(code);
    }
    for (auto& code : codes) {
        std::cout << code << " -> " << DeCode(code) << std::endl;
    }
    return 0;
}

