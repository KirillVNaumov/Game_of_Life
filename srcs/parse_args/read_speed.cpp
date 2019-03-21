#include "game_of_life.hpp"

void        read_speed(t_info *info, char *str)
{
    if (check_for_number(str) == -1 || strlen(str) > 10 || check_for_integer(str) == -1)
        error("Invalid number for speed");
    info->speed = atoi(str);
    if (info->speed != 0 && info->speed != 1 && \
        info->speed != 2 && info->speed != 3 && info->speed != 4)
        error("Invalid number for speed");
}