/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:20:42 by wmardin           #+#    #+#             */
/*   Updated: 2022/09/24 11:53:22 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include "libft/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <string.h>

typedef struct envelope
{
	int		argc;
	char	**argv;
	char	**env;
	char	***input;
	char	**env_paths;
	char	**cmdpaths;
	int		**pipe;
	int		here_doc;
	char	*tempfile;
	int		n;
	int		exitstatus;
	pid_t	pid;
	int		infile;
	int		outfile;
}	t_envl;

//00_main.c
//int		main(int argc, char **argv, char **env);

//01_children_1.c
void	firstchild(t_envl *e, int i);
void	middlechild(t_envl *e, int i);
void	lastchild(t_envl *e, int i);
void	wait_child(t_envl *e);

//02_here_doc.c
void	here_doc(t_envl *e);

//06_setup_1.c
void	setup(t_envl *e, int argc, char **argv, char **env);
void	split_input_cmds(t_envl *e);
void	split_env_path(t_envl *e);
void	get_cmdpaths(t_envl *e);
int		get_singlepath(t_envl *e, int i);

//06_setup_2.c
void	allocate_pipes(t_envl *e);
void	open_files(t_envl *e);

//07_shutdown.c
void	cleanup(t_envl *e);
void	free_mem(t_envl *e);
void	free3d_char(char ***array);
void	free2d_char(char **array);
void	free2d_int(int **array, int size);

//08_errors_1.c
void	error_pipe(t_envl *e);
void	error_fork(t_envl *e);
void	error_path(t_envl *e);
void	error_infile(t_envl *e);
void	error_outfile(t_envl *e);
void	error_env(t_envl *e);

//08_errors_2.c
void	error_argumentcount(void);
void	error_here_doc_tempfile(t_envl *e);
void	error_waitpid(t_envl *e);

//09_helperfunctions.c
void	print3d(char ***array);
void	print2d(char **array);
void	printpipefd(int	*pipe, int i);

#endif