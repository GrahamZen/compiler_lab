CXX=g++
TARGET= main
LEXER= lex
TESTFILE=test.cpp
all: $(TARGET) lex


lex_test: lex
	./$(LEXER) < $(TESTFILE)

$(LEXER): lex_only.yy.c main.cpp
	$(CXX) -o $@  $^ -DLEX

syn_test: $(TARGET) $(TESTFILE)
	./$(TARGET) < $(TESTFILE)

$(TARGET): main.cpp syn_tree.tab.c lex.yy.c syn_tree.c 

syn_tree.tab.c:syn_tree.y
	bison -d  $<

lex_only.yy.c: lex_only.l
	flex -o $@ $< 

lex.yy.c: lexer.l
	flex $< 

check:$(TARGET)
	valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--verbose \
			--log-file=valgrind-out.txt \
			./$(TARGET)<$(TESTFILE)

clean_temps:
	rm valgrind-out.txt *.log *.tab.c *.yy.c *.tab.h  2> /dev/null || echo > /dev/null

clean: clean_temps
	rm $(LEXER) $(TARGET) 2> /dev/null || echo > /dev/null
