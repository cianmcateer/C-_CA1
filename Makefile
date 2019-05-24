output.o: main.o Student.o Student_Store.o util.o
	g++ -std=c++11 main.o Student.o Student_Store.o util.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Student.o: Student.h
	g++ -std=c++11 -c Student.cpp

Student_Store.o: Student_Store.h
	g++ -std=c++11 -c Student_Store.cpp

util.o: util.h
	g++ -std=c++11 -c util.cpp

clean:
	rm *.o output
