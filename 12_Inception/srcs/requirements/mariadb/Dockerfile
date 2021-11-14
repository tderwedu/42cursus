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
ARG MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}

# 0. Launch MySQL
# 1. Create a new database
# 2. Create a new user
# 3. Grant the admin All privileges on the database
# 		(replace '%' by '${WP_HOST}.${NET_NAME}' to allow only from wordpress container)
# 4. Reload privileges tables
RUN service mysql start \
	&& mysql -u root --skip-password -e "CREATE DATABASE ${MYSQL_DATABASE};" \
	&& mysql -u root --skip-password -e "CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';" \
	&& mysql -u root --skip-password -e "GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';" \
	&& mysql -u root --skip-password -e "FLUSH PRIVILEGES;"

# 1. Copy the MySQL dump file
# 	-> `mysqldump --databases wordpress_db > wordpress_db.sql`
# 2. Launch MySQL and load pre-made Wordpress database
COPY ./tools/wordpress_db.sql ./wordpress_db.sql
RUN service mysql start && mysql ${MYSQL_DATABASE} < wordpress_db.sql

# Automating 'mysql_secure_installation'
# 0. Launch MySQL
# 1. Make root user only accessible from localhost
# 2. Remove anonymous-user accounts. 
# 3. Remove the `test` database
# 4. Use a PASSWORD for root user instead of the UNIX socket
# 5. Set root a PASSWORD
# 6. Reload privileges tables
RUN service mysql start \
	&& mysql -u root --skip-password -e "DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1')" \
	&& mysql -u root --skip-password -e "DELETE FROM mysql.user WHERE User=''" \
	&& mysql -u root --skip-password -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\_%'" \
	&& mysql -u root --skip-password -e "UPDATE mysql.user SET plugin='mysql_native_password' WHERE User='root'" \
	&& mysql -u root --skip-password -e "UPDATE mysql.user SET Password=PASSWORD('$MYSQL_ROOT_PASSWORD') WHERE User='root'" \
	&& mysql -u root --skip-password -e "FLUSH PRIVILEGES"

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

#=========================== 4. Launching Container ===========================

# To allow a graceful MariaDB shutdown (not possible without a workaround)
# STOPSIGNAL SIGTERM

EXPOSE 3306

CMD ["mysqld"]
