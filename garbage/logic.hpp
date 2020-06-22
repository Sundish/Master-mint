#include <random>
#include <chrono>
#include "graphfx.hpp"

class Mastermind_logic
{
private:
     int turn_number;
     std::string current_user_input;
     std::string curret_clue_output;
     std::string master_code;
     std::vector<std::string> ui_history;
     std::vector<std::string> co_history;
public:
     void user_input_cleaner();
     void auto_code_generator();
     void get_clues();
     void game_type_one();
     void game_type_two();
     void run();
};

void Mastermind_logic::auto_code_generator()
{
     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
     std::default_random_engine generator (seed);
     std::uniform_int_distribution<int> distribution(97, 102);
     for(int i = 0; i < 4; i++)
          master_code += (char)distribution(generator);
}

void Mastermind_logic::user_input_cleaner()
{
     std::string ui_temp;
     std::cin >> ui_temp;
     curret_clue_output.clear();
     current_user_input = ui_temp.length() >= 4 ? ui_temp.substr(0, 4) : "aaaa";
}

void Mastermind_logic::get_clues()
{
     int counter;
     std::vector<int> result{0, 0}; /*{red, white}*/
     counter = 0;
     std::for_each(current_user_input.begin(), current_user_input.end(),
                   [&](char const &user_c) mutable
                        {int find = master_code.find(user_c);
                             int parse_find = master_code.substr(counter, master_code.length()).find(user_c);
                             if (parse_find != std::string::npos && parse_find + counter == counter)
                                  curret_clue_output += '2';
                             else if ((find != std::string::npos || parse_find != std::string::npos) &&
                                      parse_find + counter != counter)
                                  curret_clue_output += '1';
                             else
                                  curret_clue_output += '0';
                             counter++;});
}

void Mastermind_logic::game_type_one()
{
     auto_code_generator();
     turn_number = 0;
     do
     {
          system("clear");
          print_full_table(ui_history, co_history, 10);
          user_input_cleaner();
          get_clues();
          ui_history.emplace_back(current_user_input);
          co_history.emplace_back(curret_clue_output);
          turn_number++;
     }while(turn_number < 10 && curret_clue_output != "2222");
     system("clear");
     print_full_table(ui_history, co_history, 10);
     turn_number == 10 ? std::cout << "You Failed! now suffer...\n" : std::cout << "You Win! but nothing happens...\n";
}

void Mastermind_logic::game_type_two()
{
     system("clear");
     std::cout << "Write the secret code: ";
     std::cin >> master_code;
     turn_number = 0;
     do
     {
          system("clear");
          print_full_table(ui_history, co_history, 10);
          user_input_cleaner();
          get_clues();
          ui_history.emplace_back(current_user_input);
          co_history.emplace_back(curret_clue_output);
          turn_number++;
     }while(turn_number < 10 && curret_clue_output != "2222");
     system("clear");
     print_full_table(ui_history, co_history, 10);
     turn_number == 10 ? std::cout << "You Failed! now suffer...\n" : std::cout << "You Win! but nothing happens...\n";
}

void Mastermind_logic::run()
{
     std::string notin;
     print_mastermind_rules();
     print_mastermind_menu();
     std::cin >> notin;
     game_type_one();
     std::cout << master_code;
}
