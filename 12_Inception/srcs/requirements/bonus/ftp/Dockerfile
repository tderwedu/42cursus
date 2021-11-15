FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install Redis
RUN apt-get -yqq install openssl vsftpd

#======================== 2. Install & Configure vsftpd  =========================

# Compying with 'secure_chroot_dir'
RUN mkdir -p  var/run/vsftpd/empty

COPY ./conf/vsftpd.conf /etc/vsftpd.conf

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
				-keyout /etc/ssl/private/vsftpd-selfsigned.key \
				-out /etc/ssl/certs/vsftpd-selfsigned.crt

# 2. Create a the home directory
# 1. Create a dedicated FTP user
# 3. Set its ownership (due to the way vsftpd secures the directory, it must not be writable by the user.)
# 4. Remove write permissions
# 5. Add FTP user to /etc/vsftpd.userlist
# adduser --quiet --disabled-password --shell /bin/bash --home /home/tderwedu --gecos "" tderwedu
RUN adduser --quiet --shell /bin/bash --home /home/tderwedu --gecos "" tderwedu && \
	echo "tderwedu:tderwedu" | chpasswd \
	chown nobody:nogroup /home/tderwedu && \
	chmod a-w /home/tderwedu && \
	echo "tderwedu" >> /etc/vsftpd.userlist

#=========================== 3. Launching Container ===========================

# To allow a graceful vsFTPd shutdown
# STOPSIGNAL SIGQUIT

EXPOSE 20

CMD ["vsftpd"]
