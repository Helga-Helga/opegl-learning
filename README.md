# OpenGL learning

## Docker installation and usage

There is a [Dockerfile](docker/Dockerfile) with all necessary dependencies for CMake, OpenGL, X11,
and GLFW in [docker](docker/) directory.

Build the image with

```bash
cd docker
docker build -t glfw-cpp:latest .
```

Run the docker container with

```bash
./run-docker.sh
```

This will launch the docker container and open the current directory where you can have access
to all the needed libraries, and can build and run the provided applications.

## Examples

1. [Simple Triangle](simple_triangle/) example provides a minimal code
   to draw a triangle using simple shaders and vertex buffers.
