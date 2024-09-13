/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utiles2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:12:32 by oussama           #+#    #+#             */
/*   Updated: 2023/02/28 18:37:39 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_angle_value(char c, t_map *var)
{
	if (c == 'N')
		var->rotation_angle = 3 * (M_PI / 2);
	if (c == 'S')
		var->rotation_angle = M_PI / 2;
	if (c == 'E')
		var->rotation_angle = 0;
	if (c == 'W')
		var->rotation_angle = M_PI;
}

void	get_player_postion(t_map *var, int x, int y)
{
	var->x = (double)x * T_S + T_S / 2.0;
	var->y = (double)y * T_S + T_S / 2.0;
}

int	len_2_map(t_map *map, int i)
{
	int	len;
	int	j;

	len = 0;
	while (i < map->lenght)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '1' || map->map[i][j] == '0')
			{
				len++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (len);
}

void	ft_fill_var(t_map *map, int i, int f, int *x)
{
	int	j;

	j = 0;
	while (map->map[i][j] != '\0')
	{
		if (map->map[i][j] == '1' || map->map[i][j] == '0')
		{
			map->var[*x] = word_dup(map->map[i], j, ft_strlen(map->map[i]) - 1);
			f--;
			(*x)++;
			return ;
		}
		else if (map->map[i][j] == '\n')
			ft_error_msg(map);
		j++;
	}
}

void	ft_take_var(t_map *map, int *index)
{
	int	x;
	int	f;
	int	i;

	x = 0;
	i = *index;
	map->count_line = len_2_map(map, i);
	map->var = malloc(sizeof(char *) * (map->count_line + 1));
	f = map->count_line;
	while (i < map->lenght && f != 0)
	{
		ft_fill_var(map, i, f, &x);
		i++;
	}
	map->var[x] = NULL;
	*index = i;
}
