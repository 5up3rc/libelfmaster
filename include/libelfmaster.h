#include <elf.h>
#include <link.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_ERROR_STR_LEN 128

typedef struct elf_error {
        char string[MAX_ERROR_STR_LEN];
        int _errno;
} elf_error_t;

typedef enum elf_arch {
	i386,
	x64
} elf_arch_t;

typedef struct elfobj {
	elf_arch_t arch;
	unsigned int type;
	union {
		Elf32_Ehdr *ehdr32;
		Elf64_Ehdr *ehdr64;
	};
	union {
		Elf32_Phdr *phdr32;
		Elf64_Phdr *phdr64;
	};
	union {
		Elf32_Shdr *shdr32;
		Elf64_Shdr *shdr64;
	};
	union {
		Elf32_Sym *symtab32;
		Elf64_Sym *symtab64;
	};
	union {
		Elf32_Sym *dynsym32;
		Elf64_Sym *dynsym64;
	};
	union {
		Elf32_Dyn *dynamic32;
		Elf64_Dyn *dynamic64;
	};
	char *dynstr;
	char *strtab;
	char *shstrtab;
	uint8_t *mem;
	size_t size;
} elfobj_t;

