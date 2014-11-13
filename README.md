md5line
=======

Similar to md5sum, but produces a separate hash for each line of input.
This program is not as versatile as md5sum, and is only designed to be used under very specific circumstances.

Prints output similar to the way that md5sum does, with a 32-digit hex number, two spaces, and then the line that was hashed.

This program currently doesn't accept any arguments, and all input must come from stdin.
In order to send an entire file to md5line, just use cat:

	cat file.txt | md5line

This is inefficient, and in the future I might add the ability to pass filenames directly to md5line as an argument.

Designed for usage with ASCII text.
Not designed for use with files that have lines that are longer than 1023 bytes.
Doesn't include the line feed at the end of each line in the hashs.

A bunch more code would have to be added to make this work with a larger range of files.

Tested in Ubuntu 12.04, x64. Not tested/compiled on OS X but it might work.
