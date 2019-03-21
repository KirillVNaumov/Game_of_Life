#include "game_of_life.hpp"

void        draw_map_no_graphics(t_info *info)
{
    int     i;
    int     j;

    std::cout << CLEAN;
    std::cout << LUA;
    i = 0;
    while (i++ != info->map_size)
        std::cout << HL;
    std::cout << RUA << std::endl;
    i = 0;
    while (i != info->map_size)
    {
        j = 0;
        std::cout << VL;
        while (j != info->map_size)
        {
            if (info->map_int[i][j] == 1)
                std::cout << "#";
            else
                std::cout << ".";
            ++j;
        }
        std::cout << VL << std::endl;
        ++i;
    }
    std::cout << LLA;
    i = 0;
    while (i++ != info->map_size)
        std::cout << HL;
    std::cout << RLA << std::endl;
}