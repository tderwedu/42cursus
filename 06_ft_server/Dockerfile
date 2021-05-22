FROM debian:buster


#==================================  1. Intall Dependencies

# Update Software Packages
RUN apt-get -qq update
RUN apt-get -yqq upgrade
RUN apt-get -yqq install tree vim

RUN apt-get -yqq install nginx
RUN apt-get -yqq install openssl
#RUN apt-get -y  install wget

#==================================  2. Install & Configure Nginx
# Root directory of our website
RUN mkdir /var/www/localhost

# Copy NGINX server block definition and create a symbolic link
# to "enable" our website
COPY srcs/localhost /etc/nginx/sites-available
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled

# Setting the working directory as /var/www/localhost
WORKDIR /var/www/localhost

#==================================  3. SSL protocol and autoindex

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
