# cub3D

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A lightweight, Norm-compliant Unix shell in C, supporting command execution, pipes, redirections, built-ins, and basic signal handling.

## Table of Contents

- [Contributors](#contributors)
- [About](#about)  
- [Features](#features)  
- [Installation](#installation)  
- [Usage](#usage)  

## Contributors

- Silva5525 ([@Silva5525](https://github.com/Silva5525)) – Map parsing & input validation  
- Matvej-g ([@matvej-g](https://github.com/matvej-g))  – Raycasting engine & texture mapping & minimap

## About

`cub3D` is a Norm-compliant C raycasting engine inspired by Wolfenstein 3D. It parses a 2D map of walls, floors, and wall textures, projects them into a 3D view, and allows the player to navigate the scene in real time.

## Features

- **Raycasting engine**: Fast distance calculations.  
- **Texture mapping**: Apply same wall textures for the 4 Hemispheres (NORTH, EAST, SOUTH, WEST).  
- **Minimap**: 2D overhead view of the map.  
- **Configurable resolution**: Set window size in the configuration file.  
- **Norm-compliant**:  
  - Only allowed functions
  - Max 25 lines per function.  
  - 80-column width limit.  
  - Max 4 functions per file.  
  - Max 4 parameters per function.  

## Installation

1. **Clone the repo**  
   ```bash
   git clone https://github.com/matvej-g/cube3D
   cd minishell
   make bonus
   ```

## Usage

Run the executable `cub3D_bonus` with a `map.cub` you can check the example_map.cub to see how to Format the Map.
  ```bash
  ./cub3D_bonus example_map.cub
  ```

You can also just `make` this will creat the `cub3D` executable without the 2D_map

![cub3D_bonus example](image/example.png)
