#include "game_of_life.hpp"

int         count_connections(t_info *info, int i, int j)
{
    int     count;

    count = 0;
    if (i != 0 && j != 0 && info->map_int[i - 1][j - 1] == 1)
        ++count;
    if (i != 0  && info->map_int[i - 1][j] == 1)
        ++count;
    if (i != 0 && j != info->map_size - 1 && info->map_int[i - 1][j + 1] == 1)
        ++count;
    if (j != 0 && info->map_int[i][j - 1] == 1)
        ++count;
    if (j != info->map_size - 1 && info->map_int[i][j + 1] == 1)
        ++count;
    if (i != info->map_size - 1 && j != 0 && info->map_int[i + 1][j - 1] == 1)
        ++count;
    if (i != info->map_size - 1  && info->map_int[i + 1][j] == 1)
        ++count;
    if (i != info->map_size - 1 && j != info->map_size - 1 && info->map_int[i + 1][j + 1] == 1)
        ++count;
    return (count);
}

void        apply_changes(t_info *info)
{
    int     i;
    int     j;
    int     count;
    int     **new_arr;

    i = 0;
    new_arr = (int **)malloc(sizeof(int *) * info->map_size);
    while (i < info->map_size)
    {
        j = 0;
        new_arr[i] = (int *)malloc(sizeof(int) * info->map_size);
        while (j < info->map_size)
        {
            count = 0;
            count = count_connections(info, i, j);
            if (count < 2 && info->map_int[i][j] == 1)
                new_arr[i][j] = 0;
            else if (count > 3 && info->map_int[i][j] == 1)
                new_arr[i][j] = 0;
            else if (count == 3 && info->map_int[i][j] == 0)
                new_arr[i][j] = 1;
            else
                new_arr[i][j] = info->map_int[i][j];
            ++j;            
        }
        ++i;
    }
    info->map_int = new_arr;
}