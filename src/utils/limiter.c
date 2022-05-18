/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/18 09:22:45 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

static void	here_doc_supply(char *limiter)
{
	char	*line;
	char	*ret;
	int	fd;

	ret = NULL;
	fd = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		ft_putstr("here_doc> ");
		line = get_next_line(0);
		ret = ft_strjoin(ret, line);
		if ((ft_strncmp(line, limiter, ft_max((ft_strlen(line) - 1), ft_strlen(limiter))) == 0))
		{
			free(line);
			//free(ret);
			//exit(EXIT_SUCCESS);
			break ;
		}
		ft_putstr_fd(ret, fd);
		//free(ret);
		free(line);
	}
	while (get_next_line(fd))
		ft_putstr(get_next_line(fd));
	close(fd);
}
/*
void	her_doc(char *input)
{
	int		fd;
	int		i;
	char	**split_input;

	i = -1;
	split_input = ft_split(input, ' ');
	fd = open(split_input[1], O_RDONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		return ;
	here_doc_supply(split_input[1]);
	while (split_input[++i])
		free(split_input[i]);
	free(split_input);
}
*/

int	main(int ac, char **av)
{
	(void)ac;
	here_doc_supply(av[1]);
}
