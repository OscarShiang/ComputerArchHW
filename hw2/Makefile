TARGET = sqrt
OBJS = sqrt.o utils/print.o utils/math.o

CC = riscv-none-embed-gcc
CFLAGS = -std=gnu11 -march=rv32i -mabi=ilp32 -nostdlib -I./include

include common.mk

all: $(TARGET)
.PHONY: all

$(TARGET): $(OBJS)
	$(VECHO) "   LD\t$@\n"	
	$(Q)$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(VECHO) "   CC\t$@\n"	
	$(Q)$(CC) -c $^ -o $@ $(CFLAGS)

format:
	$(Q)clang-format -i *.c utils/*.c include/*.h
.PHONY: format

clean:
	$(Q)$(RM) $(TARGET) $(OBJS)
.PHONY: clean
