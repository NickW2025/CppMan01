#include <iostream>
#include <vector>

#include "../hdr/Session.h"
#include "../hdr/Wordlist.h"

int main() {
  std::cout << "Welcome to CppMan!\nTo win : guess the word.\n"
            << "To lose : run out of(#) attempts.\n";
  Session session{ WordList::getRandomWord() };

  while (!session.isWon() && session.getAttempts() > 0) {
    session.updateSessionState();
  }

  if (session.isWon()) std::cout << "\nCongratulations! You Win!\nThe Word was: " 
      << session.getSecretWord() << "!\n";
  else std::cout << "\nYou Lose. \nThe Word was: " << session.getSecretWord() << ".\n";

  std::cout << "Thank you for playing!\n";
  return 0;
}

