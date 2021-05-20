# ```Ethernet Protocol```
## MAC addresses
- 1 MAC address per network interface
- 48 bits long : AA:BB:CC:00:11:22
	- First 24 bits : Organizationally Unique Identifier (OUI). Assigned by the IEEE to the manufacturer.
	- Last 24 bits : Vendor Assigned
- Broadcast : ff:ff:ff:ff:ff:ff  
	Delivers the frame to every device connected. Routers do not forward broadcast frames.
- Multicast.

## Ethernet Format
![Ethernet_Format](./Images/Ethernet_Format.svg)

### `Preamble`
A fixed pattern of ones and zeros which lasts for 7 bytes. It shows the start of a frame. The eighth byte is the Start Frame Delimiter (SFD).
### `Destination`
The destination MAC address.
### `Source`
The source MAC address
### `Type`
Tells which protocol is in the data section of the frame. Most likely IPv4 or IPv6.
### `Frame Check Sequence (FCS)`
Used to tell is any part of the frame has become corrupted during transit.

## Old style transmission
All computers are connected to a single common ethernet cable (BUS-like). Transmitted data is accessible to every computer plugged to the network. Each computer has a unique MAC (Media Access Control) address. Data is only processed when the MAC address correspond to the computer's one.
- Bandwidth : rate at which a carrier can transmit data
- Collision : two or more devices write simultaneously data
- Collision Domain : list of devices sharing the same ethernet BUS.

Cons
- Lot of unnecessary traffic.
- Security hazard.

### Carrier Sense Multiple Access (CSMA)
Carrier Sense Multiple Access (CSMA) is a Media Access Control protocol used to minimize collisions :
1. *Collision Avoidance*  
	Determine when the network is idle and only transmit then.
2. *Collision Detection*  
	When 2 or more devices detect a collision, they wait for brief period before attempting to 	re-transmit. The waiting time has a random component. When multiple collisions happen in a row, the waiting time increases exponentially. This is called **Exponential Backoff**.

## HUBS
*A layer 2 device - Still a BUS like network*
The devices are connected to the HUB instead of chaining all the nodes up. The frames are still sent to every device.
- Half Duplex : cannot send and receive at the same time
- Collision Domain = entire network.

Cons
- All devices in the same Collision Domain,
- Half Duplex,
- Data replicated to all ports,
- Limited scalability.

## Bridges
*A layer 2 device - Still a BUS like network*
Bridges have MAC addresses tables which contain all the MAC of the network and to which interface the devices are connected to. Allow to break the network into sub collision domains.

If a frame arrives at an interface of the bridge:
1. The dst MAC is in the same sub-domain. The bridge does nothing.
2. The dst MAC is connected to another bridge's interface. The bridge forward the frame out (Filtering).

Bridges have 5 functions :
- Filtering
- Learning
- Flooding
- Forwarding
- Aging

Pros
- Less traffic flooding,
- Smaller Collision Domains,
- Better performances,
- Better scalability.

### How the MAC table is filled
1. Whenever a frame arrives at an interface the bridge looks for the src MAC address. If the address id not already in the table, the MAC is added with the corresponding interface.
2. If the src MAC is unknown, the bridge flood the frame out at all interfaces except the one the frame arrived on.
3. If the MAC is already in the table but is associated to another interface, the table is updated.
4. All the entries of the table have an aging timer. The timer is reset at each new incoming frame. If the timer expires, the entry is removed from the table.
5. If the table is full and a new entry needs to be learned, the oldest entry is discarded.

## Switches
*A layer 2 device - Star topology*  
Switches are a mix between Hubs and Bridges. They have a lot of interfaces and behave like Bridges.

- Some switches have MAC addresses which allow them to be connected to other switches.
- Each MAC address can be associated to only one interface, but an interface can be associated to many MAC addresses.
- Switches, bridges and Hubs forward frames with the broadcast MAC addresses (FF:FF:FF:FF:FF:FF). Routers do not!

Pros
- Smallest Collision Domain
- Full Duplex
- Efficient

### Handling Frames
1. **Store and Forward** - Safest  
	Keeps the frame in memory until the entire frame has arrived and only then forward the frame out. This allows checking for errors.
2. **Cut Through** - Fastest  
	Keeps the frame in memory until the switch can see the dst MAC address. Then looks up in the table and start forwarding out the bits.
3. **Fragment Free**  
	The switch stores the first 64 bits of the frame as this is the part which is most likely to have errors. If there isn't any error, all the bits are sent out as soon as they arrive.

## Virtual Local Area Network (VLAN)
*A layer 2 technology*   
Using the switch to virtually divide the network into sub-networks.
- Adds security to the larger network,
- Less hardware is needed w.r.t. actual multiple LAN,
- Allows to run Management or Guest Network,
- Allows to separate different types of traffic (Voice & Data, ...),
- Applies different settings to different VLANs,
- Limits Broadcast and Flooding,
- Smaller failure domains.

### VLAN ID
12 bits : 1 to 4064, 0 and 40695 being reserved.

VLANs provide a layer 2 boundary and frames from one VLAN will not pass through another VLAN. A router (layer 3 device) is needed to move packets from network to another. To be able to do so, the router must have an interface connected to each VLAN. Each interface has also an IP address. The Default Gateway of each VLAN is the corresponding router's IP. The Address Resolution Protocol (ARP) is used to associate an MAC address to an IP.

### VLAN Trunk Link
A Trunk/Tag link allows to use a single link between switches for large network with several VLANs. Trunking or Tagging adds a *Tag* in the Ethernet header (4 bytes) with the VLAN ID and other information. This tag is added, processed and removed by the switches. This is not seen by end-use devices. This trunk link extends Broadcast Domain.

A trunk link can also be used between a switch and a router. This allows to divide an interface into several virtual interfaces with their own IPs. This is called Router On A Stick (ROAS).
