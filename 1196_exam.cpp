#include <iostream>
#include <array>
#include <algorithm>

int main()
{
  using sensei_dates_t = std::array<int, 15000>;

  int sensei_dates_count = 0;
  std::cin >> sensei_dates_count;

  sensei_dates_t sensei_dates;//{1054, 1492};
  sensei_dates.fill(0);
  for(int i = 0; i < sensei_dates_count; i++)
  {
    std::cin >> sensei_dates.at(i);
  }

  int student_dates_count = 0;
  std::cin >> student_dates_count;

  int success_dates = 0;
  int student_date = 0;
  for(int i = 0; i < student_dates_count; i++)
  {
    std::cin >> student_date;
    if(std::binary_search(sensei_dates.begin(), sensei_dates.begin() + sensei_dates_count, student_date))
      success_dates++;
  }

  std::cout << success_dates << std::endl;

  return 0;
}

