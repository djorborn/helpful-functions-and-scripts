# Helper Functions And Scripts

This is a repositry of helpful functions in C and Bourne Shell Script. 

### get-battery
Both shell and C do pretty much the same thing. Output the current battery percent and `=` for Full `-` for dischrging and `+` for charging.
The result is printed to stdout.
Orignal source for C is from [suckless](https://dwm.suckless.org/status_monitor/batterystatus.c) and the script is from [oh-my-zsh/plugin/battery](https://github.com/robbyrussell/oh-my-zsh/tree/master/plugins/battery). 
### arrow-hoome-and-end-keys.sh
This is a shell script that catches the UP, DOWN, LEFT and RIGHT arrow keys as well as HOME and END keys. 
It uses a trick to catch multi digit keys and works for most terminals.
Orignal code source from [stackoverflow](https://stackoverflow.com/questions/10679188/casing-arrow-keys-in-bash/56200043#56200043)

### dwm_status
This along with `start_dwm_status` are the script I use to show system stats in dwm. 

## Contribute
Please feel free to make a pull request if you feel like you have something that should be here. 

### License
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
