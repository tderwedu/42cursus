FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install PHP
RUN apt-get -yqq install php php-fpm php-redis php-mbstring

#==================== 2. Install & Configure phpRedisAdmin  ====================

# Needed to allow PHP-FPM error log
RUN touch /var/log/fpm-php.www.log
RUN chown www-data:www-data /var/log/fpm-php.www.log

# Used to define the listening port (unix -> TCP/IP)
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
# Disable PID file creation & daemonization
COPY ./conf/php-fpm.conf /etc/php/7.3/fpm/

RUN mkdir -p /var/www/phpredisadmin/
WORKDIR /var/www/phpredisadmin/

COPY ./phpredisadmin/ .

RUN chown -R www-data:www-data .
RUN chmod -R 755 .

#=========================== 3. Launching Container ===========================

# To allow a graceful PHP shutdown
STOPSIGNAL SIGUSR1

EXPOSE 80

# CMD ["php-fpm7.3", "-F"]
CMD [ "php", "-S", "0.0.0.0:80"]

