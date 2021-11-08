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
RUN apt-get -yqq install wget php-fpm php-mysql

# Root directory of our website
RUN mkdir -p /var/www/localhost/wordpress
WORKDIR /var/www/localhost

#======================= 2. Install & Configure WordPress ======================

RUN wget https://wordpress.org/latest.tar.gz && \
 	tar -xzvf latest.tar.gz && rm -rf latest.tar.gz
COPY ./wp-config.php /var/www/localhost/wordpress

RUN chown -R www-data:www-data .
RUN chmod -R 755 .

#=========================== 3. Launching Container ===========================

EXPOSE 3306
EXPOSE 9000

CMD ["php-fpm7.3"]
