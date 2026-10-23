// EoW Recomp on the shared runtime (nxrt): who the game is - The Legend of Zelda: Echoes of Wisdom 1.0.0, four code
// modules - and its hooks. Upstream EoWRecomp is at its first milestones (the game boots and renders its opening
// scene): no game pages, no widescreen yet (the image stays 16:9, boxed), no patches for the recompiler
// (tools/patches.py is empty).
#include "nxgame.h"

// The release tag this build is: alpha_<n> while the game isn't playable, beta_<n> until 1.0, then v<major>.<minor>.<patch>.
#define EOW_VERSION "alpha_1"

const NxGame nx_game = {
    .info = {
        .id = "eow",
        .exe = "eowrecomp",
        .title = "EoW Recomp",
        .game_name = "The Legend of Zelda: Echoes of Wisdom",
        .game_version = "1.0.0",
        .title_id = 0x01008CF01BAAC000ull,
        .build_id = {0xa5, 0x81, 0x40, 0x6b, 0xc9, 0x85, 0x86, 0x51},
        .bundle_id = "com.eowrecomp.eowrecomp",
        .data_dir = "eowrecomp",
        .ini = "eowrecomp.ini",
        .version = EOW_VERSION,
        .releases_api = "https://api.github.com/repos/Nycolazs/EoWRecomp/releases",
        .release_page = "https://github.com/Nycolazs/EoWRecomp/releases/tag/",
        .headline = "EoW Recomp",
        .romfs_probe = "region_common",
        .title_movie = "region_common/movie/title.webm",
        .menu_name = "Echoes of Wisdom",
        // Horizon's rtld order (main, subsdk*, sdk): also the symbol lookup order. main's image is 0x4004000 bytes,
        // so it gets 128 MB; the others 32 MB each (the loader checks they fit).
        .modules = {{"main", 0x7000000000ull}, {"subsdk0", 0x7008000000ull}, {"subsdk1", 0x700A000000ull},
                    {"sdk", 0x700C000000ull}},
    },
    .hooks = {
        .late_module_init = true,  // (the other modules' constructors use the SDK's heap: after nn::init's first step)
    },
};
