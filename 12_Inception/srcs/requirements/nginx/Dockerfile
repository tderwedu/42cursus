FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install NGINX
RUN apt-get -yqq install nginx openssl mariadb-client

#======================== 2. Install & Configure Nginx =========================

# Copy NGINX server block definition and create a symbolic link
# to "enable" our website
COPY ./conf/nginx.conf /etc/nginx/sites-available
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled

# Root directory of our website
RUN mkdir -p /var/www/tderwedu.42.fr
WORKDIR /var/www/tderwedu.42.fr

# Bonus services directories
RUN mkdir -p /var/www/adminer
RUN mkdir -p /var/www/website
RUN mkdir -p /var/www/phpredisadmin

#================================ 3. SSL protocol ==============================

# -newkey : creates a new private key with the certificate
# 	rsa:2048 : RSA encryption with a 2048 bits key
# -x509   : specifies self signed certificate
# -nodes  : creates a key without a passphrase.
# -days   : validity (in days) of the certificate
# -subj   : to use a string to specify subject information
# -keyout : specifies where to save the key
# -out    : specifies where to save the certificate
RUN openssl req -newkey rsa:2048 -x509 -days 31 -nodes \
				-subj "/C=BE/ST=Namur/L=Namur/O=42Network/OU=s19/CN=tderwedu.42.fr"\
				-keyout /etc/ssl/private/nginx-selfsigned.key \
				-out /etc/ssl/certs/nginx-selfsigned.crt

#=========================== 4. Launching Container ===========================

# To allow a graceful NGINX shutdown
STOPSIGNAL SIGQUIT

EXPOSE 443
EXPOSE 9000

CMD ["nginx", "-g", "daemon off;"]

