/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/17 19:39:23 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_builtin(char	*input)
{
	char	*cwd;
	char	**split_input;

	cwd = NULL;
	cwd = getcwd(cwd, 4096);
	split_input = ft_split(input, ' ');
	closedir((DIR *)cwd);
	if (chdir(split_input[1]) == -1)
		return ;
	// FREE SPLIT_INPUT
}

