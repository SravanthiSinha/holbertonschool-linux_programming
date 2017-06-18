#include "hls.h"

/**
 * get_permissions - Returns the permissions of the file
 * @sb: stat structure for a file
 *
 * Return: string with the permissions of the file
 */
char *get_permissions(struct stat sb)
{
	static char permissions[11];

	switch (sb.st_mode & S_IFMT)
	{
	case S_IFBLK:
		permissions[0] = 'b';
		break;
	case S_IFCHR:
		permissions[0] = 'c';
		break;
	case S_IFDIR:
		permissions[0] = 'd';
		break;
	case S_IFIFO:
		permissions[0] = 'd';
		break;
	case S_IFLNK:
		permissions[0] = 'l';
		break;
	case S_IFREG:
		permissions[0] = '-';
		break;
	case S_IFSOCK:
		permissions[0] = 's';
		break;
	default:
		permissions[0] = '?';
		break;
	}
	permissions[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
	permissions[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
	permissions[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
	permissions[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
	permissions[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
	permissions[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
	permissions[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
	permissions[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
	permissions[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
	permissions[10] = '\0';
	return (permissions);
}
/**
 * print_file_long_format - Prints the filelist in long format
 * @path_name: path of the filename
 * @size_width : width of the biggest filesize
 *
 * Return: void
 */
void print_file_long_format(char *path_name, int size_width)
{
	struct stat sb;
	char *time;
	char buf[1024];
	int len;
	struct passwd *usr;
	struct group *grp;

	if (lstat(path_name, &sb) == -1)
		exit(HLS_MINOR_ERROR);
	usr = getpwuid(sb.st_uid);
	grp = getgrgid(sb.st_gid);
	time = strtok(ctime(&(sb.st_mtime)), "\n");
	time[strlen(time) - 8] = '\0';
	printf("%s %ld ", get_permissions(sb), (long)sb.st_nlink);
	printf("%s ", usr != NULL ? usr->pw_name : "NULL");
	printf("%s ", grp != NULL ? grp->gr_name : "NULL");
	printf("%*ld%s ", size_width, (long)sb.st_size, time + 3);
	if (S_ISLNK(sb.st_mode))
	{
		len = readlink(path_name, buf, sizeof(buf) - 1);
		if (len != -1)
			buf[len] = '\0';
		printf("%s -> %s", basename(path_name), buf);
	}
	else
		printf("%s", basename(path_name));
}

/**
 * print_files - Prints the filelist
 * @options: options to be applied for each @dirname
 * @dirnames: the file options
 * @dirent: The list of the directories and files with absolute path.
 * @w: width of the biggest filesize
 * Return: 1 if list of files are printed else 0
 */
int print_files(Options *options, Direntry **dirent, List **dirnames, int w)
{
	Direntry *node = *dirent;
	char *filename;
	int a = 0;
	int implied;
	int hidden_file;

	if (node == NULL)
		return (0);
	while (node != NULL)
	{
		implied = 0;
		hidden_file = 0;
		filename = strdup(node->str);
		if (basename(filename)[0] == '.')
			hidden_file = 1;
		if (!strcmp(basename(filename), ".") || !strcmp(basename(filename), ".."))
			implied = 1;
		if (!options->all  && !options->almost_all && hidden_file)
			node = node->next;
		else if (options->almost_all && implied)
			node = node->next;
		else
		{
			if (options->long_format)
				print_file_long_format(filename, w);
			else
				printf("%s", basename(filename));
			if (!is_directory(filename))
				deleteParam(dirnames, filename);
			a = 1;
		node = node->next;
		if (node && a)
			printf("%s", options->delimeter);
		}
		free(filename);
	}
	printf("\n");
	return (1);
}

/**
 * print_file_list - Prints the filelist
 * @op: options to be applied for each @dirnames
 * @dirnames: the file options
 * @dirent: The list of the directories and files with absolute path.
 * @ec : to print a newline if an error was printed to OUTPUT
 *
 * Return: void
 */
void print_file_list(Options *op, List **dirnames, Direntry **dirent, int ec)
{
	Direntry *node = NULL;
	int a = 0, i = 0;
	int no_dirs = 0, no_files = 0;
	char param[MAX_PATH_SIZE];
	long size;

	param[0] = '\0';
	node = get_files(*dirent);/* print_files*/
	if (op->sort_size)
		sort_direntres(&node, &dirent_cmp_size, op->reverse);
	else
		sort_direntres(&node, &dirent_cmp, op->reverse);
	size = get_biggest_size(*dirent);
	no_files = print_files(op, &node, dirnames, no_digits(size));
	free_direntry(node);
	no_dirs = list_size(*dirnames);/* print_dirs*/
	if (no_files && no_dirs)
		printf("\n");
	while (i < no_dirs)
	{
		a = 0;
		strcat(param, get_node(*dirnames, i));
		if ((no_dirs > 1 || ec || no_files) && is_directory(param))
			printf("%s:\n", param);
		if (param[strlen(param) - 1] != '/')
			strcat(param, "/");
		node = get_direntres(param, *dirent);
		if (op->sort_size)
			sort_direntres(&node, &dirent_cmp_size, op->reverse);
		else
			sort_direntres(&node, &dirent_cmp, op->reverse);
		removeDuplicates(node);
		size = get_biggest_size(*dirent);
		if (print_files(op, &node, dirnames, no_digits(size)) && i < no_dirs - 1)
			printf("\n");
		free_direntry(node);
		i++;
		param[0] = '\0';
	}
}
