Add README instructions identifying the operating system, compiler, 
C++ standard, and exact build/run steps. List any dependencies currently needed. 
Exclude generated build folders, executables, and credentials.

#PokemonGame

- Compiler: g++
- Editor: VS Code
- C++17
- OS: Windows 11 & MacOS 14
- Dependencies: QT 6 required

Build and Run:
- Install QT
- Clone: https://github.com/DDGhost4/PokemonGame.git
- Open PokemonGame folder in VS Code
- Open terminal and run:
    cmake --build build
    ./build/PokemonGame

IMPORTANT: persistence is used in pokedex_save.txt -> to delete save data delete everything under POKEDEX1 