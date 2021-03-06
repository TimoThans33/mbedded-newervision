#ifndef SCENE_H
#define SCENE_H

#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <X11/X.h>
#include <X11/Xlib.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#include "linmath.h"

#include <vector>
#include <json-c/json.h>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fstream>
#include <vector>

class Scene
{
    private:
        GLFWwindow* window;
        GLuint vbo, vertex_buffer, vertex_shader, fragment_shader;
        GLint mvp_location, vpos_location, vcol_location;
        
        std::string vertex_shader_text;
        std::string fragment_shader_text;

        const char* fs_text;
        const char* vs_text;
        int vertex_flag, fragment_flag;
        // json declerations
        struct json_object *parsed_json;
        struct json_object *x;
        struct json_object *y;
        struct json_object *v;
        struct json_object *x_id;
        struct json_object *y_id;
        struct json_object *v_id;
    public:
        GLuint program;
        Display *display;
        Window root;
        Window win;
        XEvent ev;
        Colormap cmap;
        XSetWindowAttributes swa;
        GLXContext glc;
        XWindowAttributes gwa;
        XVisualInfo *vi;
        std::string read_shader(char direction[]);
        int get_compile_data(GLuint shader);
        int link_shader(char vs_direction[], char fs_direction[]);
        void init_X11(void);
        void init_glfw(void);
        int draw(char *socket_data);
        void glfw_cleanup(void);
};
#endif
