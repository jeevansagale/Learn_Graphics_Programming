# 3D Orbital Motion

A small C++ and Raylib experiment that uses trigonometry to move one sphere around another in a 3D scene.

## What It Demonstrates

- Representing object positions with Raylib's `Vector3`.
- Computing circular motion with sine and cosine.
- Separating the moving body's position from the central body's position.
- Viewing a 3D scene with a perspective camera.

The moving sphere follows a circular path around the central sphere. Its horizontal position is updated using:

```cpp
x = center.x + radius * cos(angle);
z = center.z + radius * sin(angle);
```

The angle changes with elapsed time, producing continuous orbital motion.

## Preview

The program renders two spheres on a 3D grid. Use Raylib's free-camera controls to inspect the scene from different angles.

## Source

[Rotation.cpp](Rotation.cpp)

## Build Requirements

- C++ compiler
- Raylib
- Raygui headers (included by the source file)

The repository does not include a dedicated build script. Configure Raylib and Raygui for your compiler, then build this source file as a standalone program.
