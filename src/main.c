#include "func.h"
#include <string.h>
#include <stdlib.h>
void optcheck(int argc, int argcnum) { int arg = argc - 1; if (arg < argcnum) { print("Too few arguments\n"); exit(1); } if (arg > argcnum) { print("Too many arguments\n"); exit(1); } }
int main(int argc, char* argv[]) {
	if (argc < 2) { print("Too few arguments\n"); exit(1); }
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) { optcheck(argc, 1); help(); }
        else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) { optcheck(argc, 1); ver(); }
        else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--write") == 0) { optcheck(argc, 3); wrt(argv[2]); }
        else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--read") == 0) { optcheck(argc, 3); readf(argv[2]); }
        else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--clean") == 0) { optcheck(argc, 3); clr(argv[2]); }
        else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--search") == 0) { optcheck(argc, 4); srch(argv[2], argv[3]); }
        else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--new") == 0) { optcheck(argc, 3); create(argv[2]); }
        else { print("Unknown option "); print(argv[1]); print("\n"); help(); return 1; }
    }
}
