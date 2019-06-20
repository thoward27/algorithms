# Troubleshooting

## `make` won't work

Run the following to fix `make`

```bash
sudo apt-get update
sudo apt-get upgrade
sudo apt install make
sudo apt install g++-8
```

## Code won't compile

Checklist:

- Are all the expected methods/functions declared **and** defined?
- Do you have `doctest.h` in your `source` folder?
- Are you using `-std=c++11`?
- What do the errors themselves say?
  
## Need attribute `x` in my class

 Any time an assignment involves a `private` section you may add anything you'd like to it.

## What libraries can I use?

You can use `<iostream>` and anything we build in the class repository. You may also use any helper functions you create. You may use **no** other libraries or STL objects.
