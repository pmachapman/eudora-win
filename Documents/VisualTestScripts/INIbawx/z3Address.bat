@echo off
del Eudora.ini
cp Eudora.adr Eudora.ini
del RCPdbase.txt
del nndbase.toc
del nndbase.txt
cd statio~1
del test*.*
cd..
cd Sigs
del test*.*
cd..
del test*.mbx
del test*.toc
del test2.fol
rmdir test2.fol
del filters.pce
pause