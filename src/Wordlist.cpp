#include <vector>
#include <string>

#include "..\hdr\Random.h"
#include "..\hdr\Wordlist.h"

namespace WordList {
  std::vector<std::string_view> word_list { 
    "mystery", "broccoli", "account", "luggage", "distance","beautiful", 
    "opinion", "spaghetti", "pizza", "lasagna", "computer"
  };

  std::string_view WordList::getRandomWord() {
    std::size_t max = WordList::word_list.size() - 1;
    std::size_t index{ Random::get<std::size_t>(0, max) };
    return WordList::word_list.at(index);
  }
}