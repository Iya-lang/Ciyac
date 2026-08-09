# **Welcome to Ciya! (parser stage)**
<img width="500" height="500" alt="drawing" src="https://github.com/user-attachments/assets/622fb2f4-5ae8-481f-ab5f-76778e812c9a" />

**Welcome, dear reader!**

Now, we're trying to make a new project called `Ciya`.

**Ciya** is a new programming language designed for speed.
The name **Ciya** came from the word `Siya`, which means he/she in filipino/tagalog language, 
We want `Ciya` to be a bigger leap than its successor, `CRy-VM`.
We expect that it is mostly written in the
[C Programming Language](https://en.wikipedia.org/wiki/C_(programming_language)).

For now, we're still in development,
but if you have any ideas to share, we'll try our best to achieve them.

## Wanna collaborate?
Feel free to collaborate on this project, but you MUST follow the license and policy

## Policy(Rules):
+ You should never swear at or intimidate others in any part of the software, not even on PRs.
+ Must not make a single thing in the project dependent on only
 1 operating system
feature that leads to it not being cross-platform
+ Please report to us when there's any problem:
    No spambots must get through! No email is posted. 
    * Contributor note: I risked it; here's my email: phuocthanhlamnguyen@gmail.com
    * GitHub issues (more preferred)

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

## How to install the packages:
<img width="480" height="360" alt="image" src="https://github.com/user-attachments/assets/b6a2cff3-7c81-464c-9775-82c822137046" />

To install the Linux or BSD packages, you need to first have `wget` for this; most mainstream Linux distros or heavy-duty distros come with it
But to check if you have it, here's the command:

```bash
wget --version
```

If it says a version like `1.21.4`, then great! Else, here's the command to install it:

On Debian:
```bash
sudo apt install wget -y 
```

On Red Hat:
```bash
sudo dnf install wget -y # On RHEL 8 to RHEL 9
sudo yum install wget -y # on older versions of RHEL
```

On Arch Linux:
```bash
sudo pacman -Syu wget
```

On Alpine Linux:
```bash
sudo apk add wget
```

On FreeBSD:
```bash
pkg install wget
```

After you have wget, you can now get the package you need by typing the command:

```bash
wget -O <binary name> <binary link>
```

After that, you can install in different ways, but generally, you'll get the .tar.gz or the package; I recommend the tar.gz one, like this:

```bash
wget -O ciya-linux.tar.gz https://github.com/Ciya-VM/Ciya/raw/main/package/tarball/ciya-linux.tar.gz # First, get the file
tar -xzvf ciya-linux.tar.gz # Second, extract the file
chrom +x <binary file> # To handle the premission
./<binary file> # run it!
```

But there are *different ways* to install the packages, and it depends on what fits you!

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
