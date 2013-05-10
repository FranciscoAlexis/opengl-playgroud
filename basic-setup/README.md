Mac OS X
--------

Setup Instructions
------------------

* Install Glew: http://glew.sourceforge.net/

Usually you should be ok just compiling

	$ make

And installing

	$ sudo make install

BUT if you have problems like "'SYSYEM' not suported" change the next line on the Makefile
	
	SYSTEM ?= $(shell config/config.guess | cut -d - -f 3 | sed -e 's/[0-9\.]//g;')
	
with
	SYSTEM = darwin

* Install glfw: www.glfw.org/‎
This worked for me like a charm, just compile

	$ make cocoa

and then

	$ sudo make cocoa-install

Any problems? RTFM.

Running Instructions
--------------------
* Compile

	$ make

* Run

	$ ./bin/openGLDemo


OTHER OS
--------
* wait for it.




