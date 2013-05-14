OpenGL Demo
===========

This demo is intended to show you a basic OpenGL setup that paints a textured triangle with the help of a vertex, a fragment shader and a texture file. No classes where coded in order to show a clear sequence of steps required to get everything running. The texture comes from Thomas Dalling's examples site http://tomdalling.com/blog/modern-opengl/02-textures/

This implementation is far from being the most efficient one, but as i said this is only to show how things work.

You can compare the source of this example with the previous one (basic setup) and see the differences. 

Finally, right know i don't have a (fast, crossplatform, crosscomputer) workaround to pass the texture path to the program. Unless i code a resource manager that handle this (out of this example scope), the texture path will have to be passed manually as an argument (see running instructions).

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
* Create TEXTURE_PATH enviroment variable `$ export TEXTURE_PATH=$PWD/assets/hazard.png`
* Run: `$ ./bin/openGLDemo $TEXTURE_PATH`

OTHER OS
========
* Windows, Linux, Raspberry Pi, PS4, Wii U, New Xbox... 
	
	Wait for it :D




