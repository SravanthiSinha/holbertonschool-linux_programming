#include "hls.h"

/**
 * no_digits - Number of digits in a number
 * @n: Number
 *
 * Return: Number of digits in a number.
 */
unsigned int no_digits(long n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

/**
 * widths - gets the widths of the biggest file, user, grp in the list.
 * @en: The Direntry where the size of each drientry are to be looked in.
 *
 * Return: size of the biggest file
 */
int *widths(Direntry *en)
{
	int tsize = 0, tsize2 = 0, tsize1 = 0;
	int *sizes; /*fsize , user_size , group_size*/
	struct stat sb;
	struct passwd *usr;
	struct group *grp;

	sizes = malloc(3 * (sizeof(int)));
	if (en != NULL)
	{
		if (lstat(en->str, &sb) == -1)
			exit(HLS_MINOR_ERROR);
		usr = getpwuid(sb.st_uid);
		grp = getgrgid(sb.st_gid);
		sizes[0] = no_digits(file_size(en->str));
		sizes[1] = usr != NULL ? _strlen(usr->pw_name) : no_digits(sb.st_uid);
		sizes[2] = grp != NULL ? _strlen(grp->gr_name) : no_digits(sb.st_gid);
	}
	while (en != NULL)
	{
		if (lstat(en->str, &sb) == -1)
			exit(HLS_MINOR_ERROR);
		usr = getpwuid(sb.st_uid);
		grp = getgrgid(sb.st_gid);
		tsize = no_digits(file_size(en->str));
		tsize1 = usr != NULL ? _strlen(usr->pw_name) : no_digits(sb.st_uid);
		tsize2 =  grp != NULL ? _strlen(grp->gr_name) : no_digits(sb.st_gid);
		if (tsize > sizes[0])
			sizes[0] = tsize;
		if (tsize1 > sizes[1])
			sizes[1] = tsize1;
		if (tsize2 > sizes[2])
			sizes[2] = tsize2;
		en = en->next;
	}
	return (sizes);
}
