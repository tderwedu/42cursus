# Open System Interconnection Model (OSI Model)

Developed by the ISO (International Organization for Standardization). Unlike the TCP/IP model the OSI model has never really been implemented. It is mostly used as a reference model for educational purposes. It is a conceptual framework for compartmentalize the different network processes.

>**1** - Physical  
>**2** - Data Link  
>**3** - Network  
>**4** - Transport  
>**5** - Session  
>**6** - Presentation  
>**7** - Application  

### `Application`
*FTP, web browsing, email, network management session (like SSH), ...*
### `Presentation`
Data formatting (data formats) and conversion (encryption, compression).
### `Session`
Application processes, request to remote services (Session Control Services - SCP)
### `Transport`
Responsible for data transport between two endpoints. Breaks data into segments (TCP) or datagram (UDP). Each flow of data has two port numbers. One is associated to the source and one the destination.  
*TCP, UDP, ...  *  
*Port number 80 for web server, ...*
### `Network`
Network addresses, IPs, and routing. After adding the IP addresses the pieces of data are called data packets.
### `Data Link`
Getting data between two devices which are not necessarily the two endpoints. Creates a logical link between devices which are not directly connected.  
*Ethernet Protocol*
### `Physical`
Encodes data into physical signals.

# TCP/IP

> *Original*  
>**1** - Link  
>**2** - Internet  
>**3** - Transport  
>**4** - Application  

> *Current*  
>**1** - Physical  
>**2** - Data Link  
>**3** - Network  
>**4** - Transport  
>**5** - Application  

TCP/IP allows using existing protocols like Ethernet if they already exist.

*Data Transfer Layers - [1-3]*  
*Application and Processes Layers - [4-5]*
- FTP : file transfer
- HTTP : web browsing
- SMTP/IMAP : email
- ...  
These applications create processes which listen on a particular port number. Transport protocol is either UDP or TCP.

### `Application`
Describes how applications use the network.
### `Transport`
TCP or UDP creates and maintains sessions between application processes on different hosts. They use port numbers to track sessions.
### `Network`
Converts data segment or datagram into packets by adding a header with the source and destination IPs.
### `Data Link`
Responsible of delivering traffic on a single network segment, LAN or subnet.  
If Ethernet protocol is used:  
1. If the 2 hosts are in the same subnet then delivery is achieved using MAC addresses.
2. If the 2 hosts are in different subnets routers are needed and the destination MAC is the router's one. The router looks at the destination IP and set the MAC address accordingly. The source MAC address becomes the one of the routers.
### `Physical`
Encodes data into physical signals.
