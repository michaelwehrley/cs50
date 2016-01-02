http://cs50.stackexchange.com/questions/1083/array-initializer-must-be-an-initializer-list-or-string-literal
http://stackoverflow.com/questions/12795850/string-literals-pointer-vs-char-array

You can look at string literal as "a sequence of characters surrounded by double quotes".
This string is stored at read-only memory and trying to modify this memory leads to undefined behavior.

So how come that you get segmentation fault?
- The main point is that char *ptr = "string literal" makes ptr to point to the read-only memory where your string literal is stored. So when you try to access this memory: ptr[0] = 'X' (which is by the way equivalent to *(ptr + 0) = 'X'), it is a memory access violation.

On the other hand: char b[] = "string2"; allocates memory and copies string "string2" into it, thus modifying it is valid. This memory is freed when b goes out of scope.

