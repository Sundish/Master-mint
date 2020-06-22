#include "logic.hpp"


struct player
{
     std::string name;
     int local_points;
     int global_points;
};


class Mastermind_game
{
private:
     player p1, p2;
     int current_round;
     int max_rounds;
     Mastermind_logic logic_core;
     bool initialize_round();
     void full_reset_player(std::string p1_name, std::string p2_name);
     void reset_player();
public:
     void start();
};

bool Mastermind_game::initialize_round()
{
     if (current_round < max_rounds)
     {
          current_round++;
          return false;
     }
     else
          return true;
}

void Mastermind_game::full_reset_player(std::string p1_name, std::string p2_name)
{
     p1.name = p1_name;
     p1.local_points = 0;
     p1.global_points = 0;
     p2.name = p2_name;
     p2.local_points = 0;
     p2.global_points = 0;
}

void Mastermind_game::reset_player()
{
     p2.local_points = 0;
     p1.local_points = 0;
}

void Mastermind_game::start()
{
     /*Something*/
}
