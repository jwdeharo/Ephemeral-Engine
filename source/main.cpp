#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Utils/Utils.h"

#include "ECS/Handlers/CEntityHandler.h"

//Window dimensions.
const GLint WIDTH = 800;
const GLint HEIGHT = 600;

GLuint VAO, VBO, shader;

//Vertex shader.
static const char* vShader = "                              \n\
#version 330                                                \n\
                                                            \n\
layout(location = 0) in vec3 pos;                            \n\
                                                            \n\
                                                            \n\
void main()                                                 \n\
{                                                           \n\
  gl_Position = vec4(0.4 * pos.x, 0.4 * pos.y, pos.z, 1.0); \n\
                                                            \n\
                                                            \n\
}";

static const char* fShader = "                              \n\
#version 330                                                \n\
                                                            \n\
out vec4 colour;                                            \n\
                                                            \n\
void main()                                                 \n\
{                                                           \n\
  colour = vec4(1.0, 0.0, 0.0, 1.0);                        \n\
}";

constexpr int ERROR = 1;
constexpr int SUCCESS = 0;

void AddShader(GLuint aProgram, const char* aShaderCode, GLenum aShaderType)
{
  GLuint TheShader = glCreateShader(aShaderType);

  const GLchar* Code[1];
  Code[0] = aShaderCode;

  GLint CodeLength[1];
  CodeLength[0] = strlen(aShaderCode);

  glShaderSource(TheShader, 1, Code, CodeLength);
  glCompileShader(TheShader);

  GLint result = 0;
  GLchar oLog[1024] = { 0 };

  glGetShaderiv(TheShader, GL_COMPILE_STATUS, &result);

  if (!result)
  {
    glGetShaderInfoLog(TheShader, sizeof(oLog), nullptr, oLog);
    EphemeralEngine::Utils::fatal("Error compiling %d shader: %s", aShaderType, oLog);
    return;
  }

  glAttachShader(aProgram, TheShader);
}

void CompileShaders()
{
  shader = glCreateProgram();

  if (!shader)
  {
    EphemeralEngine::Utils::fatal("Error creating shader program!\n");
    return;
  }

  AddShader(shader, vShader, GL_VERTEX_SHADER);
  AddShader(shader, fShader, GL_FRAGMENT_SHADER);

  GLint result = 0;
  GLchar oLog[1024] = { 0 };

  glLinkProgram(shader);
  glGetProgramiv(shader, GL_LINK_STATUS, &result);

  if (!result)
  {
    glGetProgramInfoLog(shader, sizeof(oLog), nullptr, oLog);
    EphemeralEngine::Utils::fatal("Error linking program: %s", oLog);
    return;
  }

  glValidateProgram(shader);
  glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);

  if (!result)
  {
    glGetProgramInfoLog(shader, sizeof(oLog), nullptr, oLog);
    EphemeralEngine::Utils::fatal("Error validating program: %s", oLog);
    return;
  }


}

void CreateTriangle()
{
  GLfloat vertices[] =
  {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f, 1.0f, 0.0f
  };

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);
}


struct Transform : public EphemeralEngine::Entities::SComponent<Transform>
{
  float X;
  float Y;
  float Z;

  Transform() : X(0.f), Y(0.f), Z(1.f) {};
};

int main()
{
  using namespace EphemeralEngine;
  using namespace Utils;

  Entities::CWorld* World = new Entities::CWorld();
  Entities::CEntityHandler Handler = World->CreateEntity();
  Transform NewTransform;

  Handler.AddComponent(NewTransform);

  Transform OldTransform = Handler.GetComponent<Transform>();

  //Initialise GLFW
  if (!glfwInit())
  {
    glfwTerminate();
    Utils::fatal("Couldn't initialise GLFW");
    return ERROR;
  }

  //Setup GLFW window properties.
  //OPENGL version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //Core profile = No backwards compatibility.
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //Allow forward compatibility.
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "EphemeralEngine", nullptr, nullptr);

  if (mainWindow == nullptr)
  {
    glfwTerminate();
    Utils::fatal("GLFW window creation failed.");
    return ERROR;
  }

  //Get buffer size information.
  int bufferWidth;
  int bufferHeight;

  glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

  //Set the context for GLEW to use.
  glfwMakeContextCurrent(mainWindow);

  //Allow modern extension features.
  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK)
  {
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    Utils::fatal("Couldn't initialise GLEW.");
    return ERROR;
  }

  //Setup viewport size.
  glViewport(0, 0, bufferWidth, bufferHeight);

  CreateTriangle();
  CompileShaders();


  //Loop until window closed.
  while (!glfwWindowShouldClose(mainWindow))
  {
    //Get and handle user input events.
    glfwPollEvents();

    //Clear window.
    glClearColor(0.0f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader);

    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);

    glUseProgram(0);

    glfwSwapBuffers(mainWindow);
  }

  return SUCCESS;
}
