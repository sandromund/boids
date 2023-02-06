# Boids in C

## Requirements

- SDL2
- SDL2_gfx
- SDL2_ttf
- cmake

## How to build and run

```
$ mkdir build
$ cd build
$ cmake ..
#---
$ make
$ ./boids
$ cd ..
$ ./build/boids
```

Steps before `#---` are only needed the first time.

## Key bindings

- q: quit
- p: toggle pause
- s: do 1 update step
- r: reset boids to random positions and velocities
- v: reset boids' velocities to random values
- d: toggle debug view
- 1: toggle separation
- 2: toggle cohesion
- 3: toggle alignment
- 4: toggle FOV

## TODO / Next Steps

- Fix / investigate right down tendency
- Obstacle spawning with mouse click
- Predator boids
