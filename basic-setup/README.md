OpenGL Demo
===========

This demo is intended to show you a basic OpenGL setup that paints a white triangle with the help of a vertex and a fragment shader. No classes or functions where coded in order to show the sequence of steps required to get everything running.

This implementation is far from being the most efficient one, but as i said this is only to show how things work.

Mac OS X
========

Setup Instructions
------------------

* Install Glew: http://glew.sourceforge.net/

	Usually you should be ok just compiling: `$ make`. And installing `$ sudo make install`.

	BUT if you have problems like `"SYSYEM" not suported` change the next line on the Makefile:
	
	`SYSTEM ?= $(shell config/config.guess | cut -d - -f 3 | sed -e 's/[0-9\.]//g;')` with `SYSTEM = darwin`

* Install glfw: www.glfw.org/‎
	This worked for me like a charm, just compile: `$ make cocoa`, and then install: `$ sudo make cocoa-install`. Any problems? RTFM.

Running Instructions
--------------------
* Compile: `$ make`
* Run: `$ ./bin/openGLDemo`

OTHER OS
========
* Windows, Linux, Raspberry Pi, PS4, Wii U, New Xbox... 
	
	Wait for it :D




