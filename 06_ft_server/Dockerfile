FROM debian:buster


#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update
RUN apt-get -yqq upgrade
RUN apt-get -yqq install vim

# To install NGINX
RUN apt-get -yqq install nginx
RUN apt-get -yqq install openssl

# To install MariaDB (fork of MySQL)
RUN apt-get -yqq install mariadb-server

# To install phpMyAdmin
#	php-fpm   : stands for "PHP fastCGI process manager"
#	php-mysql : allows PHP to communicate with MySQL
RUN apt-get -yqq install php-fpm php-mysql php-mbstring php-zip php-gd php-xml php-pear php-gettext php-cgi 

# To install WordPress
RUN apt-get -yqq install wget

#======================== 2. Install & Configure Nginx =========================

# Copy NGINX server block definition and create a symbolic link
# to "enable" our website
COPY srcs/localhost /etc/nginx/sites-available
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled

# Root directory of our website
RUN mkdir -p /var/www/localhost/wordpress
WORKDIR /var/www/localhost

#================================ 3. SSL protocol ==============================

# -newkey : creates a new private key with the certificate
# 	rsa:2048 : RSA encryption with a 2048 bits key
# -x509   : speicifies self signed certificate
# -nodes  : creates a key without a passphrase.
# -days   : validity (in days) of the certificate
# -subj   : to use a string to specify subject information
# -keyout : specifies where to save the key
# -out    : specifies where to save the certificate
RUN openssl req -newkey rsa:2048 -x509 -days 31 -nodes \
            	-subj "/C=BE/ST=Namur/L=Namur/O=42Network/OU=s19/CN=localhost"\
            	-keyout /etc/ssl/private/nginx-selfsigned.key \
            	-out /etc/ssl/certs/nginx-selfsigned.crt

#RUN openssl dhparam -out /etc/nginx/dhparam.pem 4096

#====================== 4. Install & Configure phpMyAdmin =======================

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz \
	&& tar -xf phpMyAdmin-5.1.0-english.tar.gz && rm -rf phpMyAdmin-5.1.0-english.tar.gz \
	&& mv phpMyAdmin-5.1.0-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

#======================= 5. Install & Configure WordPress =======================

RUN wget https://wordpress.org/latest.tar.gz && \
 	tar -xzvf latest.tar.gz && rm -rf latest.tar.gz
COPY ./srcs/wp-config.php /var/www/localhost/wordpress

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

COPY srcs/start.sh ./

ENTRYPOINT ["bash","start.sh"]
