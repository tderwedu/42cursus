FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install Redis
RUN apt-get -yqq install redis-server php-redis

#======================== 2. Install & Configure Redis =========================

COPY ./conf/redis.conf /etc/redis/redis.conf

#=========================== 3. Launching Container ===========================

# To allow a graceful Redis shutdown (SIGTERM)
# STOPSIGNAL SIGQUIT

EXPOSE 6379

CMD ["redis-server", "--protected-mode no"]
