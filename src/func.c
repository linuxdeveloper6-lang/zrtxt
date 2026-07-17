#include "func.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define MAJOR "1"
#define MINOR "2"
#define PATCH "0"
void print(const char* txt) { write(1, txt, strlen(txt)); }
void fdch(int fd, const char *file) { if (fd < 0) { print("Cannot open file "); print("'"); print(file); print("'"); print("\n"); exit(1); } }
void ver() { print("zrtxt "); print(MAJOR); print("."); print(MINOR); print("."); print(PATCH); print("\n"); }
void readf(const char *readfile) { ssize_t bytes; int fd = open(readfile, O_RDONLY); fdch(fd, readfile); char buffer[16384]; while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) { write(1, buffer, bytes); } buffer[bytes] = '\0'; print("\n"); close(fd); }
void fwrt(const char *file, const char *text) { int fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644); fdch(fd, file); off_t filesize = lseek(fd, 0, SEEK_END); char buffer[16384]; write(fd, "\n", 1); write(fd, text, strlen(text)); close(fd); print("Done. Written to a file "); print("'"); print(file); print("'"); print("\n"); }
void wrt(const char *file) { int fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644); fdch(fd, file); char buffer[16384]; while (1) { ssize_t bytes = read(0, buffer, sizeof(buffer)); buffer[bytes] = '\0'; if (bytes > 0) { write(fd, buffer, bytes); } if (bytes <= 0) { print("\n"); print("Done. Written to a file "); print("'"); print(file); print("'"); print("\n"); close(fd); return; } } }
void clr(const char *file) { int fd = open(file, O_WRONLY | O_TRUNC, 0644); fdch(fd, file); print("Done. File "); print("'"); print(file); print("'"); print(" erased.\n"); close(fd); }
void srch(const char *file, const char *text) { char *found; int fd = open(file, O_RDONLY); fdch(fd, file); char buffer[16384]; ssize_t bytes; while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) { found = strstr(buffer, text); }; buffer[bytes] = '\0'; if (!found) { print("Cannot find string "); print(text); print("\n"); close(fd); return; } char *endline = strchr(found, '\n'); if (endline) *endline = '\0'; print(found);  print("\n"); close(fd); }
void help() { print("Usage: zrtxt [option] [argument]\n"); print("-h --help                   Show help and exit\n"); print("-v --version                Show version and exit\n"); print("-w --write                  Write file\n"); print("-r --read                   Read file\n"); print("-c --clean                  Clean file\n"); print("-s --search                 Search text\n"); print("-f --fastwrite              Fast write\n"); print("-n --newfile                Create new file\n"); }
void create(const char *file) { int fd = open(file, O_RDONLY | O_CREAT, 0644); close(fd); };
