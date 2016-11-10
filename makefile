compile: signals.c
	gcc signals.c -o signals

clean:
	rm *~ *# signals

run: signals
	./signals
