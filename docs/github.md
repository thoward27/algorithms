# Github Handbook for 212

[View the official Handbook](https://guides.github.com/introduction/git-handbook/)

## Student Instructions

1. Visit the public repository's [website](https://github.com/thoward27/algorithms)
2. Fork the repository (Button on the top right)
3. Clone the forked repo to your computer (`git clone <your_repo_goes_here>`)
4. [Configure a remote for your fork](https://help.github.com/en/articles/configuring-a-remote-for-a-fork)
5. For each coding activity, you will create a branch for that specific work. (`git checkout -b <{lab, assignment}>/<topic>`)
6. Push your changes to your own copy of the repo (`git push -u origin <{lab, assignment}>/<topic>`), note that `-u origin <branch>` is only necessary on the first push, subsequent pushes can use `git push origin`.
7. If you need to submit a pull request, simply head to your online copy of the repo and select "Compare & pull request".
8. Review the guidelines for contributing if you have not already, once your pull request adheres to the guidelines, create the request.

## TA Instructions

1. Clone the public repository (`git clone git@github.com:thoward27/algorithms.git`)
2. CD into the repo (`cd algorithms`)
3. Add the private remote (`git remote add private git@github.com:thoward27/_algorithms.git`)
4. Fetch from the remote (`git fetch private`)
5. Checkout dev to work (`git checkout dev`), merge to master when you're ready to publish.

> Be sure that when you're dealing with solutions, or WIP, that you ensure you push only to private. The branch Dev should never be pushed to the public facing repo, accidental pushes will be hard wiped immediately, **all data will be lost**.
