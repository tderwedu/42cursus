# Open System Interconnection Model (OSI Model)

Developed by the ISO (International Organization for Standardization). Unlike the TCP/IP model the OSI model has never really been implemented. It is mostly used as a reference model for educational purposes. It is a conceptual framework for compartmentalize the different network processes.

>**7** - Application  
>**6** - Presentation  
>**5** - Session  
>**4** - Transport  
>**3** - Network  
>**2** - Data Link  
>**1** - Physical  

### `Application`
FTP, web browsing, email, network management session (like SSH), ...
### `Presentation`
Data formatting (data formats) and conversion (encryption, compression).
### `Session`
Application processes, request to remote services (Session Control Services - SCP)
### `Transport`
Responsible for data transport between two endpoints. Breaks data into segments (TCP) or datagram (UDP). Each flow of data has two port numbers. One is associated to the source and one the destination.  
TCP, UDP, ...  
Port number *80* for web server, ...
### `Network`
Network (IP) addresses and routing. After adding the IP addresses the pieces of data are called data segments.
### `Data Link`
Getting data between two devices which are not necessarily the two endpoints. Creates a logical link between devices which are not directly connected.  
Ethernet.
### `Physical`
Encodes data into physical signals.

# TCP/IP

> *Original*  
>**4** - Application  
>**3** - Transport  
>**2** - Internet  
>**1** - Link  

> *Current*  
>**5** - Application  
>**4** - Transport  
>**3** - Network  
>**2** - Data Link  
>**1** - Physical  

TCP/IP allows using existing protocols like Ethernet if they already exist.

*Data Transfer Layers - [1-3]*  
*Application and Processes Layers - [4-5]*
- FTP : file transfer
- HTTP : web browsing
- SMTP/IMAP : email
- ...  
These applications create processes which listen on a particular port number. The processes are either UDP or TCP.

### `Application`
This layer  describes how applications use the network.
### `Transport`**`
TCP or UDP creates and maintains conversations between application processes on different hosts. They use port numbers to track sessions.
### `Network`
Converts data segment or datagram into packets by adding a header with the source and destination IPs.
### `Data Link`
Responsible of delivering traffic on a single network segment, LAN or subnet.  
If Ethernet protocol is used:  
1. If the 2 hosts are in the same subnet then delivery is achieved using MAC. addresses.
2. If the 2 hosts are in different subnets routers are needed and the destination (dst) MAC. is the router. The router looks at the dst IP and set the MAC. address accordingly. The source (src) MAC. address becomes the one of the routers.
### `Physical`
Encodes data into physical signals.
