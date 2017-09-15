#include "readelf.h"

/**
 * get_symbol_type - gets the symbol type
 * @type: symbol type of elf
 * Return: symbol type of elf
 */
char *get_symbol_type(unsigned int type)
{
	char buff[32];

	switch (type)
	{
	case STT_NOTYPE:
		return ("NOTYPE");
	case STT_OBJECT:
		return ("OBJECT");
	case STT_FUNC:
		return ("FUNC");
	case STT_SECTION:
		return ("SECTION");
	case STT_FILE:
		return ("FILE");
	case STT_COMMON:
		return ("COMMON");
	case STT_TLS:
		return ("TLS");
	default:
		return ("NOTYPE");
	}
}

/**
 * get_symbol_binding - gets the binding type
 * @binding: binding type of elf
 * Return: binding type of elf
 */
char *get_symbol_binding(unsigned int binding)
{
	char buff[32];

	switch (binding)
	{
	case STB_LOCAL:
		return ("LOCAL");
	case STB_GLOBAL:
		return ("GLOBAL");
	case STB_WEAK:
		return ("WEAK");
	default:
		snprintf(buff, sizeof(buff), ("<unknown>: %d"), binding);
		return (strdup(buff));
	}
}

/**
 * get_symbol_visibility - gets the visibility type
 * @visibility: visibility type of elf
 * Return: visibility type of elf
 */
char *get_symbol_visibility(unsigned int visibility)
{
	switch (visibility)
	{
	case STV_DEFAULT:
		return ("DEFAULT");
	case STV_INTERNAL:
		return ("INTERNAL");
	case STV_HIDDEN:
		return ("HIDDEN");
	case STV_PROTECTED:
		return ("PROTECTED");
	default:
		abort();
	}
}

/**
 * get_symbol_index_type - gets the symbol index type
 * @type: type of symbol
 * Return: symbol index type
 */
char *get_symbol_index_type(unsigned int type)
{
	char buff[32];

	switch (type)
	{
	case SHN_UNDEF:
		return ("UND");
	case SHN_ABS:
		return ("ABS");
	case SHN_COMMON:
		return ("COM");
	default:
		if (type >= SHN_LOPROC && type <= SHN_HIPROC)
			sprintf(buff, "PRC[0x%04x]", type);
		else if (type >= SHN_LOOS && type <= SHN_HIOS)
			sprintf(buff, "OS [0x%04x]", type);
		else if (type >= SHN_LORESERVE && type <= SHN_HIRESERVE)
			sprintf(buff, "RSV[0x%04x]", type);
		else
			sprintf(buff, "%3d", type);
		break;
	}

	return (strdup(buff));
}
