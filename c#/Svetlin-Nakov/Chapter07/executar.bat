@echo off 

:cls

C:\Windows\Microsoft.NET\Framework\v4.0.30319\csc.exe  .\Exercicio%1.cs /nologo

IF %ERRORLEVEL% EQU 0 ( 
    .\Exercicio%1.exe
	
	del .\Exercicio%1.exe
)
