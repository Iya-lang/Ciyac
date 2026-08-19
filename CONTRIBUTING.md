# Contributing to Ciya
## Found a bug?
1) Report it immediately to GitHub issues or email without sending it to my main email; use the contributor's email instead (phuocthanhlamnguyen@gmail.com).
2) Minimize duplicate issues. If the problem was already reported, make sure that you minimize these. You could find related issues by scrolling in the issues section in GitHub.
3) When posting issues, make sure to put a title and description, and if possible, add a screenshot or image of the bug.

## Did you fix a bug? Made more features?
1) Open a new GitHub pull request.
2) Ensure that the pull request has a clear problem and its solution or added feature.

## Make sure to make the project stay...
* **cross-platform**; it doesn't mean that you have to include every single existing hardware, but have support for the common daily programming hardware (Windows, Linux, and Mac)
* **exactly 2-spaced indented in source code** or it won't be accepted.
* **make the repo clean**; Do not show any binaries/packages on the repo; show it in GitHub releases.
* **clean**; Do not ever litter the repo with binary files; repo=source code, not binary dumps.

## How do you compile the project?
To compile it, make sure that you at least have the first 3 tools listed:
1) CMAKE
2) Make, Ninja, etc.
3) GCC
4) GDB
5) VALGRIND

Then you run the series of commands:

```bash
$ cmake -B build # Prepares the build folder
```

```bash
$ cmake --build build # Compiles the project
```

```bash
$ ./build/ciya # Runs the executable (this may behave differently on Windows)
```

## Is the Wiki outdated?
If you see the wiki is outdated or factually wrong, please let us know by using **GitHub issues** 
or email the contributor (phuocthanhlamnguyen@gmail.com). We'll reply and actively fix it
within a span of a few minutes to days. But please let us know =)
___
**That's all, thank you and god bless,**

The Ciya Organization
