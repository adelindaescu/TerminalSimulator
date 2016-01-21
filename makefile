all: p1 p2 p3 p4

p1: internalCommands/hello.c
	gcc internalCommands/hello.c -o internalCommands/hello

p2: terminalSimulator.c
	gcc terminalSimulator.c pathBuilder.c parser.c internalCommands/cd.c -o terminalSimulator -ledit
p3: internalCommands/uniq.c
	gcc internalCommands/uniq.c -o internalCommands/uniq

p4: internalCommands/tail.c
	gcc internalCommands/tail.c -o internalCommands/tail
