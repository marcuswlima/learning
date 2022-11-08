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
PRINT N'Rename refactoring operation with key 49c9c2c3-bd5d-448d-920a-c113fa796fb3 is skipped, element [dbo].[Dim_Marca].[cod_marca] (SqlSimpleColumn) will not be renamed to Cod_Marca';


GO
PRINT N'Rename refactoring operation with key 184e9939-ff7d-4d47-846e-9cf46730690a is skipped, element [dbo].[Dim_Marca].[desc_marca] (SqlSimpleColumn) will not be renamed to Desc_Marca';


GO
PRINT N'Rename refactoring operation with key b22dee5f-6ea7-42ca-ac52-830ab26e4cae is skipped, element [dbo].[Dim_Marca].[cod_categoria] (SqlSimpleColumn) will not be renamed to Cod_Categoria';


GO
PRINT N'Creating Table [dbo].[Dim_Categoria]...';


GO
CREATE TABLE [dbo].[Dim_Categoria] (
    [Cod_Categoria]  NVARCHAR (50)  NOT NULL,
    [Desc_Categoria] NVARCHAR (250) NOT NULL,
    PRIMARY KEY CLUSTERED ([Cod_Categoria] ASC)
);


GO
PRINT N'Creating Table [dbo].[Dim_Marca]...';


GO
CREATE TABLE [dbo].[Dim_Marca] (
    [Cod_Marca]     NVARCHAR (50)  NOT NULL,
    [Desc_Marca]    NVARCHAR (250) NULL,
    [Cod_Categoria] NVARCHAR (50)  NULL,
    PRIMARY KEY CLUSTERED ([Cod_Marca] ASC)
);


GO
PRINT N'Creating Table [dbo].[Dim_Produto]...';


GO
CREATE TABLE [dbo].[Dim_Produto] (
    [Cod_Produto]  NVARCHAR (50)  NOT NULL,
    [Desc_Produto] NVARCHAR (250) NULL,
    [Atr_Tamanho]  NVARCHAR (250) NULL,
    [Atr_Sabor]    NVARCHAR (250) NULL,
    [Cod_Marca]    NVARCHAR (50)  NULL,
    PRIMARY KEY CLUSTERED ([Cod_Produto] ASC)
);


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Marca]...';


GO
ALTER TABLE [dbo].[Dim_Marca]
    ADD DEFAULT NULL FOR [Desc_Marca];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Marca]...';


GO
ALTER TABLE [dbo].[Dim_Marca]
    ADD DEFAULT NULL FOR [Cod_Categoria];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto]
    ADD DEFAULT NULL FOR [Desc_Produto];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto]
    ADD DEFAULT NULL FOR [Atr_Tamanho];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto]
    ADD DEFAULT NULL FOR [Atr_Sabor];


GO
PRINT N'Creating Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto]
    ADD DEFAULT NULL FOR [Cod_Marca];


GO
PRINT N'Creating Foreign Key [dbo].[FK_Dim_Marca_Dim_Categoria]...';


GO
ALTER TABLE [dbo].[Dim_Marca] WITH NOCHECK
    ADD CONSTRAINT [FK_Dim_Marca_Dim_Categoria] FOREIGN KEY ([Cod_Categoria]) REFERENCES [dbo].[Dim_Categoria] ([Cod_Categoria]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Dim_Produto_Dim_Marca]...';


GO
ALTER TABLE [dbo].[Dim_Produto] WITH NOCHECK
    ADD CONSTRAINT [FK_Dim_Produto_Dim_Marca] FOREIGN KEY ([Cod_Marca]) REFERENCES [dbo].[Dim_Marca] ([Cod_Marca]);


GO
-- Refactoring step to update target server with deployed transaction logs
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '49c9c2c3-bd5d-448d-920a-c113fa796fb3')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('49c9c2c3-bd5d-448d-920a-c113fa796fb3')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '184e9939-ff7d-4d47-846e-9cf46730690a')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('184e9939-ff7d-4d47-846e-9cf46730690a')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = 'b22dee5f-6ea7-42ca-ac52-830ab26e4cae')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('b22dee5f-6ea7-42ca-ac52-830ab26e4cae')

GO

GO
PRINT N'Checking existing data against newly created constraints';


GO
USE [$(DatabaseName)];


GO
ALTER TABLE [dbo].[Dim_Marca] WITH CHECK CHECK CONSTRAINT [FK_Dim_Marca_Dim_Categoria];

ALTER TABLE [dbo].[Dim_Produto] WITH CHECK CHECK CONSTRAINT [FK_Dim_Produto_Dim_Marca];


GO
PRINT N'Update complete.';


GO
