#!/bin/sh

service nginx start
service mysql start
service php7.3-fpm start

#======================== Configure WordPress database =========================

# 1. Create a database named "wordpress"
mysql -u root --skip-password -e "CREATE DATABASE wordpress;"
# 2. Making a root user with full privileges on the "wordpress" database.
mysql -u root --skip-password -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"
# 3. Flush privileges = reload privileges tables
mysql -u root --skip-password -e "FLUSH PRIVILEGES;"
# 4. Check the UNIX socker instead of using a password
mysql -u root --skip-password -e "UPDATE mysql.user SET plugin='' WHERE user='root';"

bash
