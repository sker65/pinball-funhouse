<h1>Funhouse Pinball Extension</h1>

Small project to extend / customize a funhouse pinball maschine with some 
extra light effects and a topper.

An extended version of SoftTimer library is included. It differs from the original
found here https://code.google.com/p/arduino-softtimer/ in that it uses real virtual
methods instead of function pointer. Additionally a task has a state and can be paused
or resumed.

The project / the classes are split in actor classes that control the lamps and leds
and sensor classes that track the connected switches or switched lamps.

Third category of tasks are detection of game modes and controlling actors (not implemented
until now). Everything is modeled as task and can run concurrently to other task.

