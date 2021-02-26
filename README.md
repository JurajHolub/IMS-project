# IMS project - Impact of construction on the environment

## Dependencies
- C++14

## Instalation
Native environment OS GNU/Linux (Windows not tested).
- ``make`` - compile project.
- ``./ims-project -h`` - dump usage information.
## Usage
``isa-tazatel <arguments>``
Compulsory arguments:
``  -q <IP|hostname>  = IP or hostname address to by analyzed.
  -w <IP|hostname>  = IP or hostname of questioned WHOIS server``
Optional arguments:
``  -d <IP|hostname>  = IP or hostanme of questioned DNS server
                     (default value "1.1.1.1").
  -h                = Print this help message.``

## Repository overview
- ``main.c`` - Starting point of program.
- ``dns_query.h dns_query.cpp`` - Send DNS query and deparse response data with lreslov library.
- ``argument_parser.h argument_parser.cpp`` - Parse command line arguments.
- ``tcp_socket.h tcp_socket.cpp`` - Create send and recieve tcp sockets.
- ``whois_query.h whois_query.cpp`` - Send whois query and deparse recieved data.
- ``geolocation_database.h geolocation_database.cpp`` - Create HTTP request to ip-api.com geolocation database and parse recieved data.

