#ifndef GAME_OF_LIFE
# define GAME_OF_LIFE

#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>

#define HL          "\u2501"
#define VL          "\u2503"
#define RLA         "\u251B"
#define LLA         "\u2517"
#define RUA         "\u2513"
#define LUA         "\u250F"

# define CRED       "\x1B[31m"
# define CLEAN      "\e[1;1H\e[2J"

typedef struct      s_info
{
    char            **map_char;
    int             **map_int;
    int             map_size;
    char            *file;
    int             graphics;
    int             reversed;
    int             speed;
}                   t_info;

void                apply_changes(t_info *info);

/*
    Main
*/

void                error(std::string reason);
void                usage();

/*
    Read_from_file
*/

void                read_from_file(t_info *info);
void                map_from_char_to_int(t_info *info);

/*
    Parse_args
*/

void                read_size(t_info *info, char *str);
void                read_file(t_info *info, char *str);
void                read_speed(t_info *info, char *str);
void                parse_args(t_info *info, int argc, char **argv);

/*
    Run_simulation_no_graphics
*/

void                run_simulation_no_graphics(t_info *info);
void                draw_map_no_graphics(t_info *info);

/*
    Utils
*/

int                 check_for_number(char *line);
int		            check_for_integer(char *str);


#endif