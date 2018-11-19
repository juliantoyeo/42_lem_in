# 42_lem_in

Lem_in is a project about finding the shortest path possible with algoritm.
This project trains me on tedious parsing format and finding the best algoritm to solve the project.

# Project Target

The target for this project is to find the shortest path possible for the ants to get from starting room to ending room.

example of the room looks like this:

and it will be easier to see this in action:

# Project rule

- The first room (start) and the last room (end) can host unlimited amount of ants.
- All the other room can only contain 1 ant at a time (Except the start and end)
- The ant must move from the start room to the end room with the shortest path possible.
- Each path is assumed to be same length and distance, thus shortest path does not count the path length, just the amount of room changing is counted.
- Each room must be linked to at least one of the other room (thus all room can be accessed).


# Parsing format

The parsing format have a structure like this :

number_of_ants

the_rooms

the_links


The parsing data can be given to the program either by typing in the terminal like this

<img>

or reading putting it in a file and send it to the program by doing this in the terminal

# Parsing rule

- Room name can be integer or string
- Room name can never start with the character L nor the character #
- Room coordinates will always be integers (but it is only useful when we want to visualize it, it will not affecting how the algorithm work and path does not need to consider the length)
- Lines that start with ## are commands that only to indicate the start and ending room with the data that comes right after at the next line
- Unknown ## commands other then "start" and "end" will be ignored
- Lines that start with # is comments line and the program will ignore it
- If the parsing does not respect the parsing format structure (eg. declare the room first and number of ants later) the programm will return "ERROR"
- If there is no possible path from the start to the end room, the program will return "ERROR"
- Any non complain of the parsing format will return "ERROR"

# Program Testing

There is a lem_in file generator which can generate the parsing data with the following call :

```
./lem-in_gen [number_of_ant] [number_of_room]
```

My lem_in can solve the problem of 5000 ants and 5000 room on average of 30-40seconds (time to printing output not included)

You can directly use the generator and parse the data to the program with the following command:

```
./lem-in_gen 100 200 | ./lem_in
```

This will create 100 ants and 200 rooms to be injected to the program to solve

# Program Visual (A bonus for the project)

My visual program that i write by myself is not very optimise, so it will be very chaotic to have alot of room.
You can try to see it in a visual by using the maps/goodvisu.map

To run with visual :

```
./lem_in < maps/goodvisu.map | ./visu-hex
```

# Visual control

- Use mouse drag to move the display.
- Use keyboard "space" to reset the display.
- Use keyboard "enter" to start the animation.

