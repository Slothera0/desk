/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:06:49 by arvoyer           #+#    #+#             */
/*   Updated: 2024/01/31 08:03:36 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		push_swap(char **argv, int len_a);
long	ft_atol(char *str);
int		*init_pile(char	**str, int len);
int		is_sorted(int *pile, int len);
int		error(void);
int		is_double(int *pile, int len);
void	push(int *pile_a, int *len_a, int *pile_b, int *len_b);
void	reverse_rotate(int *pile, int len);
void	rotate(int *pile, int len);
void	swap(int *pile, int len);
int		ft_strlen_p(char **str);
char	**ft_split(char *s);
char	*ft_strdup_stop(char *s);
int		tablen(const char *str);
char	**free_array(char **tab, int max);
int		max(int *pile, int len);
int		min(int *pile, int len);
void	create_chunck(int *pile_a, int *len_a, int *pile_b, int *len_b);
void	push_n(int *pile_a, int *len_a, int *pile_b, int *len_b, int n);
int		search_max_n(int *pile, int len, int n);
void	sort_tab(int *pile_a, int *len_a, int *pile_b, int *len_b);
void	push_n_sort(int *pile_a, int *len_a, int *pile_b, int *len_b);
int		dist_max(int *pile, int len);
void	sort_three(int *pile, int len);

#endif