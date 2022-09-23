/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_errors_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:19:10 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/23 19:48:20 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_argumentcount(void)
{
	write(2, "Too few arguments.\n", 19);
	exit(EXIT_FAILURE);
}

void	error_here_doc_tempfile(t_envl *e)
{
	perror("here_doc_tempfile");
	cleanup(e);
	exit(EXIT_FAILURE);
}

void	error_waitpid(t_envl *e)
{
	perror("waitpid");
	cleanup(e);
	exit(EXIT_FAILURE);
}

void	error_env(t_envl *e)
{
	perror("env");
	cleanup(e);
	exit(EXIT_FAILURE);
}
