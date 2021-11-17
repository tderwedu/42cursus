FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install NGINX
RUN apt-get -yqq install nginx

#======================== 2. Install & Configure Nginx =========================

# Copy NGINX server block definition and create a symbolic link
# to "enable" our website
COPY ./conf/nginx.conf /etc/nginx/sites-available/default
RUN ln -s /etc/nginx/sites-available/default /etc/nginx/default

# Root directory of our website
RUN mkdir -p /var/www/website
WORKDIR /var/www/website

COPY ./tools/ .

#=========================== 3. Launching Container ===========================

# To allow a graceful NGINX shutdown
STOPSIGNAL SIGQUIT

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]

