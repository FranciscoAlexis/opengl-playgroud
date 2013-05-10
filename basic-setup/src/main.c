/*
	Francisco Rojas about.me/franciscoalexis
	
	based on Thomas Dalling's example - http://tomdalling.com/

	=Fancy licence statement here=
*/
#include <stdio.h>
//Extension Wrangler
#include <GL/glew.h>
//For creating window, receive mouse and keyboard input (crossplatform?)
#include <GL/glfw.h>

int main(){
	if(!glfwInit()){
		printf("%s\n","Oh god! glfw init just failed!");
		return 1;
	}
	//open a window with glfw
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if(!glfwOpenWindow(1280, 720, 8, 8, 8, 8, 0, 0, GLFW_WINDOW)){
        printf("%s\n","glfwOpenWindow failed. Can your hardware handle OpenGL 3.2?");
        return 1;
    }
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if(glewInit() != GLEW_OK){
        printf("%s\n","Oh no! glew init failed for crying out loud!");
        return 1;
	}
    // print this stuff to know what do we have here
    printf("%s %s\n","OpenGL version: ",glGetString(GL_VERSION));
    printf("%s %s\n","GLSL version: : ",glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("%s %s\n","Vendor: ",glGetString(GL_VENDOR));
    printf("%s %s\n","Renderer: ",glGetString(GL_RENDERER));

    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2){
        printf("%s\n","Damn, OpenGL 3.2 API is not available.");
        return 1;
    }

    // while window is open
    while(glfwGetWindowParam(GLFW_OPENED)){
        // clear everything
	    glClearColor(0, 0, 0, 1); // black
	    glClear(GL_COLOR_BUFFER_BIT);
	    
	    // bind the program (the shaders)
	    //glUseProgram(gProgram->object());
	        
	    // bind the VAO (the triangle)
	    //glBindVertexArray(gVAO);
	    
	    // draw the VAO
	    //glDrawArrays(GL_TRIANGLES, 0, 3);
	    
	    // unbind the VAO
	    //glBindVertexArray(0);
	    
	    // unbind the program
	    //glUseProgram(0);
	    
	    // swap the display buffers (displays what was just drawn)
	    glfwSwapBuffers();
    }

    // clean up and exit
    glfwTerminate();

	return 0;
}