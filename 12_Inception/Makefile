# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 11:13:54 by tderwedu          #+#    #+#              #
#    Updated: 2021/11/12 19:57:01 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOMAIN_NAME	= tderwedu.42.fr

run:
		sudo mkdir -p /home/tderwedu/data/mariadb_vol
		sudo mkdir -p /home/tderwedu/data/wordpress_vol
		docker-compose -f srcs/docker-compose.yml --env-file ./srcs/.env up -d --build

ps:
		docker-compose -f srcs/docker-compose.yml ps

stop:
		docker-compose -f srcs/docker-compose.yml stop

down:
		docker-compose -f srcs/docker-compose.yml down

prune:
		docker-compose -f srcs/docker-compose.yml down --volumes
		sudo rm -rf /home/tderwedu/data/*

clear:	prune
		@docker image prune -f
		@docker volume prune -f
		@docker network prune -f
		@if	[ "$(docker image ls -q nginx)" ]; then \
			docker rmi $(docker image ls -q nginx); \
		fi
		@if	[ "$(docker image ls -q mariadb)" ]; then \
			docker rmi $(docker image ls -q nginx); \
		fi
		@if	[ "$(docker image ls -q wordpress)" ]; then \
			docker rmi $(docker image ls -q nginx); \
		fi
.phony:	run ps stop down prune clear
