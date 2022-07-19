/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/19 20:22:30 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	g_data;

static void	void_args(int ac, char **av);
static void	main_loop(void);

int	main(int ac, char **av, char **envp)
{
	void_args(ac, av);
	init_out_loop(envp);
	main_loop();
	free_split(g_data.my_env);
	return (0);
}

static void	void_args(int ac, char **av)
{
	(void)ac;
	(void)av;
}

static void	main_loop(void)
{
	while (1)
	{
		set_error_env();
		init_sig();
		g_data.input = readline("\\\\ minishell \\\\ ");
		ctrld_handler(g_data.input);
		if (!g_data.input[0] || only_white_space() == 1)
			continue ;
		init_in_loop();
		rotate_tokens();
		if (quotes_not_close() == 1)
		{
			ft_putstr_fd("quotes error\n", 0);
			free_loop();
			continue ;
		}
		builtin_or_not();
		if (exit_builtin() == 1)
			continue ;
		if (is_cd() || is_export() || is_unset())
		{
			free_loop();
			continue ;
		}
		free_loop();
		set_error_env();
	}
}

/*
MY_PROMPT>>
爪ĭກĭ-ᏕਮҾᏝᏝ
∩∩┌(ಠ_ಠ)┌∩∩
ጠĭηĭᏕħεłł
*/
