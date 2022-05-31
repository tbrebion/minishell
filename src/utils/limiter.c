/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/31 15:01:28 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

void	here_doc(char *limiter)
{
	char	*line;
	char	*ret;
	//int		fd;
	int		i;

	ret = NULL;
	//fd = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	i = 0;
	signal(SIGINT, &interrupt_here_doc);
	while (1)
	{
		ft_putstr("here_doc> ");
		line = get_next_line(0);
		if ((ft_strncmp(line, limiter, ft_max((ft_strlen(line) - 1), ft_strlen(limiter))) == 0))
		{
			free(line);
			break ;
		}
		ret = ft_strjoin(ret, line);
		//ft_putstr_fd(ret, fd);
		free(line);
	}
	ft_putstr(ret);
	//close(fd);
	free(ret);
	//unlink(".here_doc");
}
