#include "game_of_life.hpp"

void        parse_args(t_info *info, int argc, char **argv)
{
    int     i;

    i = 1;
    while (i < argc)
    {
        if (!strcmp(argv[i], "--size"))
        {
            if (i == argc - 1)
                usage();
            read_size(info , argv[i + 1]);
        }
        if (!strcmp(argv[i], "--speed"))
        {
            if (i == argc - 1)
                usage();
            read_speed(info , argv[i + 1]);
        }
        else if (!strcmp(argv[i], "--file"))
        {
            if (i == argc - 1)
                usage();
            read_file(info , argv[i + 1]);
        }
        else if (!strcmp(argv[i], "--graphics"))
        {
            info->graphics = 1;
        }
        else if (!strcmp(argv[i], "--reversed"))
            info->reversed = 1;
        ++i;
    }
    if (!info->file && !info->graphics)
        usage();
}