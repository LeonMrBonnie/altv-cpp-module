# alt:V C++ Module

## How to build

To build the project simply run the `build.bat` file.

## How to use

Look at the [example resource](https://github.com/LeonMrBonnie/altv-cpp-example-resource) to see how to use this module.<br>
This module is a very simple wrapper, so don't expect anything fancy.<br>
In your resource you still have to use the C++ SDK from alt:V.<br>
This only imports the these three functions from your resource: `Start, Stop, OnEvent`.<br>
If you don't know what those functions do, look at the example resource.

## Why doesn't this work on Linux

Because importing a DLL from Linux is absolutely painful, and I am not mentally capable of implementing it without taking my own life.<br>
Just switch to Windows. 5Head

## Credits

- drake - For helping with setting up the module and moral support
- alt:V team - For providing the alt:V mod and the `Log.h` file