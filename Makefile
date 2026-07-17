CC = gcc
CCFLAGS = -O2 -s -fno-stack-protector -fomit-frame-pointer -fno-unwind-tables -std=c99 -fdata-sections -ffunction-sections -flto -fno-math-errno -fmerge-all-constants
LDFLAGS = -Wl,--gc-sections -Wl,--strip-all -Wl,--no-undefined
CFILES = src/main.c src/func.c
NAME = zrtxt
PACK = upx
PACK_FLAGS = --best
$(NAME): $(CFILES)
	$(CC) $(CFILES) $(CCFLAGS) $(LDFLAGS) -o $(NAME)
	$(PACK) $(PACK_FLAGS) $(NAME)
clean:
	rm -rf $(NAME)
install:
	cp $(NAME) /usr/local/bin/$(NAME)
remove:
	rm -rf /usr/local/bin/$(NAME)
