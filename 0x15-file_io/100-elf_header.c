#include "main.h"

/**
 * err_exit - print error message and exit with status code 98
 * @msg: error message to print
 * @file: path to file
 *
 * Return: void
 */
void err_exit(const char *msg, const char *file)
{
    dprintf(STDERR_FILENO, msg, file);
    exit(98);
}

/**
 * elf_class_str - get string representation of ELF class
 * @class: character to use to get class
 *
 * Return: string representation of the class
 */
const char *elf_class_str(unsigned char elf_class)
{
    switch (elf_class)
    {
        case ELFCLASSNONE:
            return ("none");
        case ELFCLASS32:
            return ("ELF32");
        case ELFCLASS64:
            return ("ELF64");
        default:
            return ("unknown");
    }
}

/**
 * elf_data_str - get string representation of data format (Endianness)
 * @data: character to use to check endianness
 *
 * Return: string representation of endianness
 */
const char *elf_data_str(unsigned char data)
{
    switch (data)
    {
        case ELFDATA2LSB:
            return ("2's complement, little endian");
        case ELFDATA2MSB:
            return ("2's complement, big endian");
        default:
            return ("unknown");
    }
}

/**
 * elf_abi_version_str - get string representation of OS/ABI version
 * @osabi: the osabi value to use
 *
 * Return: string representation of the osabi value
 */
const char *elf_abi_version_str(unsigned char osabi)
{
    switch (osabi)
    {
        case ELFOSABI_SYSV:
            return ("UNIX - System V");
        case ELFOSABI_HPUX:
            return ("UNIX - HP-UX");
        case ELFOSABI_NETBSD:
            return ("UNIX - NetBSD");
        case ELFOSABI_LINUX:
            return ("UNIX - Linux");
        case ELFOSABI_SOLARIS:
            return ("UNIX - Solaris");
        case ELFOSABI_AIX:
            return ("AIX");
        case ELFOSABI_FREEBSD:
            return ("UNIX - FreeBSD");
        case ELFOSABI_TRU64:
            return ("UNIX - Tru64");
        case ELFOSABI_MODESTO:
            return ("Novell Modesto");
        case ELFOSABI_OPENBSD:
            return ("OpenBSD");
        case ELFOSABI_ARM:
            return ("ARM");
        case ELFOSABI_IRIX:
            return ("UNIX - IRIX");
        case ELFOSABI_ARM_AEABI:
            return ("ARM AEABI");
        case ELFOSABI_STANDALONE:
            return ("Standalone App");
        default:
            return ("unknown");
    }
}

/**
 * elf_type_str - get string representation of e_type
 * @type: e_type to use
 *
 * Return: String representation of e_type;
 */
const char *elf_type_str(Elf64_Half type)
{
    switch (type)
    {
        case ET_NONE:
            return ("NONE (Unknown type)");
        case ET_REL:
            return ("REL (Relocatable file)");
        case ET_EXEC:
            return ("EXEC (Executable file)");
        case ET_DYN:
            return ("DYN (Shared object file)");
        case ET_CORE:
            return ("CORE (Core file)");
        default:
            return ("Unknown");
    }
}

/**
 * elf_header - prints elf header
 * @file: name of file to use
 *
 * Return: void
 */
void elf_header(const char *file)
{
    int file_descriptor, i;
    Elf64_Ehdr header;

    file_descriptor = open(file, O_RDONLY);
    if (file_descriptor == -1)
        err_exit("Error opening file %s\n", file);
    if (lseek(file_descriptor, 0, SEEK_SET) == -1) /* reset file pointer to the beginning of the file */
    {
        close(file_descriptor);
        err_exit("Error resetting file pointer for %s\n", file);
    }
    if (read(file_descriptor, &header, sizeof(header)) != sizeof(header))
    {
        close(file_descriptor);
        err_exit("Error reading ELF header in file %s\n", file);
    }
    printf("ELF Header:\n");
    printf("  Magic:   "); /* append the hex characters to this line */
    for (i = 0; i < EI_NIDENT; i++) /* convert the characters to hex */
    {
        printf("%02x", header.e_ident[i]);
        if (i < (EI_NIDENT - 1))
            printf(" ");
    }
    printf("\n");
    printf("  Class:                  %s\n",
        elf_class_str(header.e_ident[EI_CLASS]));
    printf("  Data:                   %s\n",
        elf_data_str(header.e_ident[EI_DATA]));
    printf("  Version:                %d (current)\n",
        header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                 %s\n",
        elf_abi_version_str(header.e_ident[EI_OSABI]));
    printf("  ABI Version:            %d\n",
        (header.e_ident[EI_ABIVERSION]));
    printf("  Type:                   %s\n",
        elf_type_str(header.e_type));
    printf("  Entry point address:    0x%lx\n",
        header.e_entry);
    close(file_descriptor);
}

/**
 * elf_file - checks if the file is an ELF file
 * @file_descriptor: file descriptor to use
 *
 * Return: 1 if ELF file, 0 Otherwise
 */
int elf_file(int file_descriptor)
{
    Elf64_Ehdr header;

    /* if bad reading */
    if (read(file_descriptor, &header, sizeof(header)) != sizeof(header))
        err_exit("Error: can't read ELF file %s\n", "");

    /* check if it's an ELF file */
    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
        return (0); /* Not an ELF file */

    return (1);
}

/**
 * main - program entry point
 * @argc: count of arguments
 * @argv: pointer to array of pointers of arguments passed
 *
 * Return: 0 for success
 */
int main(int argc, char *argv[])
{
    const char *file;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: error wrong number of args\n");
        exit(98);
    }

    file = argv[1];

    /* if returns 0 (not elf file) */
    if (!elf_file(open(file, O_RDONLY)))
    {
        err_exit("Error: File %s not an ELF file\n", file);
    }
    /* print header info */
    elf_header(file);
    return (0);
}

