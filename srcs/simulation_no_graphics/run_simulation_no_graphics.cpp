#include "game_of_life.hpp"

void        usleep(int milliseconds)
{
    std::chrono::milliseconds timespan(milliseconds);
    
    std::this_thread::sleep_for(timespan);
}

void        wait(t_info *info)
{
     if (info->speed == 0)
        usleep(1000);
    else if (info->speed == 1)
        usleep(500);
    else if (info->speed == 2)
        usleep(300);
    else if (info->speed == 3)
        usleep(100);
    else if (info->speed == 4)
        usleep(50);
}

void        run_simulation_no_graphics(t_info *info)
{
    std::chrono::milliseconds timespan_3(300);
    std::chrono::milliseconds timespan_2(500);
    std::chrono::milliseconds timespan_1(1000);
    std::chrono::milliseconds timespan_0(2000);

    while (1)
    {
        draw_map_no_graphics(info);
        apply_changes(info);
        wait(info);
    }
}
