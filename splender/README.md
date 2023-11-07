Splender is a robot with a mission. It has to go to a certain location, following the given instructions on the map.
The task is to write a program which guides Splender through the map until he reaches the desired destination. In other words, an algorithm which guides it has to be created.

Rules:

The 9 rules of the new Splender system:


1) Splender starts from the place indicated by the `@` symbol on the map and heads `SOUTH`.

   
2) Splender finishes his journey when he reaches the end location marked `$`.

   
3) Obstacles that Splender may encounter are represented by `#` or `X`.

   
4) When Splender `encounters an obstacle`, he changes direction using the following priorities: `SOUTH`, `EAST`,
`NORTH`, and `WEST`. So he first tries to go SOUTH, if he cannot, then he will go EAST, if he still cannot, then he will go
NORTH, and finally, if he still cannot, then he will go WEST.


5) Along the way, Splender may come across path modifiers that will instantaneously make him change direction.
The `S` modifier will make him turn `SOUTH` from then on, `E`, to the `EAST`, `N` to the `NORTH`, and `W` to the `WEST`.

6) `The circuit inverters (I on map)` produce a magnetic field which will reverse the direction priorities that Splender
should choose when encountering an obstacle. `Priorities will become` `WEST`, `NORTH`, `EAST`, `SOUTH`. If Splender
`returns to an inverter I`, then `priorities are reset` to their original state (SOUTH, EAST, NORTH, WEST).


7) Splender can also find a few beers along his path `(B on the map)` that will give him strength and put him in
“Breaker” mode. `Breaker mode allows Splender to destroy and automatically pass through the obstacles
represented by the character X (only the obstacles X)`. If Splender is in Breaker mode and passes over a beer again, then he
immediately goes out of Breaker mode. The beers remain in place after Splender has passed.


8) 2 teleporters `T` may be present in the city. If Splender passes over a teleporter, then he is automatically
teleported to the position of the other teleporter and he `retains his direction and Breaker mode properties`.


9) Finally, the space characters are `blank areas` on the map (no special behaviour other than those specified above).
`Your program must display the sequence of moves` taken by Splender according to the map provided as input.
The map is divided into lines (L) and columns (C). The contours of the map are always unbreakable # obstacles. The
map always has a starting point `@` and a suicide booth `$`.


Let the map below:

    ######
    #@E $#
    # N  #
    #X   #
    ######

Then the path is:

    SOUTH (initial direction)
    EAST (because of the obstacle X)
    NORTH (change of direction caused by N)
    EAST (change of direction caused by E)
    EAST (current direction, until endpoint $)


Input:

X and Y of the map and then the actual map

Output:

All steps taken until reaching the final destination


Sample input:

    10 10
    ##########
    #        #
    #  S   W #
    #        #
    #        #
    #  $     #
    #@       #
    #        #
    #E     N #
    ##########

Sample output:

    South
    South
    East
    East
    East
    East
    East
    East
    North
    North
    North
    North
    North
    North
    West
    West
    West
    West
    South

Sample input:

    5 5
    #####
    #@ T#
    #T  #
    #  $#
    #####
    
Sample output:

    South
    South
    South

Sample input:

    8 8
    ########
    # @    #
    #     X#
    # XXX  #
    #   XX #
    #   XX #
    #     $#
    ########

Sample output:

    South
    East
    East
    East
    South
    East
    South
    South
    South

Sample input:

    5 5
    #####
    #@ T#
    #   #
    #T$N#
    #####

Sample output:

    South
    South
    South
    South
    North
    North
    East

Sample input:

    5 5
    #####
    #   #
    #$ I#
    #  @#
    #####

Sample output:

    North
    West
    West

Sample input:

    5 5
    #####
    #@  #
    #   #
    #  $#
    #####

Sample output:

    South
    South
    East
    East

Sample input:

    8 8
    ########
    #      #
    #      #
    #      #
    #$     #
    # I   W#
    #X   @ #
    ########

Sample output:

    East
    North
    West
    West
    West
    West
    West
    North

Sample input:

    8 8
    ########
    #T$   I#
    #      #
    #E    N#
    #      #
    #      #
    #  @  T#
    ########

Sample output:

    East
    East
    East
    South
    South
    East
    East
    East
    East
    East
    North
    North
    West
    West
    West
    West

Sample input:

    8 8
    ########
    # $   I#
    #      #
    #    @N#
    #    X #
    #      #
    #      #
    ########

Sample output:

    East
    North
    North
    West
    West
    West
    West

Sample input:

    8 8
    ########
    #      #
    #      #
    #  @   #
    #  S   #
    #      #
    #$ I   #
    ########

Sample output:

    South
    South
    South
    West
    West

Sample input:

    8 8
    ########
    #  @   #
    #  S   #
    #  B   #
    #   $  #
    #  X   #
    #$ I   #
    ########

Sample output:

    South
    South
    South
    South
    South
    West
    West
