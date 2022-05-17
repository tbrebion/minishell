/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/17 11:47:51 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

static void	here_doc_supply(char *file, char *limiter)
{
	pid_t	pid;
	char	*line;
	int	fd;

	fd = open(file, O_WRONLY | O_RDONLY | O_CREAT | O_APPEND, 0777);
	dup2(fd, 0);
	pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			//line = get_next_line(fd);
			line = readline("heredoc> ");
			if ((ft_strncmp(line, limiter, ft_max(ft_strlen(line), ft_strlen(limiter))) == 0))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			free(line);
		}
	}
	else
	{
		wait(0);
		/*while(1)
		{
			ft_printf("%s", get_next_line(fd));
		}*/
	}
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
	//fd = open(av[1], O_WRONLY | O_RDONLY | O_CREAT | O_APPEND, 0777);
	here_doc_supply(av[1], av[1]);
}
