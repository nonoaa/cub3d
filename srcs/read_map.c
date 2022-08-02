#include "cub3d.h"

int	map_valid_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("01NSEW ", str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_type type_info(char *str)
{
    if (str[0] == 'N' && str[1] == 'O')
        return (E_NO);
    else if (str[0] == 'S' && str[1] == 'O')
        return (E_SO);
    else if (str[0] == 'W' && str[1] == 'E')
        return (E_WE);
    else if (str[0] == 'E' && str[1] == 'A')
        return (E_EA);
    else if (str[0] == 'F' && str[1] == ' ')
        return (E_FLOOR);
    else if (str[0] == 'C' && str[1] == ' ')
        return (E_CEILING);
    else if (map_valid_check(str))
        return (E_MAP);
    else
        return (E_ERROR);   
}

void handle_info(t_game *game, char *line, t_type type)
{
    
}

void    read_map(t_game *game)
{
    char *line;
    t_type type;
    int read_size;

    while (1)
    {
        read_size = get_next_line(game->map.map_fd, &line);
        if (read_size < 0)
            err_exit("read error");
        else if (read_size == 0)
        {
            free(line);
            break;
        }
        type = type_info(line);
        if (type == E_ERROR)
			err_exit("Wrong map information");
        handle_info(game, line, type);
    }

}