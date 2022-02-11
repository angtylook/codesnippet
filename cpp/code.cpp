#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

constexpr int64_t kPrime1 = 9431;
constexpr int64_t kPrime2 = 9433;
constexpr int64_t kSalt = 0;
constexpr int64_t kCodeLen = 20;
constexpr int64_t kCodeSize = 52;
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

int64_t indexOf(char c) {
    for (int64_t i = 0; i < alphabets.size(); i++) {
        if (alphabets[i] == c) {
            return i;
        }
    }
    return -1;  // unreachable code
}

std::string GenCode(int64_t id) {
    id = id * kPrime1;
    id = id + kSalt;
    std::array<int64_t, kCodeLen> numbers = {};
    numbers[0] = id;
    for (int64_t i = 0; i < kCodeLen - 2; i++) {
        numbers[i + 1] = numbers[i] / kCodeSize;
        numbers[i] = (numbers[i] + numbers[0] * i) % kCodeSize;
    }
    int64_t halfSize = kCodeLen / 2;
    for (int64_t i = 0; i < halfSize; i++) {
        numbers[kCodeLen - 2] += numbers[i];
    }
    numbers[kCodeLen - 2] = (numbers[kCodeLen - 2] * kPrime1) % kCodeSize;
    for (int64_t i = halfSize; i < kCodeLen-1; i++) {
        numbers[kCodeLen - 1] += numbers[i];
    }
    numbers[kCodeLen - 1] = (numbers[kCodeLen - 1] * kPrime1) % kCodeSize;

    std::string result;
    result.reserve(kCodeLen);
    for (int64_t i = 0; i < kCodeLen; i++) {
        int64_t index = i * kPrime2 % kCodeLen;  // src i ==> dst index (�±�ת��)
        result.append(1, alphabets[numbers[index]]); 
    }
    return result;
}

int64_t DeCode(std::string code) {
    if (code.size() != kCodeLen) {
        return -1;
    }
    int64_t res = 0;

    std::array<int64_t, kCodeLen> index = {};
    for (int64_t i = 0; i < kCodeLen; i++) {
        index[i * kPrime2 % kCodeLen] = i;  // dst index ==> src i
    }
    std::array<char, kCodeLen> chars;
    for (int64_t i = 0; i < kCodeLen; i++) {
        chars[i] = code[index[i]];
    }

    for (int64_t i = 0; i < kCodeLen; i++) {
        index[i] = indexOf(chars[i]);
    }

    std::array<int64_t, kCodeLen> numbers = {};

    int64_t halfSize = kCodeLen / 2;
    for (int64_t i = 0; i < halfSize; i++) {
        numbers[kCodeLen - 2] += index[i];
    }
    numbers[kCodeLen - 2] = (numbers[kCodeLen - 2] * kPrime1) % kCodeSize;
    for (int64_t i = halfSize; i < kCodeLen-1; i++) {
        numbers[kCodeLen - 1] += index[i];
    }
    numbers[kCodeLen - 1] = (numbers[kCodeLen - 1] * kPrime1) % kCodeSize;
    
    if (numbers[kCodeLen - 2] != index[kCodeLen - 2] ||
        numbers[kCodeLen - 1] != index[kCodeLen - 1]) {
        return -1;
    }
    for (int64_t i = kCodeLen - 3; i >= 0; i--) {
        numbers[i] = (index[i] - index[0] * i + kCodeSize * i) % kCodeSize;
    }
    for (int64_t i = kCodeLen - 3; i > 0; i--) {
        res += numbers[i];
        res *= kCodeSize;
    }
    res = (res + numbers[0] - kSalt) / kPrime1;
    return res;
}

int main()
{
    auto code = GenCode(1199513165897);
    std::cout << 1199513165897 << " -> " << code << std::endl;
    std::cout << code << " -> " << DeCode(code) << std::endl;
    std::vector<std::string> codes;
    for (int64_t i = 1199513165898; i < 1199513165998; i++) {
        auto code = GenCode(i);
        std::cout << i << " -> " << code << std::endl;
        codes.push_back(code);
    }
    for (auto& code : codes) {
        std::cout << code << " -> " << DeCode(code) << std::endl;
    }
    return 0;
}

