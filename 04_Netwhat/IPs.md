# IP addresses

IP addresses consist of two groups of bits: the most significant bits are the network prefix, which identifies a whole network or subnet, and the least significant set forms the host identifier, which specifies a particular interface on that network.

**functions**
- network identification
- host identification

**IP Address = [ network ] + [ host ]**  

**Versions**
- **IPv4** (32 bits)  
	This is the first version of IP. It was deployed for production in the ARPANET in 1983.  Is still the most used IP version today. 
- **IPv6** (128 bits)  
	It is the most recent version of the Internet Protocol. It was initiated in early 1994.

> Special purpose addresses :  
> Network IP : first address of a subnet (all host bits set to 0).  
> Broadcast IP : last address of a subnet (all host bits set to 1).  
> The Broadcast IP : 255.255.255.255

This last IP is used when a device is starting up and has not an IP address nor information about the local subnet. This IP allow to send traffic everywhere.

### Assigning Addresses
1. Static addresses (routers and some server)
2. Dynamic addresses with a Dynamic Host Configuration Protocol (DHCP).
3. Automatic Private IP addressing (unusual).

## Evolutions

1. One byte for the network and 3 bytes for the host,
2. IP addresses classes,
3. Classless IP addresses and subnets (CIDR).

## IP addresses classes

1. The class is identified by looking at the first few bits.
2. Knowing the class, we can separate the part for the network from the part for the host.

 > | Class| Starting bits  | IP addresses Range              | CIDR |  Supports                             |
 > | :--: | :------------: | :-----------------------------: | :--: | :-----------------------------------: |
 > |   A  | 0              |  0.0.0.1    to  127.255.255.254 |  /8  | Networks: 127 - Hosts: 16 777 214     |
 > |   B  | 10             |  128.0.0.1  to  191.255.255.254 |  /16 | Networks: 16 384 - Hosts: 65 534      |
 > |   C  | 110            |  192.0.0.1  to  223.255.255.254 |  /24 | Networks: 2 097 152 - Hosts: 254      |
 > |   D  | 1110           |  224.0.0.1  to  239.255.255.254 |      | Reserved for multicast                |
 > |   E  | 1111           |  240.0.0.1  to  255.255.255.254 |      | Reserved for IANA (future use or R&D) |  
  
- Unicast traffic : send traffic to only one device.
- Multicast traffic : send traffic to multiple devices
- Broadcast traffic : send traffic to every device

The advantage of this system is that the network prefix could be determined for any IP address without any further information. The disadvantage is because only three sizes are available, networks were usually too big or too small for most organizations to use.

### Multicast Traffic
Streaming servers send traffic to a multicast IP and other hosts looks for traffic send to that IP. Routers forward multicast traffic.

### Internet Assigned Numbers Authority (IANA)
1. The Internet Assigned Numbers Authority assign IP addresses to Regional Internet Registries (RIRs).
2. RIRs assign space to Internet Service Providers (ISPs) and large customers.
3. ISPs gives IPs to their customers.

## Classless Networks and Subnets

Classless Inter-Domain Routing (CIDR) has been developed to replace the previous classful network addressing architecture on the Internet to help slow the rapid exhaustion of IPv4 addresses. CIDR is based on Variable-Length Subnet Masking (VLSM). The VSLM is used to distinguish the network's IP from the host interface. CIDR also introduced the so-called CIDR notation ("/x").

CIDR allows subnetting which is breaking a large network into smaller ones.

### Variable-Length Subnet Masking
A subnet mask or netmask is a bitmask that encodes the prefix length associated with an IPv4 address. The prefix bits are always contiguous (a series of ones followed by a series of zeros until the end).

> **IP address** : 10.42.37.12 / 22  
> CIDR Notation : /22 -> netmask : 255.255.**252**.0  
> Magic Number : 256 - 252 = 4  
> Subnets (boundary byte 37):  
> **10.42.** [0, 4, 8, 12, 16, 20, 24, 28, 32, **36**, **40**, 44, ...]**.0**
> - **IP range** : 10.42.**36**.1 to 10.42.**39**.254
> - **Network Address** : 10.42.**36**.0
> - **Broadcast Address** : 10.42.**39**.255
> - **Number of usable IPS** : 1022 (2 ** (32 - 22) - 2)

> | CIDR % 8 | Last byte | Magic Number |
> | :------: | :-------: | :----------: |
> |    1     |    128    |      128     |
> |    2     |    196    |       64     |
> |    3     |    224    |       32     |
> |    4     |    240    |       16     |
> |    5     |    248    |        8     |
> |    6     |    252    |        4     |
> |    7     |    254    |        2     |

## Default Gateway

The default gateway is the local router IP address. This is also known as the Gateway of Last Resort as this is the last host to which data is sent. To avoid broadcast loop between routers, routers never forward broadcast messages.

## Private Addresses (RFC 1918)
This are IP addresses for private use. We can use these IPs in any way we want within a **local** network. They are therefore not allowed int the Internet.

 > Ranges for private IP addresses :
 > - Class A : 10.0.0.1		to 10.255.255.254
 > - Class B : 172.16.0.1	to 172.31.255.254
 > - Class C : 192.168.1.1	to 192.168.255.254
