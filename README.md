# Nodes

A backend for nodes which may be used in [Gimel Studio](https://gimelstudio.github.io).

## Features

- No external dependencies - only the C++ standard library is been used
- Backend only - you can implement your own frontend
- Simple API (at least in my opinion)
- Node muting

## Compiling

This assumes you already have C/C++ and CMake already set up.

1. Download or clone this repository
2. Open a terminal in the top level directory.
3. Run `mkdir build && cd build`
4. Run `cmake ..`
5. Run the appropriate command for the compiler you're using, i.e.
```bash
make
# or
ninja
# or
clang
# etc.
```

## Running

To run the example found in `src/main.cpp`, run `./src/nodes{{OS EXECUTABLE EXTENSION}}` still inside of the `build/` directory, where `{{OS EXECUTABLE EXTENSION}}` is the operating system's executable extension, i.e. blank for Linux, `.exe` for Windows, etc..

## Additional Notes

As of writing, I am not completely convinced that this uses the most efficient evaluation system. A key problem is that the *whole* node tree is evaluated every time, even if some nodes don't need to be run again.

## License

This project is released under the MIT license. Do what you wish with it.