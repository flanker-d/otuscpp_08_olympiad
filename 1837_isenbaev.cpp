#include <iostream>
#include <map>
#include <list>
#include <limits>
#include <memory>

struct node
{
  using ref = std::shared_ptr<node>;

  std::string name;
  bool is_visited = false;
  int isenbaev_number = std::numeric_limits<int>::max();
  std::map<std::string, node::ref> teammates;

  node(const std::string& name_) : name(name_) {}
};

class isenbaev_number
{
  public:
    void add_command(const std::string& first, const std::string& second, const std::string& third)
    {
      auto first_it = create_or_get_person(first);
      auto second_it = create_or_get_person(second);
      auto third_it = create_or_get_person(third);

      linking_teammates(first_it, second_it);
      linking_teammates(first_it, third_it);
      linking_teammates(second_it, third_it);
    }

    void find_isenbaev_numbers()
    {
      auto isenbaev = get_person("Isenbaev");
      if(isenbaev != m_persons.end())
      {
        std::list<node::ref> queue;

        int isenbaev_num = 0;
        isenbaev->second->is_visited = true;
        isenbaev->second->isenbaev_number = isenbaev_num;

        queue.push_back(isenbaev->second);

        node::ref person;
        while (!queue.empty())
        {
          person = queue.front();
          queue.pop_front();
          isenbaev_num = person->isenbaev_number + 1;
          for(auto& it : person->teammates)
          {
            if(!it.second->is_visited)
            {
              it.second->is_visited = true;
              it.second->isenbaev_number = isenbaev_num;
              queue.push_back(it.second);
            }
          }
        }
      }
    }

    void print_persons()
    {
      for(auto& it : m_persons)
      {
        if(it.second->isenbaev_number == std::numeric_limits<int>::max())
          std::cout << it.second->name << " undefined" << std::endl;
        else
          std::cout << it.second->name << " " << it.second->isenbaev_number << std::endl;
      }
    }

  private:
    std::map<std::string, node::ref>::iterator create_or_get_person(const std::string& name)
    {
      auto first_it = m_persons.find(name);
      if(first_it == m_persons.end())
      {
        m_persons.emplace(std::make_pair(name, std::make_shared<node>(name)));
      }
      return m_persons.find(name);
    }

    std::map<std::string, node::ref>::iterator get_person(const std::string& name)
    {
      return m_persons.find(name);
    }

    void linking_teammates(std::map<std::string, node::ref>::iterator first_person, std::map<std::string, node::ref>::iterator second_person)
    {
      first_person->second->teammates[second_person->first] = second_person->second;
      second_person->second->teammates[first_person->first] = first_person->second;
    }

  private:
    std::map<std::string, node::ref> m_persons;
};


int main()
{
  int count = 0;
  std::cin >> count;

  std::string first;
  std::string second;
  std::string third;
  isenbaev_number isen;
  for(int i = 0; i < count; i++)
  {
    std::cin >> first >> second >> third;
    isen.add_command(first, second, third);
  }
  isen.find_isenbaev_numbers();
  isen.print_persons();

  return 0;
}

