/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:08 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/03 14:35:09 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_file	*file;
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		return (0);
	}
	file = ft_get_coord(argv[1]);
	/*if (file->first_y != NULL)
	{
		file->current = file->first_y;
		printf("TAB Y\n");
		while (file->current->next != NULL)
		{
			printf("x: %d - y: %d - z: %d\n", file->current->x, file->current->y, file->current->z);
			file->current = file->current->next;
		}
		printf("x: %d - y: %d - z: %d\n\n\n", file->current->x, file->current->y, file->current->z);
	}
	if (file->first_x != NULL)
	{
		file->current = file->first_x;
		printf("TAB X\n");
		while (file->current->next != NULL)
		{
			printf("x: %d - y: %d - z: %d\n", file->current->x, file->current->y, file->current->z);
			file->current = file->current->next;
		}
		printf("x: %d - y: %d - z: %d\n\n\n", file->current->x, file->current->y, file->current->z);
	}*/
	open_new(file);
	return (0);
}
