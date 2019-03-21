#include "game_of_life.hpp"

void        read_file(t_info *info, char *str)
{
    if (*str == '-')
        usage();
    info->file = str;
}