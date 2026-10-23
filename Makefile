# EoW Recomp build: the shared runtime (../../nxrt, nxrt.mk) + Echoes of Wisdom's own sources (runtime/).
# macOS: Homebrew clang/SDL3/FFmpeg, Metal renderer. Windows / Linux: clang + Vulkan renderer.
NXRT     := nxrt
GAME_ID  := eow
GAME_EXE := eowrecomp
GAME_SRC := $(wildcard runtime/*.c) $(wildcard runtime/ui/*.mm)
# the four code modules of Echoes of Wisdom 1.0.0, as nx_game.info.modules (runtime/eow_game.c), in rtld's order
GAME_MODULES := main:0x7000000000 subsdk0:0x7008000000 subsdk1:0x700A000000 sdk:0x700C000000

include $(NXRT)/nxrt.mk
