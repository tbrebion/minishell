# minishell - done in collab with [tbrebion](https://github.com/tbrebion)

This project is from 42 school commom core. Its aim was to create a posix bash like shell.

## Rules

- ### prompt :
  - print a prompt waiting for a new command
  - must have a working history
 
- ### redirections :
  - `<` must redirect the input
  - `>` must redirect the output
  - `<<` must act as an heredoc
  - `>>` must redirect the output in append mode
  
- ### pipes
  - each pipeline's command's output must be connected to the next command's input with a pipe ( `|` )
 
- ### environment variable
  - `$VAR` must be expanded
  
- ### `$?`
  - must be substituted by the last pipeline's error status
 
- ### signals
  - handle `ctrl-c` `ctrl-d` `ctrl-\` as bash does
 
- ### builtins
  - `echo` with `-n` option
  - `cd` with an absolute or relative path
  - `pwd` without any option
  - `export` without any option
  - `unset` without any option
  - `env` without any option nor argument
  - `exit` without any option
