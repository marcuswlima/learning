﻿/*
Deployment script for dwsucos

This code was generated by a tool.
Changes to this file may cause incorrect behavior and will be lost if
the code is regenerated.
*/

GO
SET ANSI_NULLS, ANSI_PADDING, ANSI_WARNINGS, ARITHABORT, CONCAT_NULL_YIELDS_NULL, QUOTED_IDENTIFIER ON;

SET NUMERIC_ROUNDABORT OFF;


GO
:setvar DatabaseName "dwsucos"
:setvar DefaultFilePrefix "dwsucos"
:setvar DefaultDataPath "C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\"
:setvar DefaultLogPath "C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\"

GO
:on error exit
GO
/*
Detect SQLCMD mode and disable script execution if SQLCMD mode is not supported.
To re-enable the script after enabling SQLCMD mode, execute the following:
SET NOEXEC OFF; 
*/
:setvar __IsSqlCmdEnabled "True"
GO
IF N'$(__IsSqlCmdEnabled)' NOT LIKE N'True'
    BEGIN
        PRINT N'SQLCMD mode must be enabled to successfully execute this script.';
        SET NOEXEC ON;
    END


GO
USE [$(DatabaseName)];


GO
PRINT N'Rename refactoring operation with key 7787ad1a-cdf7-4b7e-9a44-b9496ce465b2 is skipped, element [dbo].[Dim_Organizacional].[cod_organizacional] (SqlSimpleColumn) will not be renamed to Cod_Filho';


GO
PRINT N'Rename refactoring operation with key 771f81d0-4271-4379-b90b-dac3c1d1fc20 is skipped, element [dbo].[Dim_Organizacional].[desc_organizacional] (SqlSimpleColumn) will not be renamed to Desc_Filho';


GO
PRINT N'Rename refactoring operation with key ab66a156-3104-4c14-a6ad-ea95e3cabb0b is skipped, element [dbo].[Dim_Organizacional].[cod_oraganizacional_pai] (SqlSimpleColumn) will not be renamed to Cod_Pai';


GO
PRINT N'Rename refactoring operation with key 750b25eb-cd19-443b-9bb4-3ee4bb85f632 is skipped, element [dbo].[Dim_Organizacional].[esquerda] (SqlSimpleColumn) will not be renamed to Esquerda';


GO
PRINT N'Rename refactoring operation with key 1f3c1a21-97d1-47eb-8f75-2d79666fddf9 is skipped, element [dbo].[Dim_Organizacional].[direita] (SqlSimpleColumn) will not be renamed to Direita';


GO
PRINT N'Rename refactoring operation with key 110c94b9-c16b-46e6-8ca3-4e1d31cff919 is skipped, element [dbo].[Dim_Organizacional].[nivel] (SqlSimpleColumn) will not be renamed to Nivel';


GO
PRINT N'Creating Table [dbo].[Dim_Organizacional]...';


GO
CREATE TABLE [dbo].[Dim_Organizacional] (
    [Cod_Filho]  NVARCHAR (50)  NOT NULL,
    [Desc_Filho] NVARCHAR (250) NULL,
    [Cod_Pai]    NVARCHAR (50)  NULL,
    [Esquerda]   INT            NULL,
    [Direita]    INT            NULL,
    [Nivel]      INT            NULL,
    PRIMARY KEY CLUSTERED ([Cod_Filho] ASC)
);


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional]
    ADD DEFAULT NULL FOR [Desc_Filho];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional]
    ADD DEFAULT NULL FOR [Cod_Pai];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional]
    ADD DEFAULT NULL FOR [Esquerda];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional]
    ADD DEFAULT NULL FOR [Direita];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional]
    ADD DEFAULT NULL FOR [Nivel];


GO
PRINT N'Creating Foreign Key [dbo].[FK_Dim_Organizacional_Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] WITH NOCHECK
    ADD CONSTRAINT [FK_Dim_Organizacional_Dim_Organizacional] FOREIGN KEY ([Cod_Pai]) REFERENCES [dbo].[Dim_Organizacional] ([Cod_Filho]);


GO
-- Refactoring step to update target server with deployed transaction logs
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '7787ad1a-cdf7-4b7e-9a44-b9496ce465b2')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('7787ad1a-cdf7-4b7e-9a44-b9496ce465b2')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '771f81d0-4271-4379-b90b-dac3c1d1fc20')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('771f81d0-4271-4379-b90b-dac3c1d1fc20')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = 'ab66a156-3104-4c14-a6ad-ea95e3cabb0b')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('ab66a156-3104-4c14-a6ad-ea95e3cabb0b')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '750b25eb-cd19-443b-9bb4-3ee4bb85f632')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('750b25eb-cd19-443b-9bb4-3ee4bb85f632')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '1f3c1a21-97d1-47eb-8f75-2d79666fddf9')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('1f3c1a21-97d1-47eb-8f75-2d79666fddf9')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '110c94b9-c16b-46e6-8ca3-4e1d31cff919')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('110c94b9-c16b-46e6-8ca3-4e1d31cff919')

GO

GO
PRINT N'Checking existing data against newly created constraints';


GO
USE [$(DatabaseName)];


GO
ALTER TABLE [dbo].[Dim_Organizacional] WITH CHECK CHECK CONSTRAINT [FK_Dim_Organizacional_Dim_Organizacional];


GO
PRINT N'Update complete.';


GO