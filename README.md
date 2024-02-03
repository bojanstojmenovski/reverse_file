# Reverse File program in C

In command line run: `gcc -o reverse reverse.c`

## Options
* Reverse lines from one file into another: `./reverse <input-file-name> <output-file-name>`;
* Run the program and then insert names of input and output file one after another: `./reverse`;
* Print the lines from the inserted file in reversed order: `./reverse <file-name>`;

## Example
An input file might look like this:
```
hello
this
is 
a file
```

The goal of the reversing program is to read in the data from the specified input file and reverse it; thus, the lines should be printed out in the reverse order of the input stream. Thus, for the aforementioned example, the output should be:
```
a file
is
this
hello
```
