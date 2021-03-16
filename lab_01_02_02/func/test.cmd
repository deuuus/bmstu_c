@ECHO OFF
IF "%1"=="" ECHO NOT ENOUG PARAMETERS... & GOTO :END
..\app.exe <test_%~1_in.txt >out.txt
IF %ERRORLEVEL% NEQ 0 ECHO TEST %~1 ::FAIL:: RETURN CODE IS ZERO... & GOTO :END
FC /N test_%~1_out.txt out.txt
:END