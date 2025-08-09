#include <iostream>
#include <string>

#include "Session.h"
using std::size_t;

std::string_view Session::getSecretWord() const {
  return secret_word;
}

void Session::updateSessionState() {
  guessed_letters.push_back(inputCharacter());

  std::string output_word{""};

  std::cout << "Attempts remaining: ";
  for (int i{ 0 }; i < max_attempts; ++i) {
    if (i < attempts) std::cout << '#';
    else std::cout << '_';
  }
  std::cout << '\n';


  std::cout << "Incorrect Guesses so far: ";
  for (char c : incorrect_guesses) {
    std::cout << c << ' ';
  }
  std::cout << '\n';

  bool complete = true;
  for (size_t i{ 0 }; i < secret_word.size(); ++i) {
    if (contains(guessed_letters, secret_word.at(i))) {
      output_word.push_back(secret_word.at(i));
    }
    else {
      output_word.push_back('_');
      complete = false;
    }
  }
  
  if (complete) gameWon = true;
  else std::cout << output_word << "\n\n";
}

char Session::inputCharacter() {
  char chr{};
  std::cout << "\nEnter a character: ";
  std::cin >> chr;
  if (std::cin.eof()) {
    std::cout << "EOF Error.";
    exit(-1);
  }

  if (std::cin.fail()) {
    std::cout << "Invaild Input.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return inputCharacter();
  }

  if (!std::cin.eof() && std::cin.peek() != '\n') {
    std::cout << "Invaild Input.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return inputCharacter();
  }

  if (chr >= 65 && chr <= 90) chr += 32;

  if (chr >= 97 && chr <= 122) {
    if (contains(guessed_letters, chr)) {
      std::cout << "Already Guessed " << chr << ". Please try again.\n";
      return inputCharacter();
    }
    bool hit = false;
    for (size_t i{ 0 }; i < secret_word.size(); i++) {
      if (secret_word.at(i) == chr) hit = true;
    }
    if (!hit) { 
      --attempts; 
      incorrect_guesses.push_back(chr);
    }
    std::cout << '\n';
    return chr;
  }

  else {
    std::cout << "Invalid input.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return inputCharacter();
  }
}

bool Session::isWon() const {
  return gameWon;
}

int Session::getAttempts() const {
  return attempts;
}

bool contains(std::vector<char>& v_i, char chr_i) {
  for (size_t i{ 0 }; i < v_i.size(); ++i) {
    if (v_i.at(i) == chr_i) return true;
  }
  return false;
}