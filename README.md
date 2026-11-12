# Pokémon Super Emerald

A ROM hack built on [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) 1.17.2. It plays the story of Pokémon Emerald in Hoenn with Omega Ruby / Alpha Sapphire data, then opens Kanto, in its HeartGold / SoulSilver era, and the Sevii Islands as postgame.

## The game

**Hoenn (main story)**
- The Emerald story, with Team Magma and Team Aqua, in FireRed-style graphics.
- Wild Pokémon, levels and trainer teams from Omega Ruby and Alpha Sapphire (both versions).
- Wallace is the Sootopolis Gym Leader, Steven is the Champion and Juan is a Contest coordinator in Lilycove.
- Steven gives the Mega Ring outside the Petalburg Gym after you beat Norman.

**Hoenn postgame**
- Gym Leader rematches up to level 75, Wally rematches, and an Elite Four and Steven rematch with ORAS teams.
- Prof. Birch gives a Johto starter (level 45, holding an Everstone) and the Kanto Ticket.
- Event tickets from your rival, Mr. Briney, Prof. Cozmo and Wally; every legendary is at level 75.

**Kanto (HeartGold / SoulSilver era)**
- The ferry from Slateport or Lilycove goes to Vermilion City. Prof. Oak meets you at the dock with a Kanto starter and the Rainbow Pass.
- There is no Team Rocket. Kanto is already in its post-story state.
- Leaders in the HGSS order: Blue leads Viridian and Janine leads Fuchsia. The Elite Four are Koga, Bruno, Karen and Lance, and Red is the silent Champion.
- HGSS wild Pokémon by time of day, and HGSS trainers in the Fire Red trainer spots, all on a postgame level curve.
- After Red: a Sinnoh starter and the Shiny Charm from Oak, leader rematches and an Elite Four rematch.

**Sevii Islands**
- Open as soon as you arrive in Kanto. The Bill and Celio story is already over, so the islands are for exploring: Trainer Tower, Lost Cave, the Rocket Warehouse and the legendaries.

## Building

Follow [INSTALL.md](INSTALL.md), then run `make`. The ROM is `pokeemerald.gba`.

The data generators live in `tools/sfr/` (see each script's header).

---

# About `pokeemerald-expansion`

![Gif that shows debugging functionality that is unique to pokeemerald-expansion such as rerolling Trainer ID, Cheat Start, PC from Debug Menu, Debug PC Fill, Pokémon Sprite Visualizer, Debug Warp to Map, and Battle Debug Menu](https://github.com/user-attachments/assets/cf9dfbee-4c6b-4bca-8e0a-07f116ef891c) ![Gif that shows overworld functionality that is unique to pokeemerald-expansion such as indoor running, BW2 style map popups, overworld followers, DNA Splicers, Gen 1 style fishing, OW Item descriptions, Quick Run from Battle, Use Last Ball, Wild Double Battles, and Catch from EXP](https://github.com/user-attachments/assets/383af243-0904-4d41-bced-721492fbc48e) ![Gif that shows off a number of modern Pokémon battle mechanics happening in the pokeemerald-expansion engine: 2 vs 1 battles, modern Pokémon, items, moves, abilities, fully customizable opponents and partners, Trainer Slides, and generational gimmicks](https://github.com/user-attachments/assets/50c576bc-415e-4d66-a38f-ad712f3316be)

<!-- If you want to re-record or change these gifs, here are some notes that I used: https://files.catbox.moe/05001g.md -->

**`pokeemerald-expansion`** is a GBA ROM hack base that equips developers with a comprehensive toolkit for creating Pokémon ROM hacks. **`pokeemerald-expansion`** is built on top of [pret's `pokeemerald`](https://github.com/pret/pokeemerald) decompilation project. **It is not a playable Pokémon game on its own.**

# [Features](FEATURES.md)

**`pokeemerald-expansion`** offers hundreds of features from various [core series Pokémon games](https://bulbapedia.bulbagarden.net/wiki/Core_series), along with popular quality-of-life enhancements designed to streamline development and improve the player experience. A full list of those features can be found in [`FEATURES.md`](FEATURES.md).

# [Credits](CREDITS.md)

 [![](https://img.shields.io/github/all-contributors/rh-hideout/pokeemerald-expansion/upcoming)](CREDITS.md)

If you use **`pokeemerald-expansion`**, please credit **RHH (Rom Hacking Hideout)**. Optionally, include the version number for clarity.

```
Based off RHH's pokeemerald-expansion 1.17.2 https://github.com/rh-hideout/pokeemerald-expansion/
```

Please consider [crediting all contributors](CREDITS.md) involved in the project!

# Choosing `pokeemerald` or **`pokeemerald-expansion`**

- **`pokeemerald-expansion`** supports multiplayer functionality with other games built on **`pokeemerald-expansion`**. It is not compatible with official Pokémon games.
- If compatibility with official games is important, use [`pokeemerald`](https://github.com/pret/pokeemerald). Otherwise, we recommend using **`pokeemerald-expansion`**.
- **`pokeemerald-expansion`** incorporates regular updates from `pokeemerald`, including bug fixes and documentation improvements.

# [Getting Started](INSTALL.md)

❗❗ **Important**: Do not use GitHub's "Download Zip" option as it will not include commit history. This is necessary if you want to update or merge other feature branches.

If you're new to git and GitHub, [Team Aqua's Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/) has a [guide to forking and cloning the repository](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/The-Basics-of-GitHub). Then you can follow one of the following guides:

## 📥 [Installing **`pokeemerald-expansion`**](INSTALL.md)
## 🏗️ [Building **`pokeemerald-expansion`**](INSTALL.md#Building-pokeemerald-expansion)
## 🚚 [Migrating from **`pokeemerald`**](INSTALL.md#Migrating-from-pokeemerald)
## 🚀 [Updating **`pokeemerald-expansion`**](INSTALL.md#Updating-pokeemerald-expansion)

# [Documentation](https://rh-hideout.github.io/pokeemerald-expansion/)

For detailed documentation, visit the [pokeemerald-expansion documentation page](https://rh-hideout.github.io/pokeemerald-expansion/).

# [Contributions](CONTRIBUTING.md)
If you are looking to [report a bug](CONTRIBUTING.md#Bug-Report), [open a pull request](CONTRIBUTING.md#Pull-Requests), or [request a feature](CONTRIBUTING.md#Feature-Request), our [`CONTRIBUTING.md`](CONTRIBUTING.md) has guides for each.

# [Community](https://discord.gg/6CzjAG6GZk)

[![](https://dcbadge.limes.pink/api/server/6CzjAG6GZk)](https://discord.gg/6CzjAG6GZk)

Our community uses the [ROM Hacking Hideout (RHH) Discord server](https://discord.gg/6CzjAG6GZk) to communicate and organize. Most of our discussions take place there, and we welcome anybody to join us!
