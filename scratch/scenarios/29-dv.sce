* DV VERBOSE ALL OFF
* LS VERBOSE ALL OFF
* APP VERBOSE ALL OFF
* DV VERBOSE STATUS OFF
* DV VERBOSE ERROR OFF
* LS VERBOSE STATUS OFF
* LS VERBOSE ERROR OFF
* APP VERBOSE STATUS OFF
* APP VERBOSE ERROR OFF
* DV VERBOSE TRAFFIC OFF
* APP VERBOSE TRAFFIC OFF

TIME 60000

NODELINKS DOWN 11

TIME 10

LINK DOWN 5 9

TIME 30000

# TEST 1
0 DV DUMP ROUTES

TIME 10

LINK UP 5 9

TIME 30000

# TEST 2
6 DV DUMP ROUTES

TIME 10

LINK DOWN 0 5

TIME 30000

# TEST 3
6 DV DUMP ROUTES

TIME 10

LINK DOWN 0 1

TIME 30000

LINK DOWN 5 9

TIME 30000

# TEST 4
6 DV DUMP ROUTES

TIME 10

LINK UP 5 0

TIME 30000

# TEST 5
6 DV DUMP ROUTES

TIME 10

NODELINKS DOWN 19

TIME 30000

# TEST 6
20 DV DUMP ROUTES

LINK UP 19 20

TIME 10

LINK UP 19 21

TIME 30000

# TEST 7
20 DV DUMP ROUTES

QUIT