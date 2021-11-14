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
RUN mkdir -p /var/www/tderwedu.42.fr/wordpress
WORKDIR /var/www/tderwedu.42.fr

#======================= 2. Install & Configure WordPress ======================

RUN wget https://wordpress.org/latest.tar.gz && \
 	tar -xzvf latest.tar.gz && rm -rf latest.tar.gz
# Used to info about wordpress_db
COPY ./conf/wp-config.php ./wordpress/
# Used to define the listening port (unix -> TCP/IP)
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
# Disable PID file creation & deamonization
COPY ./conf/php-fpm.conf /etc/php/7.3/fpm/

RUN chown -R www-data:www-data .
RUN chmod -R 755 .

#=========================== 3. Launching Container ===========================

# To allow a graceful PHP-PFM shutdown
STOPSIGNAL SIGUSR1

EXPOSE 3306
EXPOSE 9000

# --nodaemonize, -F:
# Force to stay in foreground and ignore daemonize option from configuration file. 
CMD ["php-fpm7.3", "-F"]
