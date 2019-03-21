#include "game_of_life.hpp"

void        check_map(t_info *info)
{
    int     i;
    int     length;

    length = strlen(info->map_char[0]);
    while (info->map_char[i])
    {
        if (strlen(info->map_char[i]) != length)
            error ("Map size error");
        ++i;
    }
    if (length != i)
        error ("Map size error");
}

void        read_from_file(t_info *info)
{
    int index;
    char    *tmp;
    std::fstream infile;

    infile.open(info->file);
    index = 0;
    for (std::string line; std::getline(infile, line);) {

        if (!info->map_size)
        {
            tmp = new char[line.length() + 1];
            strcpy(tmp, line.c_str());
            read_size(info, tmp);
            info->map_char = (char **)malloc(sizeof(char *) * (info->map_size + 1));
        }
        else
        {
            info->map_char[index] = new char[line.length() + 1];
            strcpy(info->map_char[index], line.c_str());
            ++index;
        }
    }
    info->map_char[index] = NULL;
    check_map(info);
    infile.close();
}