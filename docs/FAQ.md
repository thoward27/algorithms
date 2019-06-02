# FAQ

- Why is the `doctest` folder empty?
  - Your missing your submodule, following the documentation found [here](https://git-scm.com/book/en/v2/Git-Tools-Submodules), execute `git submodule init && git submodule update` to solve this problem.
- Why won't my class compile?
  - Checklist: Are all the expected methods defined? Are there things in your `doctest` folder? Are you using `-std=c++11`?
- Can I add attribute `x` to my class?
  - Yes! Any time an assignment involves a `private` section you may add anything you'd like to it.
- What libraries can I use?
  - You can use `<iostream>` and anything we build in the class repository. You may also use any helper functions you create. You may use **no** other libraries or STL objects.
