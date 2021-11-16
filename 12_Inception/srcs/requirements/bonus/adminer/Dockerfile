FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install PHP
RUN apt-get -yqq install php-fpm php-mysql

#======================= 2. Install & Configure Adminer  =======================

# Used to define the listening port (unix -> TCP/IP)
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
# Disable PID file creation & daemonization
COPY ./conf/php-fpm.conf /etc/php/7.3/fpm/

RUN mkdir -p /var/www/adminer
WORKDIR /var/www/adminer

COPY ./conf/adminer-4.8.1-en.php ./adminer.php

RUN chown -R www-data:www-data .
RUN chmod -R 755 .

#=========================== 3. Launching Container ===========================

# To allow a graceful PHP shutdown
STOPSIGNAL SIGUSR1

EXPOSE 9000

CMD ["php-fpm7.3", "-F"]

