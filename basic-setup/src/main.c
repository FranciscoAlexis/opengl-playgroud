/*
	OpenGl basic setup created by Francisco Rojas about.me/franciscoalexis
	
	based on Thomas Dalling's examples - http://tomdalling.com/

	[Fancy licence statement here].
*/
#include <stdio.h>
#include <GL/glew.h> // OpenGL Extension Wrangler
#include <GL/glfw.h> // handle window, mouse and keyboard input

int main(){
	// init glfw
	if(!glfwInit()){ printf("%s\n","Oh god! glfw init just failed!"); return 1; }

	// open a window with glfw
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
	if(!glfwOpenWindow(1024, 768, 8, 8, 8, 8, 0, 0, GLFW_WINDOW)){
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

	// Before we create the shaders we must create a program to attach the shaders to
	GLuint program = glCreateProgram();

	// Load shaders, for this example we will have 2 harcoded shaders
	// Vertex shader
	GLuint shader = glCreateShader(GL_VERTEX_SHADER);

	if(shader != 0){
		const GLchar* code[] = {"#version 150\n in vec3 vert; void main() {  gl_Position = vec4(vert, 1); }"};
		/*
		* The first argument is the vertex shader ID.
		* The second argument is how many source strings you're using. 
		* Caution: the GLSL compiler expects one long string per source file. Much like in C++, you can have 
		* more than one source file per shader. However, it will treat each string in the array as a source file.
		* The third argument is the pointer to the array of shader source strings. 
		* The last argument is the array of string lengths for each of the shader source strings. 
		* If this is null, the GLSL source compiler assumes each string is null terminated.
		*/
		glShaderSource(shader,1,code,NULL);
		glCompileShader(shader); 
		int status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			printf("%s\n","Crap! vertex shader compilation failed");
			glDeleteShader(shader);
			return 1;
		}
	}else{ printf("%s\n","Aw man! glCreateShader failed"); return 1; }

	// If everything went well we attach the shader to our program
	glAttachShader(program,shader);

	GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
	if(fragmentShader != 0){
		const GLchar* code[] = {"#version 150\n out vec4 finalColor; void main() { finalColor = vec4(1.0, 1.0, 1.0, 1.0); }"};
		glShaderSource(fragmentShader,1,code,NULL);
		glCompileShader(fragmentShader); 
		int status;
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			printf("%s\n","Crap! fragment shader compilation failed");
			glDeleteShader(fragmentShader);
			return 1;
		}
	}else{ printf("%s\n","Aw man! glCreateShader failed");return 1; }
	glAttachShader(program,fragmentShader);

	// Link program
	glLinkProgram(program);

	int programStatus = GL_TRUE;
	glGetProgramiv(program,GL_LINK_STATUS,&programStatus);

	if( programStatus != GL_TRUE ){ printf("%s\n","Boomer! glLinkProgram failed");return 1; }

	// This is for the vertices that will form a triangle to draw on the screen
	// if you don't know the concept of VAO or VBO you can find a very good
	// explanation at homas Dalling's site
	GLuint gVAO = 0;
	GLuint gVBO = 0;
	// make and bind the VAO
	glGenVertexArrays(1, &gVAO);
	glBindVertexArray(gVAO);

	// make and bind the VBO
	glGenBuffers(1, &gVBO);
	glBindBuffer(GL_ARRAY_BUFFER, gVBO);

	// Put the three triangle verticies into the VBO
	GLfloat vertexData[] = {
		//X,Y,Z
		 0.0f, 0.8f, 0.0f,
		-0.8f,-0.8f, 0.0f,
		 0.8f,-0.8f, 0.0f,
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	// Connect the xyz to the "vert" attribute of the vertex shader
	const GLchar* attributeName = "vert";
	GLint attribute = glGetAttribLocation(program, attributeName);
	if(attribute == -1){ printf("%s\n","Noooo! unable to get attribute"); return 1; }
	glEnableVertexAttribArray(attribute);
	// attrib index, size, type, stride, pointer
	glVertexAttribPointer(attribute, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	// unbind the VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// while window is open
	while(glfwGetWindowParam(GLFW_OPENED)){
		// paint everything black (well, clear everything with black)
		glClearColor(0, 0, 0, 1); 
		glClear(GL_COLOR_BUFFER_BIT);
		//Tell OpenGL to use our shaders
		glUseProgram( program );

		// bind the VAO (the triangle)
		glBindVertexArray(gVAO);

		// draw the VAO
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// unbind the VAO
		glBindVertexArray(0); 

		// Now use the default shaders
		glUseProgram( 0 );

		glfwSwapBuffers();
	}

	// clean up and exit
	glfwTerminate();

	return 0;
}