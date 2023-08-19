# Makefile-template

Template repository to build a set of applications and dependencies with makefile in C

## Structure

- [apps](./apps): Application directory (e.g.: creating a postfix evaluator)
  - [mk](./apps/mk): Directory containing all custom makefile (e.g.: `postfix.mk` which takes care of telling makefile to compile `apps_targets` with `postfix`)
- [bin](./bin): Binaries directory, after `make all` or `make bin` an archive will be created that includes all `src` code
  - [mk](./bin/mk): Makefile directory to extend binaries
- [include](./include): Headers directory, this directory is meant for **public headers** and public headers only
- [src](./src): Source directory, use this directory for structures codes or private implementations (e.g.: stack implementation and its own private header). All this code will be compiled and sent to bin `libcompiled.a`
- [test](./test): Test directory, this directory is meant for tests code

## Suggest an improvement

Feel free to suggest new features [here](https://github.com/Ziocash/Makefile-template/issues/new)
