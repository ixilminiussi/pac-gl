# pac-gl
a pacman clone made in openGL

## Dependencies
```
sudo apt install freeglut3-dev libopenal-dev libalut-dev
```
Alternatively, you can build from source
### freealut
```
$ git clone https://github.com/vancegroup/freealut.git
$ cd freealut
$ mkdir build; cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX:STRING="/usr" -DCMAKE_C_FLAGS:STRING="-march=athlon-xp -O2" 
$ make 
$ make install
```
### freeglut
download the latest tar-ball from ![here](https://freeglut.sourceforge.net/index.php#download)
```
$ tar xzvf freeglut-X.Y.Z.tar.gz
$ cd freeglut-X.Y.Z
$ mkdir build; cd build
$ cmake ..
$ make
$ sudo make install
```

## Running
```
$ cd pac-gl/
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./pac-gl
```

## TO-DO
- add more sounds
