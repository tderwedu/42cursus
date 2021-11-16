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

# 1. Create a dedicated FTP user
# 3. Set its password
# 5. Add FTP user to /etc/vsftpd.chroot_list
RUN adduser --disabled-password --shell /bin/bash --gecos "" tderwedu && \
	echo "tderwedu:tderwedu" | chpasswd && \
	echo "tderwedu" >> /etc/vsftpd.chroot_list

#=========================== 3. Launching Container ===========================

# To allow a graceful vsFTPd shutdown
# STOPSIGNAL SIGQUIT

EXPOSE 20

CMD ["vsftpd"]

# help or ?	: list all available FTP commands.
# cd		: change directory on the remote machine.
# lcd		: change directory on the local machine.
# ls		: list the files and directories in the current remote directory.
# mkdir		: create a new directory within the current remote directory.
# pwd		: print the current working directory on the remote machine.
# delete	: remove a file in the current remote directory.
# rmdir		: remove a directory in the current remote directory.
# get		: copy one file from the remote to the local machine.
# mget		: copy multiple files from the remote to the local machine.
# put		: copy one file from the local to the remote machine.
# mput		: copy multiple files from the local to the remote machine
