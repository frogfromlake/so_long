/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:33:12 by fquist            #+#    #+#             */
/*   Updated: 2021/11/29 22:59:04 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/modules/ft_printf.h"

void	ft_eval_input(t_info *info)
{
	int					number;
	static t_formatter	*functions_array[E_LENGTH] =
	{
	[e_char] = ft_solve_char,
	[e_string] = ft_solve_string,
	[e_pointer] = ft_solve_pointer,
	[e_decimal_int] = ft_solve_dec_int,
	[e_u_dec_int] = ft_solve_uint,
	[e_u_hex_int] = ft_solve_hex,
	[e_percentage] = ft_solve_percent
	};

	ft_evaluate_flag(info);
	ft_evaluate_width(info);
	ft_evaluate_precision(info);
	number = ft_select_format_specifier(info);
	functions_array[number](info);
}
