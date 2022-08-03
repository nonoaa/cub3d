#include <cub3d.h>

void	err_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	free_split(char **split)
{
	int	idx;

	idx = -1;
	while (split[++idx])
	{
		free(split[idx]);
		split[idx] = 0;
	}
	free(split);
	split = 0;
}

int	arr_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ft_atoi_ad(const char *str)
{
	int	i;
	int	result;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			err_exit("put only 0 ~ 256 number in rgb");
		i++;
	}
	result = ft_atoi(str);
	if (result > 256 || result < 0)
		err_exit("out of rgb range");
	return (result);
}