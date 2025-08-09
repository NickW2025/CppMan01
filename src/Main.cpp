#include <iostream>
#include <vector>

#include "../hdr/Session.h"
#include "../hdr/Wordlist.h"

void playGame();

int main() {
  playGame();

  while (true) {
    char c{};
    std::cout << "\nPlay again? (y/n) ";
    std::cin >> c;
    if (c == 'y') playGame();
    else if (c == 'n') break;
  }

  return 0;
}

void playGame() {
  std::cout << "\n\nWelcome to CppMan!\nTo win : guess the word.\n"
    << "To lose : run out of(#) attempts.\n";

  Session session{ WordList::getRandomWord() };

  while (!session.isWon() && session.getAttempts() > 0) {
    session.updateSessionState();
  }

  if (session.isWon()) std::cout << "\nCongratulations! You Win!\n"
    << "The Word was : " << session.getSecretWord() << "!\n";
  else std::cout << "\nYou Lose. \nThe Word was: " << session.getSecretWord() << ".\n";

  std::cout << "Thank you for playing!\n";
  return;
}


