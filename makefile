all: p1 p2 p3

p1: terminalSimulator.c
	gcc terminalSimulator.c pathBuilder.c parser.c internalCommands/cd.c -o terminalSimulator -ledit

p2: internalCommands/uniq.c
	gcc internalCommands/uniq.c -o internalCommands/uniq

p3: internalCommands/tail.c
	gcc internalCommands/tail.c -o internalCommands/tail
