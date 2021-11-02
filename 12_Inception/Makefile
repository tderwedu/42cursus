# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 11:13:54 by tderwedu          #+#    #+#              #
#    Updated: 2021/11/02 11:14:48 by tderwedu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TODO: adapt to Inception

To bluid the 'ft_server' container
build:
		sudo docker build -t ft_server .

To run the 'ft_server' container
run:
		sudo docker run -it --rm --name ft_server --init -p 80:80 -p 443:443 ft_server

To clean up temporary files
prune:
		sudo docker system prune
		
.phony:	build run prune
