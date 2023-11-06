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
void check_if_elf(unsigned char *elf_ident);
void print_magic_num(unsigned char *elf_ident);
void print_elf_class(unsigned char *elf_ident);
void print_header(unsigned char *elf_ident);
void print_header_version(unsigned char *elf_ident);
void print_abi_version(unsigned char *elf_ident);
void print_osabi_str(unsigned char *elf_ident);
void print_elf_type(unsigned int elf_type, unsigned char *elf_ident);
void print_header_entry(unsigned long int elf_entry, unsigned char *elf_ident);
void close_elf(int elf);
#endif
