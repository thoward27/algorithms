# Instructor Guide

## Setting up the repo

1. Clone the public repo to your local machine. 
  - `git clone https://github.com/thoward27/algorithms`
  - `git clone git@github.com:thoward27/algorithms.git
2. Add the private remote.
  - `git checkout -b dev`
  - `git remote add private [private repo address]`
  - `git push -u private dev`
3. Merge work from private.
  - `git checkout master`
  - `git merge dev`
  - `git push`

[source](https://24ways.org/2013/keeping-parts-of-your-codebase-private-on-github/)

## Autograder Setup

The autograder for this course should use [RapidCheck](https://github.com/emil-e/rapidcheck).

> Single Header Version: [autocheck](https://github.com/thejohnfreeman/autocheck)

