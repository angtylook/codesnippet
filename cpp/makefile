LINK_PATH=/Users/z/dev/lib
INCLUDE_PATH=/Users/z/dev/include
OUT_PATH=/Users/z/dev/bin

CC=clang
LIB=apue
TARGET=print_tid
SRC=print_thread_id.c

$(TARGET):$(SRC) 
	$(CC) $(SRC) -I$(INCLUDE_PATH) -L$(LINK_PATH) -l$(LIB) -o $(OUT_PATH)/$(TARGET)

run:
	$(OUT_PATH)/$(TARGET)

clean:
	rm $(OUT_PATH)/$(TARGET) ./*.o $(OUT_PATH)/*.o
