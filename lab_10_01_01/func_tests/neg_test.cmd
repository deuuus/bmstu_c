@ECHO OFF
IF "%1"=="" ECHO NOT ENOUGH PARAMETERS... & GOTO :END
SET /P var=<.\neg_%~1_args.txt
..\app.exe %var%
IF %ERRORLEVEL% EQU 0 ECHO NEG TEST %~1 ::FAIL:: RETURN CODE IS ZERO... & GOTO :END
FC /N .\neg_%~1_out.txt out.txt
DEL out.txt
:END