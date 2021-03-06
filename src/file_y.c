/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:37:56 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/27 16:37:57 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_file		*ft_new_list_y(int x, int y, int z, int len)
{
	t_file		*file;
	t_one		*ini;

	file = (t_file*)malloc(sizeof(*file));
	if (!file)
		ft_error();
	if (len == 1)
	{
		file->first_y = NULL;
		return (file);
	}
	ini = (t_one*)malloc(sizeof(*ini));
	if (!ini)
		ft_error();
	ini->x = x;
	ini->y = y;
	ini->z = z;
	ini->color = get_color(z);
	ini->update = 0;
	if (z != 0)
		ini->update = 1;
	ini->next = NULL;
	file->first_y = ini;
	file->current = ini;
	return (file);
}

t_file		*ft_add_list_y(t_file *file, int x, int y, int z)
{
	t_one		*new;

	if (!file)
		ft_error();
	new = (t_one*)malloc(sizeof(*new));
	if (!new)
		ft_error();
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = get_color(z);
	new->update = 0;
	if (z != 0)
		new->update = 1;
	new->next = NULL;
	while (file->current->next != NULL)
		file->current = file->current->next;
	file->current->next = new;
	if (file->first_y->next == NULL)
		file->first_y->next = file->current->next;
	return (file);
}

int			ft_test(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

t_file		*ft_create_y(char **reader)
{
	int		x;
	int		y;
	int		len;
	char	**tab;
	t_file	*file;

	y = -1;
	len = 0;
	while (reader[++y] != 0)
	{
		x = -1;
		tab = ft_strsplit(reader[y], ' ');
		if (len == 0)
			len = ft_test(tab);
		if (x == -1 && y == 0)
		{
			file = ft_new_list_y(0, 0, ft_atoi(tab[0]), len);
			if (len == 1)
				return (file);
			x++;
		}
		while (tab[++x] != NULL)
			file = ft_add_list_y(file, x, y, ft_atoi(tab[x]));
	}
	return (file);
}
