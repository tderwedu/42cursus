FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install MariaDB (fork of MySQL)
RUN apt-get -yqq install mariadb-server

#======================= 2. Install & Configure MariaDB =======================

# Defines variables passed at build-time
ARG MYSQL_DATABASE=${MYSQL_DATABASE}
ARG MYSQL_USER=${MYSQL_USER}
ARG MYSQL_PASSWORD=${MYSQL_PASSWORD}
ARG MYSQL_ADMIN=${MYSQL_ADMIN}
ARG MYSQL_ADMIN_PASSWORD=${MYSQL_ADMIN_PASSWORD}
ARG WP_HOST=${WP_HOST}
ARG NET_NAME=${NET_NAME}

# 0. Launch MySQL
# 1. Create a new database
# 2. Create a new user
# 3. Grant the user All privileges on the database.
# 4. Create a new user (admin)
# 5. Grant the admin All privileges on the database and 
# 7. Reload privileges tables
# 6. (='console' auth plugin = Default) Disable remote access to ROOT and use UNIX socket for authentification
RUN service mysql start \
	&& mysql -u root --skip-password -e "CREATE DATABASE ${MYSQL_DATABASE};" \
	&& mysql -u root --skip-password -e "CREATE USER '${MYSQL_USER}'@'${WP_HOST}.${NET_NAME}' IDENTIFIED BY '${MYSQL_PASSWORD}';" \
	&& mysql -u root --skip-password -e "GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'${WP_HOST}.${NET_NAME}';" \
	&& mysql -u root --skip-password -e "CREATE USER '${MYSQL_ADMIN}'@'${WP_HOST}.${NET_NAME}' IDENTIFIED BY '${MYSQL_ADMIN_PASSWORD}';" \
	&& mysql -u root --skip-password -e "GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_ADMIN}'@'${WP_HOST}.${NET_NAME}' WITH GRANT OPTION;" \
	&& mysql -u root --skip-password -e "FLUSH PRIVILEGES;" 
# && mysql -u root --skip-password -e "UPDATE mysql.user SET plugin='' WHERE user='root' AND host = 'localhost';"

COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/

#=========================== 4. Launching Container ===========================

# To allow a graceful MariaDB shutdown (not possible without a workaround)
# STOPSIGNAL SIGTERM

EXPOSE 3306

CMD ["mysqld"]
