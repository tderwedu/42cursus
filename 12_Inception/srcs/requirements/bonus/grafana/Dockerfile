FROM	debian:buster

#=========================== 1. Intall Dependencies ============================

# Update Software Packages
RUN apt-get -qq update && apt-get -yqq upgrade
# To install ps
RUN apt-get -yqq install procps

# To install Grafana
RUN apt-get -yqq install gpg wget

#======================== 2. Install & Configure Grafana  =========================

# Add InfluxDB & Telegraf gpg keys which allows to install signed packages.
RUN wget -qO- https://repos.influxdata.com/influxdb.key | apt-key add -
RUN echo "deb https://repos.influxdata.com/debian buster stable" |  tee -a /etc/apt/sources.list.d/influxdb.list

# Add InfluxDB gpg key which allows to install signed packages.
RUN wget -qO - https://packages.grafana.com/gpg.key | sudo apt-key add -
RUN echo "deb https://packages.grafana.com/oss/deb stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list

# Install Telegraf, InfluxDB and Grafana
RUN apt-get update && sudo apt-get install -yqq telegraf influxdb2 grafana

#=========================== 3. Launching Container ===========================

# To allow a graceful vsFTPd shutdown
# STOPSIGNAL SIGQUIT

EXPOSE 3000

# CMD ["vsftpd"]

