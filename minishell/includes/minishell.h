/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:12:00 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 16:41:32 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>

# define DQUOTE 34
# define SQUOTE 39
# define LESSER '<'
# define GREATER '>'
# define PIPE '|'

# define MALLOC_ERR "minishell: malloc"

static bool	g_sig = false;

typedef enum e_token
{
	LESS,
	LESS_LESS,
	GREAT,
	GREAT_GREAT,
	WORD,
	T_PIPE,
	OUTPUT,
	APPEND,
	INPUT,
	HEREDOC,
	EMPTY,
	AMBIGUOUS,
}	t_token;

typedef struct s_tokens
{
	t_token			token;
	char			*str;
	struct s_tokens	*next;
	struct s_tokens	*previous;
}	t_tokens;

typedef struct s_cmds
{
	char			**args;
	char			*path;
	int				infile;
	int				outfile;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_minishell
{
	char		**envp;
	t_cmds		*cmds;
	bool		pipe;
	ssize_t		index;
	uint8_t		exit_status;
}	t_minishell;

char		**init_envp(char **envp);
void		init_sig(t_minishell *minishell);
void		sig_status(t_minishell *minishell);

int			parsing(char *line, t_minishell *minishell);

void		init_variables(int *args, size_t *delim, size_t *i,
				t_minishell *minishell);
char		*no_pipe_cmd(char *line, size_t *i, size_t start,
				t_minishell *minishell);
char		*split_arg(char *line, size_t *delim, size_t i,
				t_minishell *minishell);
char		**init_split(char *line, int args, size_t *i,
				t_minishell *minishell);
char		**init_pipes_split(char *line, int args, size_t *i,
				t_minishell *minishell);
char		**pipes_split(char *line, t_minishell *minishell);

t_tokens	*tokens_checker(char **split, t_minishell *minishell);
t_tokens	*create_tokens_node(t_tokens **tokens, t_token token,
				t_minishell *minishell);
bool		check_before(t_tokens *tokens, t_minishell *minishell);
int			token_getter(char *split, size_t *j, t_tokens **tokens,
				t_minishell *minishell);
int			tokens_checker_utils(char **split, size_t i, t_tokens **tokens,
				t_minishell *minishell);
int			get_redirections(t_tokens **tokens, t_minishell *minishell);
void		clean_tokens(t_tokens **tokens);
void		*free_tokens(t_tokens *tokens);
void		ambiguous_redirect(t_tokens **tokens, char *non_expand,
				t_minishell *minishell);

t_cmds		*create_cmds(t_tokens **tokens, t_minishell *minishell);
t_cmds		*create_node(t_minishell *minishell);
int			cmds_error(t_cmds **cmds);
int			open_error(char *prefix, t_minishell *minishell);
int			skip_pipe(t_tokens **tokens, t_cmds **cmds);
int			heredoc(t_cmds **cmds, t_tokens **tokens, t_minishell *minishell);
char		*delimiter_quote(char *str, t_minishell *minishell);
int			redirs_handler(t_cmds **start, t_cmds **cmds, t_tokens **tokens,
				t_minishell *minishell);

char		*pre_expand(char *str, t_minishell *minishell);
char		*expander(char *str, t_minishell *minishell, bool heredoc);
char		**pro_expand(char **args, size_t *i, t_minishell *minishell);
char		*replace_var(char *str, size_t *i, size_t var_len, char **infos);
char		*quotes_remover(char *str, size_t first, size_t *last,
				t_minishell *minishell);
char		*var_remover(char *str, size_t start, size_t len);
char		*exit_var(char *str, size_t *i, t_minishell *minishell);
char		*find_var(char *str, size_t *i, t_minishell *minishell,
				bool in_quotes);
char		**envp_split(char *line, t_minishell *minishell);
char		*get_var(char *str, size_t *i, size_t len, t_minishell *minishell);
char		**get_infos(char *str, char *line, t_minishell *minishell);
size_t		get_len(char *str, size_t *i, size_t *j);
bool		check_var(char *temp, char **infos);

bool		ft_isspace(char c);
bool		is_space(char c);
bool		is_token(char c);
int			quote_handler(const char *str, size_t *i);

void		free_ptr_tab(char **tab);

int			parse_error(char *msg, t_minishell *minishell, int status);
int			ft_perror(char *prefix, t_minishell *minishell, int status);

size_t		count_args(t_tokens *tokens);

int			input(t_cmds **cmds, t_tokens *tokens, t_minishell *minishell);
int			output(t_cmds **cmds, t_tokens *tokens, t_minishell *minishell);
int			append(t_cmds **cmds, t_tokens *tokens, t_minishell *minishell);
int			heredoc_redir(t_cmds **cmds, t_tokens **tokens,
				t_minishell *minishell);

int			exec(t_minishell *data);
int			error(char *str);
int			env(char **envp, int outfile);
int			pwd(int outfile);
int			echo(t_cmds *cmd);
int			cd(char ***env, char *path);
int			export(char ***env, char **define);
int			unset(char ***env, char **var);
int			exit_cmd(char **status, t_minishell *data);
void		free_data(t_minishell *data);
int			is_builtin(char *cmd);
int			exec_builtins(t_minishell *data, t_cmds *cmd, char **envp);
char		*find_path(char **path, char *cmd);
int			error_msg(char *cmd, char *msg);
void		free_cmd(t_cmds *cmd);

#endif
