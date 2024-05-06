<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://github.com/cwhitelytning/liquid/blob/main/img/1a619fdd-f5b9-44b8-869c-a0ff047b8974.png">
  <source media="(prefers-color-scheme: light)" srcset="https://github.com/cwhitelytning/liquid/blob/main/img/69f499c1-f922-4911-800d-60910128a0d3.png">
  <img alt="Shows an illustrated banner in light mode in the dark mode." src="https://github.com/cwhitelytning/liquid/blob/main/img/69f499c1-f922-4911-800d-60910128a0d3.png">
</picture>

# Liquid

Cross-platform static library that allows you to use operating system functions regardless of the target
platforms. Developed in the C 11 standard programming language.

## Description

You no longer have to worry about dependencies when using operating system APIs. The library will take care of
this for you. It provides its own methods and properties that will work on any operating system.

## Peculiarities

1. As already mentioned, the static library is written with the most simple and understandable approach, which reduces
   the input
   barrier to using a cross-platform library in your project.
2. Only native methods (operating system API) are used, regardless of ready-made compiler solutions. This
   ensures that the code is visible and it works.
3. Actually tested on three compilers (**MSVC**, **GNU**, **CLANG**) in different operating systems (**Linux**
   and **Windows**) with different bit depths (**x86-64** and **x86**).
4. Has a single implementation for standardized and non-standardized **POSIX** systems.
5. Doesn't clutter your project with operating system APIs and uses the **snake_case** style typical of C-like ones
   languages.
6. Has support for multibyte strings when defining **UNICODE** for the Windows operating system.

## Installation

<details>
   <summary>Install the build system</summary>

### Windows

   ```bash
   scoop install cmake
   ```

   ```bash
   scoop install ninja
   ```

### Debian

   ```bash
   sudo apt install cmake
   ```

   ```bash
   sudo apt install ninja-build
   ```

### macOS

   ```bash
   brew install cmake
   ```

   ```bash
   brew install ninja
   ```

</details>

<details>
   <summary>Install a code formatter</summary>

### Windows

`scoop` does not have a separate `clang-format` package, but it is included with `llvm` when installed.

### Debian

   ```bash
   sudo apt install clang-format
   ```

### macOS

   ```bash
   brew install clang-format
   ```

</details>

<details>
   <summary>Install one of the compilers</summary>

### Windows

   ```bash
   scoop install gcc
   ```

**or**

   ```bash
   scoop install llvm
   ```

**or** please download [Microsoft Visual Studio](https://visualstudio.microsoft.com/) from official repository.

### Debian

   ```bash
   sudo apt install gcc
   ```

**or**

   ```bash
   sudo apt install clang
   ```

### macOS

Execute the
below [script](https://gist.github.com/diogorusso/47756a7a474f7236332d11eabe9ac5ae#file-1-1-install-xcode-commnadline-sh)
to install `xcode` developer tools from the command line.

```bash
# who are you?
whoami
# check if Xcode package is installed
# if installed it will display : /Applications/Xcode.app/Contents/Developer
xcode-select -p
# install Xcode command line form terminal
xcode-select --install
# verify successfull installation
xcode-select -p
# verify if GCC is installed
gcc --version
```

</details>

<details>
   <summary>Install the Documentation Generator</summary>

### Windows

   ```bash
   scoop install doxygen
   ```

   ```bash
   scoop install graphviz
   ```

### Debian

   ```bash
   sudo apt install doxygen
   ```

   ```bash
   sudo apt install graphviz
   ```

### macOS

   ```bash
   brew install doxygen
   ```

   ```bash
   brew install graphviz
   ```

</details>