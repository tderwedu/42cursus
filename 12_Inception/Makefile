# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 11:13:54 by tderwedu          #+#    #+#              #
#    Updated: 2021/11/19 10:27:21 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOMAIN_NAME	= tderwedu.42.fr

run:
		sudo mkdir -p /home/tderwedu/data/mariadb_vol
		sudo mkdir -p /home/tderwedu/data/wordpress_vol
		sudo mkdir -p /home/tderwedu/data/website_vol
		sudo mkdir -p /home/tderwedu/data/adminer_vol
		sudo mkdir -p /home/tderwedu/data/phpredisadmin_vol
		docker-compose -f srcs/docker-compose.yml --env-file ./srcs/.env up -d --build

logs:
		docker-compose -f srcs/docker-compose.yml logs

ps:
		docker-compose -f srcs/docker-compose.yml ps

stop:
		docker-compose -f srcs/docker-compose.yml stop

down:
		docker-compose -f srcs/docker-compose.yml down

prune:
		docker-compose -f srcs/docker-compose.yml down --volumes
		@printf "\e[34m Freeing "data" directory \e[0m \n"
		sudo rm -rf /home/tderwedu/data/*

clear:	prune
		printf "\e[34m Cleaning Docker \e[0m \n"
		@docker image prune -f
		@docker volume prune -f
		@docker network prune -f
		@printf "\e[34m Removing NGINX image \e[0m \n"
		@if	[ "$(shell docker image ls -q nginx)" ]; then \
			docker rmi $(shell docker image ls -q nginx); \
		fi
		@printf "\e[34m Removing MariaDB image \e[0m \n"
		@if	[ "$(shell docker image ls -q mariadb)" ]; then \
			docker rmi $(shell docker image ls -q mariadb); \
		fi
		@printf "\e[34m Removing WordPress image \e[0m \n"
		@if	[ "$(shell docker image ls -q wordpress)" ]; then \
			docker rmi $(shell docker image ls -q wordpress); \
		fi
		@printf "\e[34m Removing Redis image \e[0m \n"
		@if	[ "$(shell docker image ls -q redis)" ]; then \
			docker rmi $(shell docker image ls -q redis); \
		fi
		@printf "\e[34m Removing FTP image \e[0m \n"
		@if	[ "$(shell docker image ls -q ftp)" ]; then \
			docker rmi $(shell docker image ls -q ftp); \
		fi
		@printf "\e[34m Removing Website image \e[0m \n"
		@if	[ "$(shell docker image ls -q website)" ]; then \
			docker rmi $(shell docker image ls -q website); \
		fi
		@printf "\e[34m Removing Adminer image \e[0m \n"
		@if	[ "$(shell docker image ls -q adminer)" ]; then \
			docker rmi $(shell docker image ls -q adminer); \
		fi
		@printf "\e[34m Removing phpRedisAdmin image \e[0m \n"
		@if	[ "$(shell docker image ls -q phpredisadmin)" ]; then \
			docker rmi $(shell docker image ls -q phpredisadmin); \
		fi
		@printf "\e[34m Deleting `data` directory \e[0m \n"
		sudo rmdir /home/tderwedu/data
.phony:	run logs ps stop down prune clear
