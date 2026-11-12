# Learning Graphics Programming

A collection of small C++ experiments built with [Raylib](https://www.raylib.com/). Each module explores a graphics or programming concept through a focused implementation.

## Experiments

| Module | Concepts | Source | Preview |
|---|---|---|---|
| Bouncing Ball | Gravity, velocity, air drag, coefficient of restitution | [Bounce.cpp](src/Bouncing_Ball/Bounce.cpp) | [GIF](src/Bouncing_Ball/Assets/record.gif) |
| 2D Rotation | Trigonometry and rotation transforms | [Rotation.cpp](src/Rotating_2D_Ball/Rotation.cpp) | — |
| Collision and Player Control | Keyboard input and collision detection | [Collision.cpp](src/Collision/Collision.cpp) | [Image](src/Collision/Assets/image.png) |
| Sprite Animation | Sprite sheets and frame-based animation | [animation.cpp](src/Animation/animation.cpp) | — |

## Concepts

- Applying vectors and trigonometry to movement and rotation.
- Simulating basic motion with gravity and drag.
- Handling collisions and player input.
- Working with sprite sheets and animation frames.
- Translating mathematical concepts into real-time graphics.

## Repository Structure

```text
Learn_Graphics_Programming/
└── src/
    ├── Animation/
    │   ├── Assets/
    │   ├── animation.cpp
    │   └── README.md
    ├── Bouncing_Ball/
    │   ├── Assets/
    │   ├── Bounce.cpp
    │   └── README.md
    ├── Collision/
    │   ├── Assets/
    │   ├── Collision.cpp
    │   └── README.md
    └── Rotating_2D_Ball/
        ├── Rotation.cpp
        └── README.md
```

## Build Requirements

- A C++ compiler.
- Raylib installed and configured for your platform.

The experiments are separate programs rather than one combined application. Configure Raylib for your compiler, then build the relevant source file. This repository does not currently provide a shared cross-platform build configuration.

## Asset Credits

The sprite assets used by the animation experiment are credited in [src/Animation/README.md](src/Animation/README.md).

---

This is an actively evolving learning repository; implementations and experiments may change as I work through graphics programming fundamentals.
