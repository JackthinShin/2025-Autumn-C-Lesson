CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm

# 源文件
SOURCES = main.c utils.c preprocess.c tokenize.c similarity.c evaluate.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = similarity_detection

# 默认目标
all: $(TARGET)

# 链接目标文件
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# 编译源文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(OBJECTS) $(TARGET)

# 运行测试
test: $(TARGET)
	./$(TARGET) test_data/code1.c test_data/code2.c

.PHONY: all clean test

