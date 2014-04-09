/*
 * Copyright (c) 2013 - 2014 Jan Klemkow <j.klemkow@wemelug.de>
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
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char**argv)
{
	char *file = "in";
	char buf[BUFSIZ];
	size_t size;
	int fd;

	if ((fd = open(file, O_WRONLY)) < 0)
		goto err;

	while ((size = read(STDIN_FILENO, buf, sizeof buf)) > 0)
		if (write(fd, buf, size) < 0)
			goto err;

	if (size < 0)
		goto err;

	printf("Content-type: text/plain\n\n");
	return EXIT_SUCCESS;
 err:
	perror(NULL);
	return EXIT_FAILURE;
}
