
#verificar conexion con stk500
avrdude -c stk500 -p m32 -P /dev/ttyUSB0 -v -U lfuse:r:-:i -v
#si sale error de escritura
Es por los permisos, correr:
sudo chmod 666 /dev/ttyUSB0

#HOWTO
- Activa el Bluetooth
- password 1234
- configura la aplicación con todos los datos de entrada y salida
- configura la aplicación como terminal
- ingresa :h para ayuda

# IDOCK
manualito de como configurar git

[COMMAND ESCAPE SEQUENCES] (https://shiroyasha.svbtle.com/escape-sequences-a-quick-guide-1)
[ATMEGA32 pinout] (https://atmega32-avr.com/wp-content/uploads/2012/04/atmega-pinout.jpg)


## configuracion de la terminal bluetooth "Serial Bluetooth"

# TERMINAL

```bash
Font size: la que te guste
Font style: Normal
Charset: US-ASCII
Display mode: Terminal
Auto scroll to end of buffer: ON
Show connection messages: ON
Show timestamps: OFF
```

# RECEIVE
```bash
Newline: LF
```
# SEND
```bash
Newline: CR
Edit mode: text
line delay: 0 ms
Character delay 0m s
Local echo: ON
Clear input on send: ON
```

# Commands that I used to recover branch

```bash
  395  cd /home/acatl/Projects/ipod
  396  ls
  397  cd idock
  398  ls
  399  git branch
  400  git checkout master
  401  git merge origin/master
  402  git add .
  403  git commit -m "merged all"
  404  git push
  405  git branch
  406  git checkout master
  407  git checkout feature/functions
  408  git checkout features/functions
  409  git checkout feature/functions
  410  git help
  411  git status
  412  git checkout master
  413  git status
  414  git status
  415  git push
  416  git commit -m "merged"
  417  git commit
  418  git status
  419  git branch -d features/functions
  420  git branches
  421  git branch
  422  git status
  423  git pull
  424  git status
  425  git merge --abort
  426  ls
  427  ls --la
  428  ls -la
  429  .git
  430  ls .git
  431  ls .git/branches/
  432  cd ..
  433  cd idock
  434  git status
  435  git pull
  436  cd /home/acatl/
  437  cd /home/acatl/Descargas/
  438  ls 
  439  unzip idock-features-functions.zip 
  440  ls
  441  cd idock-features-functions
  442  ls
  443  kicad idock_pcb0-1.kicad_pcb
  444  cd ..
  445  cd /home/acatl/Projects/
  446  ls
  447  cd ipod
  448  ls
  449  git reflog --no-abbrev
  450  ls
  451  cd idock
  452  ls
  453  git reflog --no-abbrev
  454  git checkout 3a2d1c04740ebc144cd8f27a33aed1c6fbf23376
  455  git checkout -b debug
  456  git branch
  457  git status
  458  git status
  459  git branch
  460  git commit
  461  cp -r /home/acatl/Projects/ipod/idock /home/acatl/Projects/ipod/.idock
  462  ls
  463  nano main.c 
  464  git branch
  465  git commit
  466  git add
  467  git add .
  468  git commit -m "restored features with debug name"
  469  git commit -a
  470  git commit -h
  471  git commit -a -m "restored features with debug name"
  472  git checkout master
  473  git checkout debug
  474  nano main.c
  475  git commit -a -m "restored features with debug name"
  476  git checkout master
  477  git merge debug
  478  git branch
  479  git push
  480  git branch
  481  git status
  482  git status
  483  git add .
  484  git commit -a -m "update Fsilk pinout"
  485  git commit -a -m "update Fsilk pinout"
  486  git push
  487  git push
  488  git status
  489  git branch
  490  git branch -d debug
  491  git branch
  492  git commit
  493  git commit -a -m "add real connections on PCB outport"
  494  git status
  495  git push
  496  git commit
  497  git commit -a -m "add real connections on PCB outport"
  498  git push
  499  startx
  500  history
```
