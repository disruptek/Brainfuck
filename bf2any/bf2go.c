
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf2any.h"

/*
 * Google GO translation from BF, runs at about 710,000,000 instructions per second.
 *
 * But it is very slow to compile.
 */

static int ind = 0;
#define I printf("%*s", ind*4, "")

struct be_interface_s be_interface = {};

static const char * ctype = "int";
static int vmask = -1;

static void print_cstring(void);

void
outcmd(int ch, int count)
{
    switch(ch) {
    case '!':
	if (bytecell) { ctype = "byte"; vmask = 255; }

	printf( "%s%d%s%s%s%d%s%s%s",
		"package main\n"
		"import(\"fmt\"\n"
		"    \"os\")\n"
		"var m [",tapesz,"]", ctype, "\n"
		"var p = ",tapeinit,"\n"
		"var v ", ctype, "\n"
		"func main() {\n"
		);
	ind++;
	break;

    case '~':
	I; printf("os.Exit(0)\n");
	ind--;
	printf("}\n");
	break;

    case '=': I; printf("m[p] = %d\n", count & vmask); break;
    case 'B':
	I; printf("v = m[p]\n");
	break;
    case 'M': I; printf("m[p] = m[p]+v*%d\n", count & vmask); break;
    case 'N': I; printf("m[p] = m[p]-v*%d\n", count & vmask); break;
    case 'S': I; printf("m[p] = m[p]+v\n"); break;
    case 'T': I; printf("m[p] = m[p]-v\n"); break;
    case '*': I; printf("m[p] = m[p]*v\n"); break;

    case 'C': I; printf("m[p] = v*%d\n", count & vmask); break;
    case 'D': I; printf("m[p] = -v*%d\n", count & vmask); break;
    case 'V': I; printf("m[p] = v\n"); break;
    case 'W': I; printf("m[p] = -v\n"); break;

    case 'X':
	I; printf("fmt.Fprintf(os.Stderr, \"Aborting Infinite Loop.\\n\")\n");
	I; printf("os.Exit(1)\n");
	break;

    case '+': I; printf("m[p] += %d\n", count & vmask); break;
    case '-': I; printf("m[p] -= %d\n", count & vmask); break;
    case '<': I; printf("p -= %d\n", count); break;
    case '>': I; printf("p += %d\n", count); break;
    case '[':
	I; printf("for m[p] != 0 {\n");
	ind++;
	break;
    case ']':
	ind--; I; printf("}\n");
	break;
    case 'I':
	I; printf("if m[p] != 0 {\n");
	ind++;
	break;
    case 'E':
	ind--; I; printf("}\n");
	break;
    case '.': I; printf("fmt.Print(string(m[p]))\n"); break;
    case '"': print_cstring(); break;
    case ',': I; printf("fmt.Scanf(\"%%c\", &m[p])\n"); break;
    }
}

static void
print_cstring(void)
{
    char * str = get_string();
    char buf[256];
    int gotnl = 0;
    size_t outlen = 0;

    if (!str) return;

    for(;; str++) {
	if (outlen && (*str == 0 || gotnl || outlen > sizeof(buf)-8))
	{
	    buf[outlen] = 0;
	    I; printf("fmt.Print(\"%s\")\n", buf);
	    gotnl = 0; outlen = 0;
	}
	if (!*str) break;

	if (*str == '\n') gotnl = 1;
	if (*str == '"' || *str == '\\') {
	    buf[outlen++] = '\\'; buf[outlen++] = *str;
	} else if (*str >= ' ' && *str <= '~') {
	    buf[outlen++] = *str;
	} else if (*str == '\n') {
	    buf[outlen++] = '\\'; buf[outlen++] = 'n';
	} else {
	    char buf2[16];
	    int n;
	    sprintf(buf2, "\\%03o", *str & 0xFF);
	    for(n=0; buf2[n]; n++)
		buf[outlen++] = buf2[n];
	}
    }
}
