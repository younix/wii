/*
 * Copyright (c) 2013 Jan Klemkow <j.klemkow@wemelug.de>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

off_t
get_range(void)
{
	char *str = getenv("HTTP_RANGE");

	if (str == NULL)
		return 0;

	if ((str = strchr(str, '=')) == NULL)
		return 0;

	return strtol(str + 1, NULL, 10);
}

int
main(int argv, char**argc)
{
	char *file = "out";
	int fd;
	char buf[BUFSIZ];
	size_t size, diff = 0;
	off_t range = get_range();

	if ((fd = open(file, O_RDONLY)) < 0)
		goto err;
	if (lseek(fd, range, SEEK_SET) < 0)
		goto err;

	/* TODO: if eof than use libevent to detect file changes */

	printf("Content-Length: %zd\n", diff);
	printf("Content-type: text/plain\n\n");

	while ((size = read(fd, buf, BUFSIZ)) > 0)
		if (write(STDOUT_FILENO, buf, size) < 0)
			goto err;

	if (size < 0)
		goto err;

	return EXIT_SUCCESS;
 err:
	perror(NULL);
	return EXIT_FAILURE;
}
