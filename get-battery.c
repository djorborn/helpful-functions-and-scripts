/* get-battery - print battery status and percent to stdout
 * 
 * Original Source from http://dwm.suckless.org/status_monitor/batterystatus.c
 * edited by djorborn at gmail dot com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#define BATT_NOW "/sys/class/power_supply/BAT0/charge_now"
#define BATT_FULL "/sys/class/power_supply/BAT0/charge_full"
#define BATT_STATUS "/sys/class/power_supply/BAT0/status"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *
smprintf(char *fmt, ...)
{
	va_list fmtargs;
	char *buf = NULL;

	va_start(fmtargs, fmt);
	if (vasprintf(&buf, fmt, fmtargs) == -1)
	{
		fprintf(stderr, "malloc vasprintf\n");
		exit(1);
	}
	va_end(fmtargs);

	return buf;
}

char *
getbattery()
{
	long lnum1, lnum2 = 0;
	char *status = malloc(sizeof(char) * 12);
	char s = '?';
	FILE *fp = NULL;
	if ((fp = fopen(BATT_NOW, "r")))
	{
		fscanf(fp, "%ld\n", &lnum1);
		fclose(fp);
		fp = fopen(BATT_FULL, "r");
		fscanf(fp, "%ld\n", &lnum2);
		fclose(fp);
		fp = fopen(BATT_STATUS, "r");
		fscanf(fp, "%s\n", status);
		fclose(fp);
		if (strcmp(status, "Charging") == 0)
			s = '+';
		if (strcmp(status, "Discharging") == 0)
			s = '-';
		if (strcmp(status, "Full") == 0)
			s = '=';
		return smprintf("%c%ld%%", s, (lnum1 / (lnum2 / 100)));
	}
	else
		return smprintf("");
}

int main(void)
{
	printf("%s\n", getbattery());
	return 0;
}