#ifndef CPPMAN_SESSION_H
#define CPPMAN_SESSION_H

#include <string>
#include <vector>

static bool contains(std::vector<char>&, char);
static void cinCleanup();

class Session {
  public:
    Session(std::string_view);
    void updateSessionState();
    std::string_view getSecretWord() const;
    bool isWon() const;
    int getAttempts() const;

  private:
    int max_attempts;
    int attempts;
    bool gameWon;
    char inputCharacter();
    std::string_view secret_word;
    std::vector<char> guessed_letters;
    std::vector<char> incorrect_guesses;
};

#endif