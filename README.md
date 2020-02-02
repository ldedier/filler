# filler
42 Algorithm project

![oops something went wrong, try to check on https://raw.githubusercontent.com/ldedier/filler/master/resources/filler.gif](https://raw.githubusercontent.com/ldedier/filler/master/resources/filler.gif)

This project was about coding a player of filler.

## Rules

The virtual machine * filler_vm * given by the subject takes 3 parameters:

* a map as a text file
* a player #1 represented with *x*
* a player #2 represented with *o*

Each turn the virtual machine provides one piece to each players besides the current state of the map.
The players shall place their piece in the map so that these pieces overlap with only one tile of a piece previously placed before by themselves (the map always starts with one tile already set for each players).

The first player who can't place its piece anymore (or uses illegal coordinates) looses the game.

## Bonus

A program called filler_visu should be piped directly to the output of the virtual machine and provides a graphic interface to better show the progress of the game.

## Usage

* ./filler_vm -f mapFileName -p1 players/playerExecFileName -p2 players/playerExecFileName
* ./filler_vm -f mapFileName -p1 players/playerExecFileName -p2 players/playerExecFileName | ./filler_visu `[-i]`
