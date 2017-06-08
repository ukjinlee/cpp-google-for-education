CC = g++
CFLAGS = -std=c++0x -Wall

composer: composer.cpp test_composer.cpp
	$(CC) $(CFLAGS) -o $@ $^

composer.o: composer.cpp
	$(CC) $(CFLAGS) -c composer.cpp

database.o: database.cpp
	$(CC) $(CFLAGS) -c database.cpp

database: composer.o database.o test_database.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o composer database

