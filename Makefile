#
# Basic make file to create the bud_get executable
# See https://makefiletutorial.com/ and https://www.gnu.org/software/make/manual/make.html
#


# It is likely that default C compiler is already gcc, but explicitly
# set, just to be sure
CC := gcc
# The CFLAGS variable sets compile flags for gcc:
#  -g        compile with debug information
#  -Wall     give verbose compiler warnings
#  -O0       do not optimize generated code
#  -std=c99  use the C99 standard language definition
CFLAGS := -g -Wall -O0 -std=c99

# The LDFLAGS variable sets flags for linker
#  -lm   says to link in libm (the math library)
# LDFLAGS = -lm

# target
TARGET_EXEC := bud_get

# Directory variables
SRC_DIR := src
BIN_DIR := bin

# run all
all: dir bud_get

# create bin dir if necessary
dir:
	mkdir -p $(BIN_DIR)

bud_get: $(SRC_DIR)/bud_get.c
	$(CC) $(CFLAGS) $(SRC_DIR)/bud_get.c -o $(BIN_DIR)/$(TARGET_EXEC)

# Phony means not a "real" target, it doesn't build anything
# The phony target "clean" is used to remove all compiled object files.
.PHONY: clean
clean:
	rm -r $(BIN_DIR)