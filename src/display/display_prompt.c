/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:54:00 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/10 14:22:08 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
char	*display_prompt(char **my_env)
{
	char	*cwd;
	char	*user_line;
	char	*tmp_ret;
	char	*tmp_2_ret;
	char	*tmp_3_ret;
	char	*ret;
	int		i;
	char	buff[4096 + 1];

	i = 0;
	cwd = getcwd(buff, 4096);
	user_line = catch_user(my_env);
	cwd = ft_strnstr(cwd, user_line + 5, ft_strlen(cwd));
	while (cwd[i] != '/')
		i++;
	i++;
	//tmp_ret = ft_strdup(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
	tmp_ret = " \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ";
	tmp_2_ret = ft_strjoin(cwd + i, tmp_ret); 
	tmp_3_ret = "~/";//ft_strdup("~/");
	ret = ft_strjoin(tmp_3_ret, tmp_2_ret);
	//free(tmp_ret);
	//free(tmp_2_ret);
	return (ret);
}*/
