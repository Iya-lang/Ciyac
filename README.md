# **Welcome to Ciya! (parser stage)**
<img width="500" height="500" alt="drawing" src="https://github.com/user-attachments/assets/622fb2f4-5ae8-481f-ab5f-76778e812c9a" />

**Welcome, dear reader!**

Now, we're trying to make a new project called `Ciya`.

**Ciya**, a fast, cross-platform programming language from the Philippines/Vietnam written in C.
The name **Ciya** came from the word `Siya`, which means he/she in filipino/tagalog language, 
We want `Ciya` to be a bigger and faster leap than its successor, `CRy-VM`.

For now, we're still in development,
but if you have any ideas to share, we'll try our best to achieve them.

## Wanna collaborate?
Please read our CONTRIBUTING file.

## Essential tools:
  * [GCC](https://gcc.gnu.org/) ([Clang](https://clang.llvm.org/) or [Mircosoft C/C++ Compiler](https://aka.ms/vs/17/release/vs_BuildTools.exe)): for compiling code
  * [CMAKE](https://cmake.org/): For building the build files
  * [MAKE](https://en.wikipedia.org/wiki/Make_(software)) (or other build systems like [Ninja](https://ninja-build.org/)): for building the program
  * [GDB](https://www.sourceware.org/gdb/)(optional): For debugging code, or you can use the debugger in some IDE's
  * [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)(for windows, optional) for Linux testing binaries

## Why we made the project:
We first made the project on July 22nd, 2026, which is very *early*, after the creator and owner of
**CRy-VM** suggested a new language. So, we started this repo to be a *faster and bigger* leap than its successor, CRy-VM. As long ago, in **2024-2025**, the creator who made Ry1 found out he was using too much AI and heavy tools, heavy classes, etc., which made it unoptimized. So, we made Ciya! But really don't fork the older ones, as it's abandoned and no longer has
support.

## Pros:
 * Cross-compatible
 * Working lexer
## Cons:
 * No standard libraries
 * No support for file reading

## How to install the packages:
<img width="480" height="360" alt="image" src="https://github.com/user-attachments/assets/b6a2cff3-7c81-464c-9775-82c822137046" />

To install the Linux or BSD packages, use curl or wget; we'll use curl as it is very common:
First, we get the tarball from the latest release:
```bash
curl -o ciya.tar.gz -L https://github.com/Ciya-VM/Ciya/archive/refs/tags/v0.0.3.tar.gz
```

And then, we extract it:
```bash
tar -xzvf ciya-linux.tar.gz
```

Apply permissions:
```bash
chmod +x ciya
```

And Booom, you can run it; it's that simple:
```bash
./ciya
```

Here is every command altogether:
```bash
curl -o ciya.tar.gz -L https://github.com/Ciya-VM/Ciya/archive/refs/tags/v0.0.3.tar.gz
tar -xzvf ciya-linux.tar.gz
chmod +x ciya
./ciya
```

But there are *different ways* to install the packages, and it depends on what fits you!
An example is using a .deb file:
```bash
# Get the .deb file
curl -o ciya.deb -L https://github.com/Ciya-VM/Ciya/releases/download/v0.0.3/ciya-linux_0.0.3_amd64.deb
sudo apt install ciya.deb # Then just install it
ciya # Run it
```

## More details in:

[Our official Wiki](https://github.com/Ciya-VM/Ciya/wiki/Introduction),
[Our website](https://ciya-vm.github.io/),
[Development code](https://github.com/Ciya-VM/Ciya/tree/development),
[Minimal code](https://github.com/Ciya-VM/Ciya/tree/minimalist),
[HTML source code](https://github.com/Ciya-VM/Ciya-VM.github.io)

# Q&A:

If you have any *problems* or *questions* to ask, please make them in the discussion; the community may answer them, but
we'll respond in a span of hours to days. But hope y'all have a good day =)!

Repo made by `Johnryzon Z. Abejero`

Contributors: 
* Nguyễn Phước Thành Lâm
