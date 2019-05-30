#!/bin/bash

# Script from https://dwm.suckless.org/status_monitor

## CHANGE /home TO YOUR DRIVE

df -h | awk '{ if ($6 == "/home") print $4 }'

