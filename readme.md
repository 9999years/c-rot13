#rot13 for C

Inspired by the lack of a simple rot13 for Windows and my surplus of free time.

Might work on Unix if you fiddle with the Makefile a bit.

Reads from the pipeline

```
>echo Hello | rot13
Uryyb
```

Or from the arguments!

```
>rot13 Hello
Uryyb
```

Only reads 1024 characters so ¯\_(ツ)_/¯ if you need more than that. Sorry!
