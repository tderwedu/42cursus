FROM	debian:buster

#=========================== 1. Intall Dependencies ===========================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install phpMyAdmin
#	php-fpm   : stands for "PHP FastCGI Process Manager"
#	php-mysql : allows PHP to communicate with MySQL
#	wget      : used to install wordpress
RUN apt-get -yqq install wget php-fpm php-mysql mariadb-client

# Root directory of our website
RUN mkdir -p /var/www/localhost/wordpress
WORKDIR /var/www/localhost

#======================= 2. Install & Configure WordPress ======================

RUN wget https://wordpress.org/latest.tar.gz && \
 	tar -xzvf latest.tar.gz && rm -rf latest.tar.gz
# Used to info about wordpress_db
COPY ./wp-config.php ./wordpress/
# Used to define the listening port (unix -> TCP/IP)
COPY ./www.conf /etc/php/7.3/fpm/pool.d/
# Disable PID file creation & deamonization
COPY ./php-fpm.conf /etc/php/7.3/fpm/

RUN chown -R www-data:www-data .
RUN chmod -R 755 .

#=========================== 3. Launching Container ===========================

STOPSIGNAL SIGUSR1

EXPOSE 3306
EXPOSE 9000

# --nodaemonize, -F:
# Force to stay in foreground and ignore daemonize option from configuration file. 
CMD ["php-fpm7.3", "-F"]
