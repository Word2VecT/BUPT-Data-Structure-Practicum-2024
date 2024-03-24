#include <iostream>
#include <random>

constexpr int MIN = 1;
constexpr int MAX = 1000;

int main() {
  std::random_device rdm;
  std::mt19937 mt_rand(rdm());
  std::uniform_int_distribution<int> dist(MIN, MAX);

  int const price = dist(mt_rand);
  int guess = 0;
  int tries = 1;

  std::cout << "Guess the price of the item between " << MIN << " and " << MAX
            << " (inclusive):";
  std::cin >> guess;
  std::cout << std::endl;
  while (guess != price) {
    tries++;
    if (guess > price) {
      std::cerr << "Too high!" << std::endl;
    } else {
      std::cerr << "Too low!" << std::endl;
    }
    std::cout << "Guess again:";
    std::cin >> guess;
    std::cout << std::endl;
  }

  std::cout << "Congratulations! You guessed the price! You guessed " << tries << " times" << std::endl;
}