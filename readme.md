#rot13 in C

Inspired by the lack of a simple rot13 for Windows and my surplus of free time.

Works on Linux!

Compile with `make` or `nmake`.

Reads from the pipeline (stdin)

```
>echo The quick brown fox jumps over the lazy dog. | rot13

Gur dhvpx oebja sbk whzcf bire gur ynml qbt.
```

or

```
$ echo "The quick brown fox jumps over the lazy dog." | ./rot13
Gur dhvpx oebja sbk whzcf bire gur ynml qbt.
```

Or from the arguments!

```
>rot13 The quick brown fox jumps over the lazy dog.
Gur dhvpx oebja sbk whzcf bire gur ynml qbt.
```

or

```
$ ./rot13 The quick brown fox jumps over the lazy dog.
Gur dhvpx oebja sbk whzcf bire gur ynml qbt.
```

prints help text with `--help`, `-h`, `-?`, `/?`, `/help`, and `/h`. Y’know, for compatability.

Only reads 1024 characters so ¯\\\_(ツ)\_/¯ if you need more than that. Sorry!
