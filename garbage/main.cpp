#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <vector>


std::string generate_color_sequence(int sequence_size)
{
     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
     std::string gen_code;
     std::default_random_engine generator (seed);
     std::uniform_int_distribution<int> distribution(49, 54);
     for(int i = 0; i < sequence_size; i++)
          gen_code += (char)distribution(generator);
     return gen_code;
}

std::vector<int> seqcmp(std::string &user_sequence, std::string &t_sequence)
{
     int counter;
     std::vector<int> result{0, 0}; /*{red, white}*/
     counter = 0;
     std::for_each(user_sequence.begin(), user_sequence.end(),
                   [&](char const &user_c) mutable
                        {int find = t_sequence.find(user_c);
                             int parse_find = t_sequence.substr(counter, t_sequence.length()).find(user_c);
                             if (parse_find != std::string::npos && parse_find + counter == counter)
                                  result.front()++;
                             else if ((find != std::string::npos || parse_find != std::string::npos) &&
                                      parse_find + counter != counter)
                                  result.back()++;
                             counter++;});
     return result;
}

std::string get_safe_input(std::string &user_input, int min_len)
{
     std::string safe_input(user_input.length() > min_len ?
                            user_input.substr(0, min_len) : user_input);
     return safe_input;
}

void print_clues(std::vector<int> r_seqcmp)
{
     std::cout << "AM: ";
     for (int red = 0; red < r_seqcmp.front(); ++red)
          std::cout << "r";
     for (int white = 0; white < r_seqcmp.back(); ++white)
          std::cout << "w";
     std::cout << "\n";
     std::cout << "────────" << "\n";
}

void mastermind_rules(void)
{
     std::cout << "You are in the belly of A.M.\n";
     std::cout << "The only way to escape is to win\n";
     std::cout << "You got 10 turns..." << "\n";
     std::cout << "To enter a 4 number combination" << "\n";
     std::cout << "from 1 to 6, for each number in the right place" << "\n";
     std::cout << "you get a 'r' and a 'w' for each number in the sequence\n";
     std::cout << "But in the wrong place.\n";
     std::cout << std::endl;
}

void mastermind_main(void)
{
     std::vector<int> code_result;
     std::string user_sequence, real_sequence(generate_color_sequence(4));
     int turn_number;
     turn_number = 0;
     do
     {
          ++turn_number;
          std::cout << "P1: ";
          std::cin >> user_sequence;
          user_sequence = get_safe_input(user_sequence, 4);
          code_result = seqcmp(user_sequence, real_sequence);
          print_clues(code_result);
     }while(code_result.front() != 4 && turn_number < 10);
     turn_number >= 10 ? std::cout << "You Failed! now suffer...\n" : std::cout << "You Win! but nothing happens...\n";
}

int main(int argc, char** argv)
{
     if (argc == 1)
     {
          mastermind_rules();
          mastermind_main();
     }
     if (argc != 0 && argv[1] == "-r")
          mastermind_main();
     return 0;
}
