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

void full_table(std::vector<std::string> full_sequence, int max_chances)
{
     int number_of_empty_rows = max_chances - full_sequence.size();
     std::cout << draw_between_row() << "\n";
     std::for_each(full_sequence.begin(), full_sequence.end(),
                   [&](std::string sequence)
                        {std::cout << draw_full_row(sequence) << "\n";
                             std::cout << draw_between_row() << "\n";});
     for (int iter = 0; iter < number_of_empty_rows; iter++)
     {
          std::cout << draw_empty_row() << "\n";
          std::cout << draw_between_row() << "\n";
     }
}
