#include "game_of_life.hpp"

void        usage() 
{
    std::cout << "Usage: ./exe [flags ...]" << std::endl;
    std::cout << "Flags: " << std::endl;
    std::cout << "--graphics = turn on graphics" << std::endl;
    std::cout << "--reverse = reversed Game of Life" << std::endl;
    std::cout << "--size [size] = size of the map (only for '--graphics')" << std::endl;
    std::cout << "--speed [0/1/2/3/4] = speed of the simulation" << std::endl;
    std::cout << "--file [file] = read map from file" << std::endl;
    exit(0);
}

void        error(std::string reason) 
{
    std::cout << CRED << "Error: " << reason << std::endl;
    exit(0);
}

void        info_init(t_info *info)
{
    info->map_char = NULL;
    info->map_int = NULL;
    info->file = NULL;
    info->map_size = 0;
    info->graphics = 0;
    info->reversed = 0;
    info->speed = 0;
}

int         main(int argc, char **argv)
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    std::cout << CLEAN;
    info_init(info);
    parse_args(info, argc, argv);
    if (info->file)
    {
        read_from_file(info);
        map_from_char_to_int(info);
    }
    if (!info->graphics)
        run_simulation_no_graphics(info);
    return (0);
}