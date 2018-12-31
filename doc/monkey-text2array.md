# monkey-text2array

Sometimes, it is useful to transform a file into a 
literal array.  Sometimes it is a jpeg, crytographic certificate, or just a 
simple text file. 

In these situations I usually write a quick and dirty script or 
program to do this, but for the life of me I can't find any of the remnants.  As I 
stumble across my old code, I will push the code here.

This version only takes a text file and creates a string literal in C/C++.

### Redirection
Without specifying an input file and output file:
 - If no input file is specified, standard input is used
 - If no output file is specified, standard output is used

Therefore, you can take a file and pipe it to the utility  which will take the input and format it which can be dumped into a  file (named myoutputfile in the following example):

```bash
 $ cat myfile | monkey-text2array > myoutputfile
 ```

 Additionally, you can append it to an existing file:
 
```bash
 $ cat myfile | monkey-text2array  >> myoutputfile
```

### Example:

```bash
 $ cat myfile.txt
 jane
 bob
 woody
 
 $ cat myfile.txt | monkey-text2array --name "hello" > myoutputfile
 
 $ cat myoutputfile
 const char *hello[] =
 {
 "jane",
 "bob",
 "woody",
 };
 
```
