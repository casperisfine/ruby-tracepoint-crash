require 'mkmf'

$CFLAGS = "-O3 -Wall"

create_makefile('tracepoint_crash/tracepoint_crash')
