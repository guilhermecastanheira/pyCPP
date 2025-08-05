# pyCPP

A simple example of exposing C++ functions to Python using [pybind11](https://github.com/pybind/pybind11), CMake, and Jupyter Notebook.

## Tools Used

- **C++ (MSVC or Clang)** — For writing and compiling the native extension.
- **[pybind11](https://github.com/pybind/pybind11)** — For creating Python bindings for C++ code.
- **[CMake](https://cmake.org/)** — For building the C++ extension module.
- **[Python 3.12](https://www.python.org/)** — For running and importing the extension.
- **[Jupyter Notebook](https://jupyter.org/)** — For interactive testing of the compiled module.
- **[Visual Studio Code](https://code.visualstudio.com/)** — As the development environment.

## Project Structure

```
pyCPP/
├── src/
│   └── module.cpp
├── Notebooks/
│   └── main.ipynb
├── CMakeLists.txt
├── README.md
└── build/
    └── module*.pyd
```

## Build Instructions

1. **Install dependencies:**
    ```sh
    pip install pybind11 notebook
    ```

2. **Build the extension:**
    ```sh
    mkdir build
    cd build
    cmake ..
    cmake --build . --config Release
    ```

3. **Test in Jupyter Notebook:**
    - Start Jupyter:
      ```sh
      jupyter notebook
      ```
    - In your notebook, add the build directory to `sys.path` and import the module:
      ```python
      import sys
      sys.path.append(r'../build/Release')  # or the absolute path to your build output
      import module

      print(module.add(2, 3))
      ```

## Notes

- Delete the `build` path before create the new one. 
- Make sure your Python version matches the `.pyd` file (e.g., Python 3.12 → `python312.lib`).
- If you use a different compiler or Python version, adjust the CMake configuration accordingly.