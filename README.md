# IMS project - Impact of construction on the environment

## About
Matej's legs smell like shit. Feet ty angličan.
Juraj is gay.

#### L.A.G song -  Horkýže Slíže
Poď sem, nech sa stebou zblížim.
Poď sem, ja ti neubližim.
Poď sem, ja ťa nezbijem.
I'm sorry, I'm Lesbian.
Poď sem, som tvoj dvorny basnik.
Mam energiu za dvanastich
a k tomu lubrikačný gel.
I'm sorry, I'm really Gay.
Lesbian's and Gay's song.
Lesbian's and Gay's sooooong.
Lesbian's and Gay's song.
Lesbian's and Gay's song.
Poď sem, pustim Iron Maiden.
Poď sem, nalejem ti za jeden.
Poď sem, s barskym nepijem.
I'm sorry, I'm Lesbian.
Poď sem, tu si ku mne hačaj.
Ked´som ťa pozval na rum a čaj.
Stoj! Nechod nikam! Čo je? Hej!
I'm sorry, I'm really Gay.
Refren:
Lesbian's and Gay's song
Lesbian's and Gay's sooooong
Lesbian's and Gay's song
Lesbian's and Gay's sooooong
Lesbian's and Gay's song
Lesbian's and Gay's sooooong
Lesbian's and Gay's song
Lesbian's and Gay's song
Poď sem, spolu mame v plane.
že ťa okupem vo fontane.
tak otvor branu lebo ju rozbijem!!
I'm sorry baby, I'm Lesbian.
Viem, neopakuj mi to stale
ja som vyrastol na Death Metale,
ja takymto veciam rozumiem.
I'm sorry ...ale ved ja viem.
Refren:
Lesbian's and Gay song
Lesbian's and Gay sooooong
Lesbian's and Gay song
Lesbian's and Gay sooooong
Lesbian's and Gay song
Lesbian's and Gay sooooong
Lesbian's and Gay song
Lesbian's and Gay song
Lesbian's and Gay song
I'm sorry
Lesbian's and Gay sooooong
Lesbian's and Gay song
I'm sorry
Lesbian's and Gay sooooong
Lesbian's and Gay song
I'm sorry. 

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

