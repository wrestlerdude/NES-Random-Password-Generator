# NES-Random-Password-Generator
Randomly generates passwords for various NES games.
Requires make and gcc. Tested on Linux + Windows.

Compile by running `make build`
and run with `./generate.exe <game_name>`

List of games supported so far:
- Metroid (1986)

## Warning
This program is intended for "random" runs of games or to create glitches. For certain games this may corrupt save files, and will likely if not most of the time crash and reset the game due to invalid op codes being ran (if this happens just try more passwords); this is because the randomn generation does not care what parts of the password mean what, it's literally just random values formatted as a password. I may develop a safe mode where the password always enters a valid game in the future.
