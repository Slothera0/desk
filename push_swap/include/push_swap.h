/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:06:49 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/02 20:01:49 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pile
{
	int	*pile;
	int	len;
}	t_pile;

int		push_swap(char **argv, int len_a);
long	ft_atol(char *str);
t_pile	*init_pile(char	**str, int len);
int		is_sorted(int *pile, int len);
void	error(t_pile *pile_a, t_pile *pile_b);
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
void	create_chunck(t_pile *pile_a, t_pile *pile_b);
void	push_n_to_b(t_pile *pile_a, t_pile *pile_b, int n);
int		search_max_n(t_pile *pile, int n);
void	sort_tab(t_pile *pile_a, t_pile *pile_b);
void	push_n_sort(t_pile *pile_a, t_pile *pile_b);
int		dist_max(int *pile, int len);
void	sort_three(t_pile *pile_a, t_pile *pile_b);
void	push_one_to_b(t_pile *pile_a, t_pile *pile_b, int median_ten);
void	free_struct(t_pile *pile);
void	rotate_up_or_down(t_pile *pile_a, t_pile *pile_b);
int		check_arg(char *s);

#endif