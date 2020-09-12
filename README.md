# Pybind11 Tutorial

This repository is supplemental material of [Pybind11でC++とPythonのいいとこ取りをする](). 

## Requirements

* C++17
* CMake 3.12 or Higher

## Setup

Setup external libraries by running following command.

```sh
git submodule update --init
```

## Build

```sh
mkdir build
cd build
cmake ..
make -j2
```

## Run

After building C++ codes, you need to copy  `build/MyLib.CPython*.so` to `python/`.

Then run `python/test.py`
```sh
python python/test.py
```

## Externals

* [Pybind11](https://github.com/pybind/pybind11)