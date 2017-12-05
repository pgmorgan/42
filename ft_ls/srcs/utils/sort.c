/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <vtouffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:18:41 by vtouffet          #+#    #+#             */
/*   Updated: 2017/12/04 11:31:12 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_swap_files(t_file *file1, t_file *file2)
{
	char		*name;
	char		*path;
	struct stat	stats;

	name = file1->name;
	path = file1->path;
	stats = file1->stats;
	file1->name = file2->name;
	file1->path = file2->path;
	file1->stats = file2->stats;
	file2->name = name;
	file2->path = path;
	file2->stats = stats;
}

void	ft_sort_files(t_file **files_list, int (*f)(t_file *file1, t_file *file2))
{
	t_file	*files;
	t_file	*ptr;
	int		swaped;

	files = *files_list;
	swaped = 1;
	while (swaped && files)
	{
		swaped = 0;
		ptr = *files_list;
		while (ptr->next)
		{
			if (f(ptr, ptr->next))
			{
				ft_swap_files(ptr, ptr->next);
				swaped = 1;
			}
			ptr = ptr->next;
		}
		files = files->next;
	}
}

void	ft_sort_files_reverse(t_file **files)
{
	t_file	*previous;
	t_file	*next;
	t_file	*current;

	previous = NULL;
	current = *files;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*files = previous;
}

void	ft_sort_tab_by_time(char **tab)
{
	int		index;
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		index = 0;
		while (tab[index])
		{
			if (tab[index + 1] &&
			ft_get_stats_from_name(tab[index]).st_mtimespec.tv_sec <
			ft_get_stats_from_name(tab[index + 1]).st_mtimespec.tv_sec)
				ft_swap(&tab[index], &tab[index + 1]);
			++index;
		}
		++i;
	}
}

void	ft_sort_params(t_options *params)
{
	if (!params->sort_by_time)
	{
		ft_sort_wordtab(params->folders);
		ft_sort_wordtab(params->files);
	}
	else
	{
		ft_sort_tab_by_time(params->folders);
		ft_sort_tab_by_time(params->files);
	}
	if (params->sort_reverse)
	{
		ft_reverse_tab(params->folders);
		ft_reverse_tab(params->files);
	}
}