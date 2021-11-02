# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 11:13:54 by tderwedu          #+#    #+#              #
#    Updated: 2021/11/02 17:21:09 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

run:
		docker-compose -f srcs/docker-compose.yml --env-file ./srcs/.env up
		# docker-compose -f srcs/docker-compose.yml --env-file ./srcs/.env up

list:
		docker-compose ps

stop:
		docker-compose stop

prune:
		docker-compose down --volumes

.phony:	run list stop prune
