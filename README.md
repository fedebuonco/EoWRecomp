# EoW Recomp

A native recompilation of *The Legend of Zelda: Echoes of Wisdom* (Switch), built on
[nxrt](https://github.com/fedebuonco/nxrt): the runtime, recompiler, renderers, kernel, HLE services and app shell
come from the `nxrt` submodule. This repository holds only what is Echoes of Wisdom's own: its identity and hooks
(`runtime/`), and the per-instruction patches its recompilation needs (`tools/patches.py`).

## Building

macOS: Homebrew clang, SDL3 and FFmpeg. `git clone --recursive`, then `make`. The game's code is generated from
your own game files by `nxrt/tools/gen.py` (the start screen's Game Files setup does it), never shipped here.

## Game files

The app reads the game from a folder you choose on its start screen: `exefs/` plus either a `romfs/` folder or a
`romfs.src` package image. No game files, fonts or keys are included.

Based on [nxrt](https://github.com/fedebuonco/nxrt) and LASRecomp's shared runtime (MIT).
