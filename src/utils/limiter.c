/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/16 15:27:38 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

static void	here_doc_supply(char *limiter)
{
	pid_t	pid;
	char	*line;
	//char	*tab[4096];
	//int		i;

	//i = 0;
	pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			/*line = malloc(ft_strlen(limiter));
			if (!line)
				return ;*/
			line = readline("heredoc> ");
			if ((ft_strncmp(line, limiter, ft_max(ft_strlen(line), ft_strlen(limiter))) == 0))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			//tab[i] = line;
			//i++;
			free(line);
		}
	}
	else
	{
		wait(0);
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
	int	fd;

	(void)ac;
	fd = open(av[1], O_WRONLY | O_RDONLY | O_CREAT | O_APPEND, 0777);
	here_doc_supply(av[1]);
}
