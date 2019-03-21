#include "game_of_life.hpp"

int         check_for_number(char *line) {

    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] < '0' || line[i] > '9')
            return (-1);
        ++i;
    }
    return (1);
}

int		check_for_integer(char *str)
{
	if (str[0] == '-' || str[0] == '0' || strlen(str) > 10)
			return (-1);
	if (strlen(str) == 10 && strcmp(str, "2147483647") > 0)
			return (-1);
	return (0);
}