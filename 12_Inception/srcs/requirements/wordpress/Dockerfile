FROM	debian:buster

#=========================== 1. Intall Dependencies ===========================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps
# To install WordPress
RUN apt-get -yqq install wget

# To install phpMyAdmin
#	php-fpm   : stands for "PHP fastCGI process manager"
#	php-mysql : allows PHP to communicate with MySQL
RUN apt install -yqq php-fpm php-mysql

# Root directory of our website
RUN mkdir -p /var/www/localhost/wordpress
WORKDIR /var/www/localhost

#======================= 2. Install & Configure WordPress ======================

RUN wget https://wordpress.org/latest.tar.gz && \
 	tar -xzvf latest.tar.gz && rm -rf latest.tar.gz
COPY ./srcs/wp-config.php /var/www/localhost/wordpress

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

COPY srcs/start.sh ./

ENTRYPOINT ["bash","start.sh"]
