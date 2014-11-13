md5line
=======

Similar to md5sum, but produces a separate hash for each line of a file.
This program is not as versatile as md5sum, and is only designed to be used under very specific circumstances.

Prints output similar to the way that md5sum does, with a 32-digit hex number, two spaces, and then the line that was hashed.

Designed for usage with ASCII text files.
Not designed for use with files that have lines that are longer than 1023 bytes.
Doesn't include the line feed at the end of each line in the hashs.

A bunch more code would have to be added to make this work with a larger range of files.

Tested in Ubuntu 12.04, x64. Not tested/compiled on OS X but it might work.
