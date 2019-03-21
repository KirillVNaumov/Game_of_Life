#include "game_of_life.hpp"

void            map_from_char_to_int(t_info *info)
{
    int         i;
    int         j;

    info->map_int = (int **)malloc(sizeof(int *) * info->map_size);
    i = 0;
    while (info->map_char[i])
    {
        j = 0;
        info->map_int[i] = (int *)malloc(sizeof(int) * (info->map_size));
        while (info->map_char[i][j])
        {
            if (info->map_char[i][j] == '0')
                info->map_int[i][j] = 0;
            else
                info->map_int[i][j] = 1;
            ++j;
        }
        ++i;
    }
}