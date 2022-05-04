/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:54:00 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/04 15:07:43 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	display_prompt(char **my_env)
{
	char	*cwd;
	//char	*user_line;
	//char	*to_print;
	//int		i;
	char	buff[4096 + 1];
	(void)my_env;

	//i = 0;
	cwd = getcwd(buff, 4096);
	/*user_line = catch_user(my_env);
	while ((ft_strnstr(cwd, catch_username(user_line)user_line + 5, ft_strlen(cwd))))
		i++;*/
	ft_printf("%s", cwd /*+ i*/);
	ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
}
