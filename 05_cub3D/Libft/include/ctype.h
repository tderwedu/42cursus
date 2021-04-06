/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:17:30 by tderwedu          #+#    #+#             */
/*   Updated: 2021/02/10 13:33:09 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef CTYPE_H
# define CTYPE_H

# define FT_ISALNUM(c)	((t_ui)(c - '0') <= 9 || (t_ui)((c | 0x20) - 'a') < 26)
# define FT_ISALPHA(c)	((t_ui)((c | 0x20) - 'a') < 26U)
# define FT_ISASCII(c)	((t_ui)(c) < 128U)
# define FT_ISDIGIT(c)	((t_ui)(c - '0') < 10U)
# define FT_ISPRINT(c)	((t_ui)(c - ' ') < 95U)
# define FT_ISPRINT(c)	((t_ui)(c - ' ') < 95U)
# define FT_TOLOWER(c)	((t_ui)(c - 'A') < 26U ? (c | 0x20) : c)
# define FT_TOUPPER(c)	((t_ui)(c - 'a') < 26U ? (c ^ 0x20) : c)
# define FT_ISSPACE(c)	((t_ui)(c == ' ' || c - 9U < 4U))

#endif
