states.exe: state_facts.o run_facts.o
	g++ state_facts.o run_facts.o -o states.exe
state_facts:
	g++ -c state_facts.cpp
run_facts:
	g++ -c run_facts.cpp
	
clean:
	rm -f *.o *.out *.exe
