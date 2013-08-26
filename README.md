wii
===

Simple web front end for [Irc it](http://tools.suckless.org/ii/).

This web script implements an easy way to chat over an existing
[ii](http://tools.suckless.org/ii/) session.
The web front end it self is written with [W3C standard](http://www.w3.org/)
techniques.
Edit *chat.css* to customize the style of this chat front end.

The C implementations of the CGI scripts should be used within a chrooted
web server.
So no shell utilities have to be inside of the chroot directory.
