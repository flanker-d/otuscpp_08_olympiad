#include <iostream>
#include <set>

int main()
{
  using submitters_t = std::set<std::string>;
  using spammers_t = std::set<std::string>;

  int count = 0;
  std::cin >> count;

  submitters_t submitters;
  spammers_t spammers;

  std::string submitter;
  for(int i = 0; i < count; i++)
  {
    std::cin >> submitter;

    auto found_spammer = spammers.find(submitter);
    if (found_spammer != spammers.end())
      continue;

    auto found_submitter = submitters.find(submitter);
    if (found_submitter == submitters.end())
      submitters.emplace(submitter);
    else
      spammers.emplace(submitter);
  }

  for(auto& spammer : spammers)
  {
    std::cout << spammer << std::endl;
  }

  return 0;
}

