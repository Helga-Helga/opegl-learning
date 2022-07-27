# Simple triangle

## Description

This example provides a minimal code to draw a triangle using simple shaders and vertex buffers.

## Building the example

Run the docker container with

```bash
./run-docker.sh
```

and build the project with

```bash
mkdir build
cd build
cmake ..
make
```

If the project build was successfull,
`SimpleTriangle` application will appear in the `build/` directory.

## Result

If you launch the `SimpleTriangle` application, you should see a purple triangle.

![Screenshot](simple_triangle.png)
