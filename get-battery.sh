#!/bin/sh

FULL=$(acpi 2>/dev/null | grep -c '^Battery.*Full')
DISCHARGING=$(acpi 2>/dev/null | grep -c '^Battery.*Discharging')
PERCENT=$(acpi 2>/dev/null | cut -f2 -d ',' | tr -cd '[:digit:]')

if [[  $FULL -gt 0 ]]; then
	BATT="=$PERCENT"
elif [[ $DISCHARGING -gt 0 ]]; then
	BATT="-$PERCENT"
else
	BATT="+$PERCENT"
fi

echo $BATT
