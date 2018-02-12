#include <iostream>
#include <map>
#include <array>
#include <algorithm>
#include <type_traits>


int main()
{
  using dictionary_t = std::multimap<char, char>;
  using hieroglyph_t = std::array<char, 3>;

  int count = 0;
  std::cin >> count;

  dictionary_t dictionary;
  hieroglyph_t hieroglyph;
  for(int i = 0; i < count; i++)
  {
    std::cin >> hieroglyph.data();
    dictionary.emplace(std::make_pair(hieroglyph.at(0), hieroglyph.at(1)));
  }

  char first_char;
  std::cin >> first_char;

  auto lambda = [first_char](auto& it)
  {
    if(it.first == first_char)
      return true;
    return false;
  };

  auto found = dictionary.find(first_char);
  while (found != dictionary.end())
  {
    std::cout << found->first << found->second << std::endl;
    found = std::find_if(++found, dictionary.end(), lambda);
  }

  return 0;
}

