#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/* DONE A way of keeping track of the past turns: a vector with strings going from oldest to newest.
 * DONE A function for coloring a object
 * DONE A function for printing one row
 * DONE A function for printing multiple rows
 */

std::string color_string (char what_color)
{
     switch(what_color)
     {
     case 'a': /* Black Color */
          return "\033[1;49;37m██\033[0m";
     case 'b': /* Red Color */
          return "\033[1;49;31m██\033[0m";
     case 'c': /* Green Color */
          return "\033[1;49;32m██\033[0m";
     case 'd': /* Yellow Color */
          return "\033[1;49;33m██\033[0m";
     case 'e': /* Purple Color */
          return "\033[1;49;34m██\033[0m";
     case 'f': /* Orange Color */
          return "\033[1;49;35m██\033[0m";
     default:
          return "ERROR";
     }
}

std::string draw_help (int help_number)
{
     switch(help_number)
     {
     case 0: /* Black Color */
          return "\ta = \033[1;49;37m█\033[0m";
     case 1: /* Red Color */
          return "\tb = \033[1;49;31m█\033[0m";
     case 2: /* Green Color */
          return "\tc = \033[1;49;32m█\033[0m";
     case 3: /* Yellow Color */
          return "\td = \033[1;49;33m█\033[0m";
     case 4: /* Purple Color */
          return "\te = \033[1;49;34m█\033[0m";
     case 5: /* Orange Color */
          return "\tf = \033[1;49;35m█\033[0m";
     default:
          return "ERROR";
     }
}

std::string draw_between_row(void)
{
     return "\033[1;49;30m█████████████\033[0m";
}

std::string draw_full_row(std::string user_sequence)
{
     std::string formated_row("\033[1;49;30m█");
     std::for_each(user_sequence.begin(), user_sequence.end(),
                   [&](char char_code)mutable
                        {formated_row += color_string(char_code) + "\033[1;49;30m█";});
     return formated_row + "\033[0m";
}

std::string draw_empty_row(void)
{
     return "\033[1;49;30m█\033[0m  \033[1;49;30m█\033[0m  \033[1;49;30m█\033[0m  \033[1;49;30m█\033[0m  \033[1;49;30m█\033[0m";
}

std::string stringme (int clue1, int clue2, int clue3, int clue4)
{
     std::string convstr;
     convstr = (char)(clue2 + 48) + (char)(clue3 + 48) + (char)(clue4 + 48) + (char)(clue1 + 48);
     return convstr;
}

void print_clue_mrow (std::string clue_sequence)
{
     int for_adder = 1;
     std::cout << " ";
     std::for_each(clue_sequence.begin(),
                   clue_sequence.end(), [&](char single_clue)
                                             {switch (single_clue){
                                                  case '0':for_adder++;break;
                                                  case '1':std::cout << "\033[1;49;30m█\033[0m";break;
                                                  case '2':std::cout << "\033[1;49;31m█\033[0m";break;}});
     for (int i = 0; i < for_adder; i++)
     {
          std::cout << " ";
     }
}

void print_empty_mrow (void)
{
     for (int e = 0; e < 6; e++)
     {
          std::cout << " ";
     }
}

void print_full_table(std::vector<std::string> full_sequence, std::vector<std::string> clue_sequence, int max_chances)
{
     int number_of_empty_rows = max_chances - full_sequence.size();
     int help_counter, sequence_counter;
     help_counter = 0;
     sequence_counter = 0;
     print_empty_mrow();
     std::cout << draw_between_row() << "\n";
     std::for_each(full_sequence.begin(), full_sequence.end(),
                   [&](std::string sequence)
                        {print_clue_mrow(clue_sequence.at(sequence_counter));
                             std::cout << draw_full_row(sequence);
                             if (help_counter < 6)
                                  std::cout << draw_help(help_counter) << "\n";
                             help_counter++;
                             print_empty_mrow();
                             std::cout << draw_between_row();
                             if (help_counter < 6)
                                  std::cout << draw_help(help_counter) << "\n";
                             help_counter++;
                             sequence_counter++;});
     for (int iter = 0; iter < number_of_empty_rows; iter++)
     {
          print_empty_mrow();
          std::cout << draw_empty_row() << "\n";
          print_empty_mrow();
          std::cout << draw_between_row() << "\n";
     }
}

void mastermind_rules(void)
{
     std::cout << "You are in the belly of A.M.\n";
     std::cout << "The only way to escape is to win\n";
     std::cout << "You got 10 turns..." << "\n";
     std::cout << "To enter a 4 number combination" << "\n";
     std::cout << "from a to f, for each number in the right place" << "\n";
     std::cout << "you get a 'r' and a 'w' for each number in the sequence\n";
     std::cout << "But in the wrong place.\n";
     std::cout << std::endl;
}
