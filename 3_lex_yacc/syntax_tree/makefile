CC=gcc
TARGET= main
LEXER= lex
TESTFILE=test.cpp
all: $(TARGET) lex


lex_test: lex
	./$(LEXER) < $(TESTFILE)

$(LEXER): lex_only.yy.c main.c
	$(CC) -o $@  $^ -DLEX

syn_test: $(TARGET) $(TESTFILE)
	./$(TARGET) < $(TESTFILE)

$(TARGET): main.c syn_tree.tab.c lex.yy.c syn_tree.c 

syn_tree.tab.c:syn_tree.y
	bison -d  $<

lex_only.yy.c: lex_only.l
	flex -o $@ $< 

lex.yy.c: lexer.l
	flex $< 

clean:
	rm syn_tree.tab.c *.yy.c syn_tree.tab.h $(LEXER) $(TARGET) 2> /dev/null || echo > /dev/null
