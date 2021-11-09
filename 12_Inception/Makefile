# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 11:13:54 by tderwedu          #+#    #+#              #
#    Updated: 2021/11/09 18:22:54 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

run:
		sudo mkdir -p /home/tderwedu/data/mariadb_vol
		sudo mkdir -p /home/tderwedu/data/wordpress_vol
		docker-compose -f srcs/docker-compose.yml --env-file ./srcs/.env up -d --build 
		# docker-compose -f srcs/docker-compose.yml --env-file ./srcs/.env up

ps:
		docker-compose -f srcs/docker-compose.yml ps

stop:
		docker-compose -f srcs/docker-compose.yml stop

down:
		docker-compose -f srcs/docker-compose.yml down

prune:
		docker-compose -f srcs/docker-compose.yml down --volumes

.phony:	run ps stop down prune
