FROM ubuntu:18.04

# Dependencies for C++, X11, GLFW, and OpenGL.
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    cmake \ 
    libglfw3 \
    libglfw3-dev \
    libgles2-mesa-dev \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev && \
    rm -rf /var/lib/apt/lists/*
