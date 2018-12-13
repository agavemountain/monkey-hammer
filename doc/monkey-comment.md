As a technical mercenary (consultant), I've had the pleasure of working in a variety of industries and with a myriad of clients.  While I generally follow the style of the code I'm editing, I do run into developers with unusually strong opinions about code comment formatting, especially where copyright
headers and class documentation are concerned.

I gave up and wrote this handy-dandy utility for generating properly formatted copyright headers and code comments.  

This application does not strip or alter code.  It will simply prepend and format the stream of text that is passed through it, via standard I/O

### Redirection
Without specifying an input file and output file:
 - If no input file is specified, standard input is used
 - If no output file is specified, standard output is used

Therefore, you can take a file and pipe it to the utility  which will take the input and format it which can be dumped into a  file (named myoutputfile in the following example):

```bash
 $ cat myfile | monkey-comment > myoutputfile
 ```

 Additionally, you can append it to an existing file:
```bash
 $ cat myfile | monkey-comment  >> myoutputfile
```

### Single Line Comments

 You can choose to prefix each line with a string.  For bash files, or Perl  headers you'd want to use the # symbol.  For C++, // would rule the day.

```bash
 $ monkey-comment --input myfile  --comment-pre "# "
 # This is a test
 # This is only a test
```
### Multi-Line Comments

 More importantly, you can specify how multi-line comments are formatted.
```bash
 $ monkey-comment  --input myfile --comment-prefix "//!" --comment-pre " #" --comment-postfix "//!"
//!
 # This is a test
 # This is only a test
//!
```
