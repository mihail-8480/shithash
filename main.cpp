#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <streambuf>
#include <array>

template<std::size_t N>
std::array<char, N> hash(const auto& input) {
  std::array<char, N> arr{};

  auto f = [&arr](const auto& a, const auto& b) {
    for(std::size_t i = 0; i < N; i++) {
      arr[i] = a[i] ^ b[i];
    }
  };


  if (input.size() / N < 2) {
    char first[N]{0};
    char second[N]{0};

    for(std::size_t i = 0; i < input.size() / 2; i++) {
      first[i] = input[i];
    }

    for(std::size_t i = input.size() / 2; i < input.size(); i++) {
      second[input.size() / 2] = input[i];
    }

    f(first, second);

    return arr;
  }

  for (std::size_t i = 0; i < (std::size_t)floor((double)input.size() / N) + 1; i++) {
    char second[N]{0};
    for(std::size_t j = 0; j < N && i * N + j < input.size(); j++) {
      second[j] = input[i * N + j];
    }
    f(arr, second);
  }

  return arr;
}

#ifndef BITS
#define BITS 8
#endif

#ifndef LENGTH
#define LENGTH (BITS/8)
#endif

auto process(const std::istreambuf_iterator<char>& it) {
  std::string str((it), std::istreambuf_iterator<char>());
  auto value = hash<LENGTH>(str);

  std::cout << "0x";
  for (const auto &item: value) {
    std::cout << std::setfill('0') << std::setw(2) << std::hex << (int) (0xFF & item);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    process(std::istreambuf_iterator<char>(std::cin));
    return 0;
  } else if (argc != 2) {
    std::cout << argv[0] << ": no file specified" << std::endl;
    return 1;
  }

  std::ifstream t(argv[1]);
  if (!t.is_open()) {
    std::cout << argv[0] << ": couldn't open file" << std::endl;
    return 1;
  }

  process(std::istreambuf_iterator<char>(t));

  return 0;
}