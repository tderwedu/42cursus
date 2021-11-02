FROM	debian:buster

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
RUN apt-get -yqq install vim

# To install NGINX
RUN apt-get -yqq install nginx
RUN apt-get -yqq install openssl
