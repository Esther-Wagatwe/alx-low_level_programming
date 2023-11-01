#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> 
#include <elf.h>
#define BUFFER_SIZE 1024

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int stringLength(const char *str);
int copyFile(const char *srcFilename, const char *destFilename);
void err(int code, const char *err_message, const char *file);
void err_exit(const char *msg, const char *file);
const char *elf_class_str(unsigned char elf_class);
const char *elf_abi_version_str(unsigned char osabi);
const char *elf_type_str(Elf64_Half type);
void elf_header(const char *file);
int elf_file(int fd);
#endif
