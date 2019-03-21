#include "game_of_life.hpp"

void        read_size(t_info *info, char *str)
{
    if (check_for_number(str) == -1 || strlen(str) > 10 || check_for_integer(str) == -1)
        error("Invalid number for map size");
    info->map_size = atoi(str);
}