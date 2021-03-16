@ECHO OFF
FOR /L %%B IN (1, 1, 2) DO (call test.cmd 0%%B)
DEL out.txt