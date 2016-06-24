#rot13 in C

Inspired by the lack of a simple rot13 for Windows and my surplus of free time.

Works on Unix!

Reads from the pipeline

```
>echo Hello | rot13
Uryyb
```

or

```
$ ./rot13 Hello
Uryyb
```

Or from the arguments!

```
>rot13 Hello
Uryyb
```

or

```
$ echo "Hello" | ./rot13
Uryyb
```

Only reads 1024 characters so ¯\\_(ツ)_/¯ if you need more than that. Sorry!
