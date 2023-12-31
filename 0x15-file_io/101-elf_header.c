#include "main.h"
#include <fcntl.h>
#include <elf.h>
/*void check_if_elf(unsigned char *elf_ident);
void print_magic_num(unsigned char *elf_ident);
void print_elf_class(unsigned char *elf_ident);
void print_header(unsigned char *elf_ident);
void print_header_version(unsigned char *elf_ident);
void print_abi_version(unsigned char *elf_ident);
void print_osabi_str(unsigned char *elf_ident);
void print_elf_type(unsigned int elf_type, unsigned char *elf_ident);
void print_header_entry(unsigned long int elf_entry, unsigned char *elf_ident);
void close_elf(int elf);*/

/**
 * check_if_elf - Checks if a file is an ELF file.
 * @elf_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Return: If the file is not an ELF file - exit code 98.
 */
void check_if_elf(unsigned char *elf_ident)
{
int i;
for (i = 0; i < 4; i++)
{
if (elf_ident[i] != 127 &&
elf_ident[i] != 'E' &&
elf_ident[i] != 'L' &&
elf_ident[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * print_magic_num - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 * Return: Void
 */
void print_magic_num(unsigned char *elf_ident)
{
int i;
printf("  Magic:   ");

for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", elf_ident[i]);
if (i == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
 * print_elf_class - Prints the class of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF class.
 *Return: void
 */
void print_elf_class(unsigned char *elf_ident)
{
printf("  Class:                             ");
switch (elf_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
}
}

/**
 * print_header - Prints the data of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF class.
 * Return: Void
 */
void print_header(unsigned char *elf_ident)
{
printf("  Data:                              ");

switch (elf_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
}
}

/**
 * print_header_version - Prints the version of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF version.
 * Return: void
 */
void print_header_version(unsigned char *elf_ident)
{
printf("  Version:                           %d",
elf_ident[EI_VERSION]);
switch (elf_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
 * print_osabi_str - Prints the OS/ABI of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF version.
Return: void
 */
void print_osabi_str(unsigned char *elf_ident)
{
printf("  OS/ABI:                            ");
switch (elf_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF ABI version.
 * Return: void
 */
void print_abi_version(unsigned char *elf_ident)
{
printf("  ABI Version:                       %d\n",
elf_ident[EI_ABIVERSION]);
}

/**
 * print_elf_type - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf_ident: A pointer to an array containing the ELF class.
 * Return: void
 */
void print_elf_type(unsigned int elf_type, unsigned char *elf_ident)
{
if (elf_ident[EI_DATA] == ELFDATA2MSB)
elf_type >>= 8;
printf("  Type:                              ");
switch (elf_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", elf_type);
}
}

/**
 * print_header_entry - Prints the entry point of an ELF header.
 * @elf_entry: The address of the ELF entry point.
 * @elf_ident: A pointer to an array containing the ELF class.
 * Return: void
 */
void print_header_entry(unsigned long int elf_entry, unsigned char *elf_ident)
{
printf("  Entry point address:               ");
if (elf_ident[EI_DATA] == ELFDATA2MSB)
{
elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
((elf_entry >> 8) & 0xFF00FF);
elf_entry = (elf_entry << 16) | (elf_entry >> 16);
}
if (elf_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)elf_entry);
else
printf("%#lx\n", elf_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", elf);
exit(98);
}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *header;
    int o, r;
    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        close_elf(o);
        dprintf(STDERR_FILENO, "Error: Can't allocate memory for ELF header\n");
        exit(98);
    }
    r = read(o, header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        free(header);
        close_elf(o);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }
    check_if_elf(header->e_ident);
    printf("ELF Header:\n");
    print_magic_num(header->e_ident);
    print_elf_class(header->e_ident);
    print_header(header->e_ident);
    print_header_version(header->e_ident);
    print_abi_version(header->e_ident);
    print_osabi_str(header->e_ident);
    print_elf_type(header->e_type, header->e_ident);
    print_header_entry(header->e_entry, header->e_ident);
    free(header);
    close_elf(o);
    return (0);
}

