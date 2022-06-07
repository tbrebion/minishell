/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sig_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:19:17 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/07 16:20:45 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_sig(void)
{
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, &sigquit_handler);
}

void	reinit_sig(void)
{
	signal(SIGINT, &interrupt_cmd);
	signal(SIGQUIT, &sigquit_handler);
}

void	ignore_sig(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
