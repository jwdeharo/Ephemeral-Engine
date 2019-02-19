#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Utils/Utils.h"

#include "ECS/CWorld.h"
#include "ECS/CComponent.h"

//Window dimensions.
const GLint WIDTH   = 800;
const GLint HEIGHT  = 600;

constexpr int ERROR   = 1;
constexpr int SUCCESS = 0;

int main()
{
  using namespace EphemeralEngine;
  using namespace Utils;

  Entities::CWorld* World = new Entities::CWorld();
  Entities::CEntity FirstEntity = World->CreateEntity();
  Entities::CEntity SecondEntity = World->CreateEntity();
  
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

  //Loop until window closed.
  while (!glfwWindowShouldClose(mainWindow))
  {
    //Get and handle user input events.
    glfwPollEvents();

    //Clear window.
    glClearColor(1.0f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(mainWindow);
  }

  return SUCCESS;
}
