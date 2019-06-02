# Github Handbook for 212

[View the official Handbook](https://guides.github.com/introduction/git-handbook/)

> Note: Do not type angle brackets (< >), those indicate that you should replace the contents.

## Student Instructions

1. Create a fork.
   1. Visit the public repository's [website](https://github.com/thoward27/algorithms)
   2. Fork the repository (Button on the top right)
2. Cloning your fork
   1. Navigate to your Github profile
   2. Select your copy of the `algorithms` repository
   3. Get the link to your repo from the big green button on the right side of the page.
   4. In your terminal, navigate to where you'd like to save your work
   5. Execute `git clone --recurse-submodules <your_repo_link_goes_here>`
3. Configuring your new repository
   1. CD into the freshly cloned repo (`cd algorithms`)
   2. [Configure a remote for your fork](https://help.github.com/en/articles/configuring-a-remote-for-a-fork)
   3. Make sure when you run `git remote -v` you see `upstream` with a link to my copy of `algorithms` (`https://github.com/thoward27/algorithms.git`)
4. Working with your repository
   1. Before beginning any work, you should update your copy of the repo from upstream.
      1. Checkout the master branch `git checkout master`
      2. Update from upstream `git fetch upstream && git merge upstream master`
   2. Then create a new branch for your work `git checkout -b lab/<topic>`
   3. Publish your changes with `git push -u origin lab/<topic>`
   4. Do your work
   5. Commit your changes to the branch
      1. Stage all of you changes `git add *`
      2. Commit them `git commit -m "<your message goes here>"`
   6. Push them to the remote `git push`
5. Opening a Pull Request
   1. **You should only do this with explicit permission**
   2. Navigate to your Github profile, and select the `algorithms` repository.
   3. Select the branch you'd like to open a pull request from (normally the one from that days work)
   4. Select "Open a Pull Request"
   5. In the message, put all of your groups URI Emails so that I can update my gradebook

## TA Instructions

1. Clone the public repository (`git clone git@github.com:thoward27/algorithms.git`)
2. CD into the repo (`cd algorithms`)
3. Add the private remote (`git remote add private git@github.com:thoward27/_algorithms.git`)
4. Fetch from the remote (`git fetch private`)
5. Checkout dev to work (`git checkout dev`), merge to master when you're ready to publish.

> Be sure that when you're dealing with solutions, or WIP, that you ensure you push only to private. The branch Dev should never be pushed to the public facing repo, accidental pushes will be hard wiped immediately, **all data will be lost**.
