/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeier < imeier@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:30:59 by imeier            #+#    #+#             */
/*   Updated: 2024/11/11 19:32:29 by imeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	content[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*safe;
	int			flag;

	safe = NULL;
	flag = 0;
	if (fd < 0 || fd > FOPEN_MAX || !BUFFER_SIZE || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
			return (ft_null_buff(content[fd]));
		return (NULL);
	}
	while (content[fd][0] || read(fd, content[fd], BUFFER_SIZE) > 0)
	{
		safe = ft_content_safer(safe, content[fd]);
		ft_manage_buff(content[fd], &flag);
		if (flag)
			break ;
	}
	return (safe);
}
