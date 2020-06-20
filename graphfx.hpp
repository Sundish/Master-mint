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

void print_full_table(std::vector<std::string> full_sequence, int max_chances)
{
     int number_of_empty_rows = max_chances - full_sequence.size();
     int help_counter;
     help_counter = 0;
     std::cout << "\t" << draw_between_row() << "\n";
     std::for_each(full_sequence.begin(), full_sequence.end(),
                   [&](std::string sequence)
                        {std::cout << "\t" << draw_full_row(sequence);
                             if (help_counter < 6)
                                  std::cout << draw_help(help_counter) << "\n";
                             help_counter++;
                             std::cout << "\t" << draw_between_row();
                             if (help_counter < 6)
                                  std::cout << draw_help(help_counter) << "\n";
                             help_counter++;});
     for (int iter = 0; iter < number_of_empty_rows; iter++)
     {
          std::cout << "\t" << draw_empty_row() << "\n";
          std::cout << "\t" << draw_between_row() << "\n";
     }
}
