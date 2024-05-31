# Компилятор
CXX = g++
# Флаги компиляции
CXXFLAGS = -Wall -g

# Цель по умолчанию
all: program1 program2

# Правила для сборки program1
program1: program1.o
	$(CXX) $(CXXFLAGS) -o program1 program1.o

# Правила для сборки program2
program2: program2.o
	$(CXX) $(CXXFLAGS) -o program2 program2.o

# Правила для сборки объектного файла из program1.cpp
program1.o: program1.cpp
	$(CXX) $(CXXFLAGS) -c program1.cpp

# Правила для сборки объектного файла из program2.cpp
program2.o: program2.cpp
	$(CXX) $(CXXFLAGS) -c program2.cpp

# Очистка сгенерированных файлов
clean:
	rm -f program1 program2 *.o

# Фиктивная цель для предотвращения конфликтов с файлами
.PHONY: all clean
