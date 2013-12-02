#!/bin/sh
### BEGIN INIT INFO
# Provides: banner
# Required-Start:
# Required-Stop:
# Default-Start:     S
# Default-Stop:
### END INIT INFO

# abuse for creating the ttyS1 symlink
ln -s tts/1 /dev/ttyS1
vtmaster=/dev/console
echo > $vtmaster
echo "Please wait: booting..." > $vtmaster
