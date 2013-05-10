/*
	OpenGl basic setup created by Francisco Rojas about.me/franciscoalexis
	
	based on Thomas Dalling's example - http://tomdalling.com/

	[Fancy licence statement here].
*/
#include <stdio.h>
#include <GL/glew.h> //OpenGL Extension Wrangler
#include <GL/glfw.h> //handle window, mouse and keyboard input

int main(){
	//init glfw
	if(!glfwInit()){ printf("%s\n","Oh god! glfw init just failed!"); return 1; }

	//open a window with glfw
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if(!glfwOpenWindow(720, 405, 8, 8, 8, 8, 0, 0, GLFW_WINDOW)){
        printf("%s\n","glfwOpenWindow failed. Can your silly hardware handle OpenGL 3.2?");
        return 1;
    }

	// initialise GLEW
	glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
	if(glewInit() != GLEW_OK){ printf("%s\n","Oh no! glew init failed for crying out loud!"); return 1; }

    // print this stuff to know what do we have here
    printf("%s %s\n","OpenGL version: ",glGetString(GL_VERSION));
    printf("%s %s\n","GLSL version: : ",glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("%s %s\n","Vendor: ",glGetString(GL_VENDOR));
    printf("%s %s\n","Renderer: ",glGetString(GL_RENDERER));

    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2){ printf("%s\n","Damn, OpenGL 3.2 API is not available."); return 1; }

	// while window is open
	while(glfwGetWindowParam(GLFW_OPENED)){
		// paint everything black (well, clear with black)
		glClearColor(0, 0, 0, 1); 
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers();
	}

    // clean up and exit
    glfwTerminate();

	return 0;
}