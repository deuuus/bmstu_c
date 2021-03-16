@ECHO OFF
FOR /L %%B IN (1, 1, 1) DO (call test.cmd 0%%B)
DEL out.txt