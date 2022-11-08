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
/*
The column Desc_Filho on table [dbo].[Dim_Organizacional] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.

The column Direita on table [dbo].[Dim_Organizacional] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.

The column Esquerda on table [dbo].[Dim_Organizacional] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.

The column Nivel on table [dbo].[Dim_Organizacional] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.
*/

IF EXISTS (select top 1 1 from [dbo].[Dim_Organizacional])
    RAISERROR (N'Rows were detected. The schema update is terminating because data loss might occur.', 16, 127) WITH NOWAIT

GO
/*
The column Custo_Variavel on table [dbo].[Fato_001] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.

The column Faturamento on table [dbo].[Fato_001] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.

The column Imposto on table [dbo].[Fato_001] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.

The column Quantidade_Vendida on table [dbo].[Fato_001] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.

The column Unidade_vendida on table [dbo].[Fato_001] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.
*/

IF EXISTS (select top 1 1 from [dbo].[Fato_001])
    RAISERROR (N'Rows were detected. The schema update is terminating because data loss might occur.', 16, 127) WITH NOWAIT

GO
/*
The column Frete on table [dbo].[Fato_002] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.
*/

IF EXISTS (select top 1 1 from [dbo].[Fato_002])
    RAISERROR (N'Rows were detected. The schema update is terminating because data loss might occur.', 16, 127) WITH NOWAIT

GO
/*
The column Custo_Fixo on table [dbo].[Fato_003] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.
*/

IF EXISTS (select top 1 1 from [dbo].[Fato_003])
    RAISERROR (N'Rows were detected. The schema update is terminating because data loss might occur.', 16, 127) WITH NOWAIT

GO
/*
The column Meta_Faturamento on table [dbo].[Fato_004] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.
*/

IF EXISTS (select top 1 1 from [dbo].[Fato_004])
    RAISERROR (N'Rows were detected. The schema update is terminating because data loss might occur.', 16, 127) WITH NOWAIT

GO
/*
The column Meta_Custo on table [dbo].[Fato_005] must be changed from NULL to NOT NULL. If the table contains data, the ALTER script may not work. To avoid this issue, you must add values to this column for all rows or mark it as allowing NULL values, or enable the generation of smart-defaults as a deployment option.
*/

IF EXISTS (select top 1 1 from [dbo].[Fato_005])
    RAISERROR (N'Rows were detected. The schema update is terminating because data loss might occur.', 16, 127) WITH NOWAIT

GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] DROP CONSTRAINT [DF__Dim_Organ__Desc___4222D4EF];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] DROP CONSTRAINT [DF__Dim_Organ__Direi__44FF419A];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] DROP CONSTRAINT [DF__Dim_Organ__Esque__440B1D61];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] DROP CONSTRAINT [DF__Dim_Organ__Nivel__45F365D3];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_001]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [DF__Fato_001__Custo___5070F446];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_001]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [DF__Fato_001__Fatura__4E88ABD4];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_001]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [DF__Fato_001__Impost__4F7CD00D];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_001]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [DF__Fato_001__Quanti__52593CB8];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_001]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [DF__Fato_001__Unidad__5165187F];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_002]...';


GO
ALTER TABLE [dbo].[Fato_002] DROP CONSTRAINT [DF__Fato_002__Frete__59FA5E80];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_003]...';


GO
ALTER TABLE [dbo].[Fato_003] DROP CONSTRAINT [DF__Fato_003__Custo___6477ECF3];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_004]...';


GO
ALTER TABLE [dbo].[Fato_004] DROP CONSTRAINT [DF__Fato_004__Meta_F__656C112C];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Fato_005]...';


GO
ALTER TABLE [dbo].[Fato_005] DROP CONSTRAINT [DF__Fato_005__Meta_C__66603565];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Marca]...';


GO
ALTER TABLE [dbo].[Dim_Marca] DROP CONSTRAINT [DF__Dim_Marca__Desc___2E1BDC42];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Marca]...';


GO
ALTER TABLE [dbo].[Dim_Marca] DROP CONSTRAINT [DF__Dim_Marca__Cod_C__2F10007B];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] DROP CONSTRAINT [DF__Dim_Organ__Cod_P__4316F928];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto] DROP CONSTRAINT [DF__Dim_Produ__Desc___300424B4];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto] DROP CONSTRAINT [DF__Dim_Produ__Atr_T__30F848ED];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto] DROP CONSTRAINT [DF__Dim_Produ__Atr_S__31EC6D26];


GO
PRINT N'Dropping Default Constraint unnamed constraint on [dbo].[Dim_Produto]...';


GO
ALTER TABLE [dbo].[Dim_Produto] DROP CONSTRAINT [DF__Dim_Produ__Cod_M__32E0915F];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_001_Dim_Cliente]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [FK_Fato_001_Dim_Cliente];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_002_Dim_Cliente]...';


GO
ALTER TABLE [dbo].[Fato_002] DROP CONSTRAINT [FK_Fato_002_Dim_Cliente];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_004_Dim_Cliente]...';


GO
ALTER TABLE [dbo].[Fato_004] DROP CONSTRAINT [FK_Fato_004_Dim_Cliente];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_001_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [FK_Fato_001_Dim_Fabrica];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_002_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_002] DROP CONSTRAINT [FK_Fato_002_Dim_Fabrica];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_003_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_003] DROP CONSTRAINT [FK_Fato_003_Dim_Fabrica];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_005_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_005] DROP CONSTRAINT [FK_Fato_005_Dim_Fabrica];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Dim_Produto_Dim_Marca]...';


GO
ALTER TABLE [dbo].[Dim_Produto] DROP CONSTRAINT [FK_Dim_Produto_Dim_Marca];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Dim_Marca_Dim_Categoria]...';


GO
ALTER TABLE [dbo].[Dim_Marca] DROP CONSTRAINT [FK_Dim_Marca_Dim_Categoria];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Dim_Organizacional_Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] DROP CONSTRAINT [FK_Dim_Organizacional_Dim_Organizacional];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_001_Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [FK_Fato_001_Dim_Organizacional];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_004_Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Fato_004] DROP CONSTRAINT [FK_Fato_004_Dim_Organizacional];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_001_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [FK_Fato_001_Dim_Produto];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_002_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_002] DROP CONSTRAINT [FK_Fato_002_Dim_Produto];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_004_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_004] DROP CONSTRAINT [FK_Fato_004_Dim_Produto];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_005_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_005] DROP CONSTRAINT [FK_Fato_005_Dim_Produto];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_001_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_001] DROP CONSTRAINT [FK_Fato_001_Dim_Tempo];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_002_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_002] DROP CONSTRAINT [FK_Fato_002_Dim_Tempo];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_003_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_003] DROP CONSTRAINT [FK_Fato_003_Dim_Tempo];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_004_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_004] DROP CONSTRAINT [FK_Fato_004_Dim_Tempo];


GO
PRINT N'Dropping Foreign Key [dbo].[FK_Fato_005_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_005] DROP CONSTRAINT [FK_Fato_005_Dim_Tempo];


GO
PRINT N'Altering Table [dbo].[Dim_Categoria]...';


GO
ALTER TABLE [dbo].[Dim_Categoria] ALTER COLUMN [Desc_Categoria] NVARCHAR (250) NULL;


GO
PRINT N'Starting rebuilding table [dbo].[Dim_Cliente]...';


GO
BEGIN TRANSACTION;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SET XACT_ABORT ON;

CREATE TABLE [dbo].[tmp_ms_xx_Dim_Cliente] (
    [Cod_Cliente]   NVARCHAR (50)  NOT NULL,
    [Desc_Cliente]  NVARCHAR (250) NULL,
    [cod_cidade]    NVARCHAR (50)  NULL,
    [Desc_Cidade]   NVARCHAR (250) NULL,
    [Cod_Eestato]   NVARCHAR (50)  NULL,
    [Desc_Estado]   NVARCHAR (250) NULL,
    [Cod_Regiao]    NVARCHAR (50)  NULL,
    [Desc_Regiao]   NVARCHAR (250) NULL,
    [Cod_Segmento]  NVARCHAR (50)  NULL,
    [Desc_Segmento] NVARCHAR (250) NULL,
    CONSTRAINT [tmp_ms_xx_constraint_PK_Dim_Cliente1] PRIMARY KEY CLUSTERED ([Cod_Cliente] ASC)
);

IF EXISTS (SELECT TOP 1 1 
           FROM   [dbo].[Dim_Cliente])
    BEGIN
        INSERT INTO [dbo].[tmp_ms_xx_Dim_Cliente] ([Cod_Cliente], [Desc_Cliente], [cod_cidade], [Desc_Cidade], [Cod_Eestato], [Desc_Estado], [Cod_Regiao], [Desc_Regiao], [Cod_Segmento], [Desc_Segmento])
        SELECT   [Cod_Cliente],
                 [Desc_Cliente],
                 [cod_cidade],
                 [Desc_Cidade],
                 [Cod_Eestato],
                 [Desc_Estado],
                 [Cod_Regiao],
                 [Desc_Regiao],
                 [Cod_Segmento],
                 [Desc_Segmento]
        FROM     [dbo].[Dim_Cliente]
        ORDER BY [Cod_Cliente] ASC;
    END

DROP TABLE [dbo].[Dim_Cliente];

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_Dim_Cliente]', N'Dim_Cliente';

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_constraint_PK_Dim_Cliente1]', N'PK_Dim_Cliente', N'OBJECT';

COMMIT TRANSACTION;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;


GO
PRINT N'Starting rebuilding table [dbo].[Dim_Organizacional]...';


GO
BEGIN TRANSACTION;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SET XACT_ABORT ON;

CREATE TABLE [dbo].[tmp_ms_xx_Dim_Organizacional] (
    [Cod_Filho]  NVARCHAR (50)  NOT NULL,
    [Desc_Filho] NVARCHAR (250) NOT NULL,
    [Cod_Pai]    NVARCHAR (50)  NULL,
    [Esquerda]   INT            NOT NULL,
    [Direita]    INT            NOT NULL,
    [Nivel]      INT            NOT NULL,
    CONSTRAINT [tmp_ms_xx_constraint_PK_Dim_Organizacional1] PRIMARY KEY CLUSTERED ([Cod_Filho] ASC)
);

IF EXISTS (SELECT TOP 1 1 
           FROM   [dbo].[Dim_Organizacional])
    BEGIN
        INSERT INTO [dbo].[tmp_ms_xx_Dim_Organizacional] ([Cod_Filho], [Desc_Filho], [Cod_Pai], [Esquerda], [Direita], [Nivel])
        SELECT   [Cod_Filho],
                 [Desc_Filho],
                 [Cod_Pai],
                 [Esquerda],
                 [Direita],
                 [Nivel]
        FROM     [dbo].[Dim_Organizacional]
        ORDER BY [Cod_Filho] ASC;
    END

DROP TABLE [dbo].[Dim_Organizacional];

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_Dim_Organizacional]', N'Dim_Organizacional';

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_constraint_PK_Dim_Organizacional1]', N'PK_Dim_Organizacional', N'OBJECT';

COMMIT TRANSACTION;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;


GO
PRINT N'Altering Table [dbo].[Fato_001]...';


GO
ALTER TABLE [dbo].[Fato_001] ALTER COLUMN [Custo_Variavel] FLOAT (53) NOT NULL;

ALTER TABLE [dbo].[Fato_001] ALTER COLUMN [Faturamento] FLOAT (53) NOT NULL;

ALTER TABLE [dbo].[Fato_001] ALTER COLUMN [Imposto] FLOAT (53) NOT NULL;

ALTER TABLE [dbo].[Fato_001] ALTER COLUMN [Quantidade_Vendida] FLOAT (53) NOT NULL;

ALTER TABLE [dbo].[Fato_001] ALTER COLUMN [Unidade_vendida] FLOAT (53) NOT NULL;


GO
PRINT N'Altering Table [dbo].[Fato_002]...';


GO
ALTER TABLE [dbo].[Fato_002] ALTER COLUMN [Frete] FLOAT (53) NOT NULL;


GO
PRINT N'Altering Table [dbo].[Fato_003]...';


GO
ALTER TABLE [dbo].[Fato_003] ALTER COLUMN [Custo_Fixo] FLOAT (53) NOT NULL;


GO
PRINT N'Altering Table [dbo].[Fato_004]...';


GO
ALTER TABLE [dbo].[Fato_004] ALTER COLUMN [Meta_Faturamento] FLOAT (53) NOT NULL;


GO
PRINT N'Altering Table [dbo].[Fato_005]...';


GO
ALTER TABLE [dbo].[Fato_005] ALTER COLUMN [Meta_Custo] FLOAT (53) NOT NULL;


GO
PRINT N'Starting rebuilding table [dbo].[Dim_Fabrica]...';


GO
BEGIN TRANSACTION;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SET XACT_ABORT ON;

CREATE TABLE [dbo].[tmp_ms_xx_Dim_Fabrica] (
    [Cod_fabrica]  NVARCHAR (50)  NOT NULL,
    [Desc_Fabrica] NVARCHAR (200) NULL,
    CONSTRAINT [tmp_ms_xx_constraint_PK_Dim_Fabrica1] PRIMARY KEY CLUSTERED ([Cod_fabrica] ASC)
);

IF EXISTS (SELECT TOP 1 1 
           FROM   [dbo].[Dim_Fabrica])
    BEGIN
        INSERT INTO [dbo].[tmp_ms_xx_Dim_Fabrica] ([Cod_fabrica], [Desc_Fabrica])
        SELECT   [Cod_fabrica],
                 [Desc_Fabrica]
        FROM     [dbo].[Dim_Fabrica]
        ORDER BY [Cod_fabrica] ASC;
    END

DROP TABLE [dbo].[Dim_Fabrica];

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_Dim_Fabrica]', N'Dim_Fabrica';

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_constraint_PK_Dim_Fabrica1]', N'PK_Dim_Fabrica', N'OBJECT';

COMMIT TRANSACTION;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;


GO
PRINT N'Starting rebuilding table [dbo].[Dim_Marca]...';


GO
BEGIN TRANSACTION;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SET XACT_ABORT ON;

CREATE TABLE [dbo].[tmp_ms_xx_Dim_Marca] (
    [Cod_Marca]     NVARCHAR (50)  NOT NULL,
    [Desc_Marca]    NVARCHAR (250) NULL,
    [Cod_Categoria] NVARCHAR (50)  NULL,
    CONSTRAINT [tmp_ms_xx_constraint_PK_Dim_Marca1] PRIMARY KEY CLUSTERED ([Cod_Marca] ASC)
);

IF EXISTS (SELECT TOP 1 1 
           FROM   [dbo].[Dim_Marca])
    BEGIN
        INSERT INTO [dbo].[tmp_ms_xx_Dim_Marca] ([Cod_Marca], [Desc_Marca], [Cod_Categoria])
        SELECT   [Cod_Marca],
                 [Desc_Marca],
                 [Cod_Categoria]
        FROM     [dbo].[Dim_Marca]
        ORDER BY [Cod_Marca] ASC;
    END

DROP TABLE [dbo].[Dim_Marca];

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_Dim_Marca]', N'Dim_Marca';

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_constraint_PK_Dim_Marca1]', N'PK_Dim_Marca', N'OBJECT';

COMMIT TRANSACTION;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;


GO
PRINT N'Creating Index [dbo].[Dim_Marca].[IX_Dim_Marca_Cod_Categoria]...';


GO
CREATE NONCLUSTERED INDEX [IX_Dim_Marca_Cod_Categoria]
    ON [dbo].[Dim_Marca]([Cod_Categoria] ASC);


GO
PRINT N'Starting rebuilding table [dbo].[Dim_Produto]...';


GO
BEGIN TRANSACTION;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SET XACT_ABORT ON;

CREATE TABLE [dbo].[tmp_ms_xx_Dim_Produto] (
    [Cod_Produto]  NVARCHAR (50)  NOT NULL,
    [Desc_Produto] NVARCHAR (250) NULL,
    [Atr_Tamanho]  NVARCHAR (250) NULL,
    [Atr_Sabor]    NVARCHAR (250) NULL,
    [Cod_Marca]    NVARCHAR (50)  NULL,
    CONSTRAINT [tmp_ms_xx_constraint_PK_Dim_Produto1] PRIMARY KEY CLUSTERED ([Cod_Produto] ASC)
);

IF EXISTS (SELECT TOP 1 1 
           FROM   [dbo].[Dim_Produto])
    BEGIN
        INSERT INTO [dbo].[tmp_ms_xx_Dim_Produto] ([Cod_Produto], [Desc_Produto], [Atr_Tamanho], [Atr_Sabor], [Cod_Marca])
        SELECT   [Cod_Produto],
                 [Desc_Produto],
                 [Atr_Tamanho],
                 [Atr_Sabor],
                 [Cod_Marca]
        FROM     [dbo].[Dim_Produto]
        ORDER BY [Cod_Produto] ASC;
    END

DROP TABLE [dbo].[Dim_Produto];

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_Dim_Produto]', N'Dim_Produto';

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_constraint_PK_Dim_Produto1]', N'PK_Dim_Produto', N'OBJECT';

COMMIT TRANSACTION;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;


GO
PRINT N'Starting rebuilding table [dbo].[Dim_Tempo]...';


GO
BEGIN TRANSACTION;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SET XACT_ABORT ON;

CREATE TABLE [dbo].[tmp_ms_xx_Dim_Tempo] (
    [Cod_Dia]            NVARCHAR (50) NOT NULL,
    [Data]               DATE          NULL,
    [Cod_Semana]         INT           NULL,
    [Nome_Dis_Semana]    NVARCHAR (50) NULL,
    [Cod_Mes]            INT           NULL,
    [Nome_Mes]           NVARCHAR (50) NULL,
    [Cod_Mes_Ano]        NVARCHAR (50) NULL,
    [Nome_Mes_Ano]       NVARCHAR (50) NULL,
    [Cod_Trimestre]      INT           NULL,
    [Nome_Trimestre]     NVARCHAR (50) NULL,
    [Cod_Trimestre_Ano]  INT           NULL,
    [Nome_Trimestre_Ano] NVARCHAR (50) NULL,
    [Cod_Senestre]       INT           NULL,
    [Nome_Semestre]      NVARCHAR (50) NULL,
    [Cod_Semestre_Ano]   INT           NULL,
    [Nome_Semestre_Ano]  NVARCHAR (50) NULL,
    [Ano]                INT           NULL,
    [Tipo_Dia]           NVARCHAR (50) NULL,
    CONSTRAINT [tmp_ms_xx_constraint_pk_Dim_Tempo1] PRIMARY KEY CLUSTERED ([Cod_Dia] ASC)
);

IF EXISTS (SELECT TOP 1 1 
           FROM   [dbo].[Dim_Tempo])
    BEGIN
        INSERT INTO [dbo].[tmp_ms_xx_Dim_Tempo] ([Cod_Dia], [Data], [Cod_Semana], [Nome_Dis_Semana], [Cod_Mes], [Nome_Mes], [Cod_Mes_Ano], [Nome_Mes_Ano], [Cod_Trimestre], [Nome_Trimestre], [Cod_Trimestre_Ano], [Nome_Trimestre_Ano], [Cod_Senestre], [Nome_Semestre], [Cod_Semestre_Ano], [Nome_Semestre_Ano], [Ano], [Tipo_Dia])
        SELECT   [Cod_Dia],
                 [Data],
                 [Cod_Semana],
                 [Nome_Dis_Semana],
                 [Cod_Mes],
                 [Nome_Mes],
                 [Cod_Mes_Ano],
                 [Nome_Mes_Ano],
                 [Cod_Trimestre],
                 [Nome_Trimestre],
                 [Cod_Trimestre_Ano],
                 [Nome_Trimestre_Ano],
                 [Cod_Senestre],
                 [Nome_Semestre],
                 [Cod_Semestre_Ano],
                 [Nome_Semestre_Ano],
                 [Ano],
                 [Tipo_Dia]
        FROM     [dbo].[Dim_Tempo]
        ORDER BY [Cod_Dia] ASC;
    END

DROP TABLE [dbo].[Dim_Tempo];

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_Dim_Tempo]', N'Dim_Tempo';

EXECUTE sp_rename N'[dbo].[tmp_ms_xx_constraint_pk_Dim_Tempo1]', N'pk_Dim_Tempo', N'OBJECT';

COMMIT TRANSACTION;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_001_Dim_Cliente]...';


GO
ALTER TABLE [dbo].[Fato_001] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_001_Dim_Cliente] FOREIGN KEY ([Cod_Cliente]) REFERENCES [dbo].[Dim_Cliente] ([Cod_Cliente]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_002_Dim_Cliente]...';


GO
ALTER TABLE [dbo].[Fato_002] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_002_Dim_Cliente] FOREIGN KEY ([Cod_Cliente]) REFERENCES [dbo].[Dim_Cliente] ([Cod_Cliente]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_004_Dim_Cliente]...';


GO
ALTER TABLE [dbo].[Fato_004] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_004_Dim_Cliente] FOREIGN KEY ([Cod_Cliente]) REFERENCES [dbo].[Dim_Cliente] ([Cod_Cliente]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_001_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_001] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_001_Dim_Fabrica] FOREIGN KEY ([Cod_Fabrica]) REFERENCES [dbo].[Dim_Fabrica] ([Cod_fabrica]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_002_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_002] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_002_Dim_Fabrica] FOREIGN KEY ([Cod_Fabrica]) REFERENCES [dbo].[Dim_Fabrica] ([Cod_fabrica]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_003_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_003] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_003_Dim_Fabrica] FOREIGN KEY ([Cod_Fabrica]) REFERENCES [dbo].[Dim_Fabrica] ([Cod_fabrica]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_005_Dim_Fabrica]...';


GO
ALTER TABLE [dbo].[Fato_005] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_005_Dim_Fabrica] FOREIGN KEY ([Cod_Fabrica]) REFERENCES [dbo].[Dim_Fabrica] ([Cod_fabrica]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Dim_Produto_Dim_Marca]...';


GO
ALTER TABLE [dbo].[Dim_Produto] WITH NOCHECK
    ADD CONSTRAINT [FK_Dim_Produto_Dim_Marca] FOREIGN KEY ([Cod_Marca]) REFERENCES [dbo].[Dim_Marca] ([Cod_Marca]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Dim_Marca_Dim_Categoria]...';


GO
ALTER TABLE [dbo].[Dim_Marca] WITH NOCHECK
    ADD CONSTRAINT [FK_Dim_Marca_Dim_Categoria] FOREIGN KEY ([Cod_Categoria]) REFERENCES [dbo].[Dim_Categoria] ([Cod_Categoria]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Dim_Organizacional_Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Dim_Organizacional] WITH NOCHECK
    ADD CONSTRAINT [FK_Dim_Organizacional_Dim_Organizacional] FOREIGN KEY ([Cod_Pai]) REFERENCES [dbo].[Dim_Organizacional] ([Cod_Filho]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_001_Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Fato_001] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_001_Dim_Organizacional] FOREIGN KEY ([Cod_Organizacional]) REFERENCES [dbo].[Dim_Organizacional] ([Cod_Filho]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_004_Dim_Organizacional]...';


GO
ALTER TABLE [dbo].[Fato_004] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_004_Dim_Organizacional] FOREIGN KEY ([Cod_Organizacional]) REFERENCES [dbo].[Dim_Organizacional] ([Cod_Filho]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_001_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_001] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_001_Dim_Produto] FOREIGN KEY ([Cod_Produto]) REFERENCES [dbo].[Dim_Produto] ([Cod_Produto]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_002_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_002] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_002_Dim_Produto] FOREIGN KEY ([Cod_Produto]) REFERENCES [dbo].[Dim_Produto] ([Cod_Produto]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_004_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_004] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_004_Dim_Produto] FOREIGN KEY ([Cod_Produto]) REFERENCES [dbo].[Dim_Produto] ([Cod_Produto]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_005_Dim_Produto]...';


GO
ALTER TABLE [dbo].[Fato_005] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_005_Dim_Produto] FOREIGN KEY ([Cod_Produto]) REFERENCES [dbo].[Dim_Produto] ([Cod_Produto]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_001_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_001] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_001_Dim_Tempo] FOREIGN KEY ([Cod_Dia]) REFERENCES [dbo].[Dim_Tempo] ([Cod_Dia]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_002_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_002] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_002_Dim_Tempo] FOREIGN KEY ([Cod_Dia]) REFERENCES [dbo].[Dim_Tempo] ([Cod_Dia]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_003_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_003] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_003_Dim_Tempo] FOREIGN KEY ([Cod_Dia]) REFERENCES [dbo].[Dim_Tempo] ([Cod_Dia]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_004_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_004] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_004_Dim_Tempo] FOREIGN KEY ([Cod_Dia]) REFERENCES [dbo].[Dim_Tempo] ([Cod_Dia]);


GO
PRINT N'Creating Foreign Key [dbo].[FK_Fato_005_Dim_Tempo]...';


GO
ALTER TABLE [dbo].[Fato_005] WITH NOCHECK
    ADD CONSTRAINT [FK_Fato_005_Dim_Tempo] FOREIGN KEY ([Cod_Dia]) REFERENCES [dbo].[Dim_Tempo] ([Cod_Dia]);


GO
PRINT N'Checking existing data against newly created constraints';


GO
USE [$(DatabaseName)];


GO
ALTER TABLE [dbo].[Fato_001] WITH CHECK CHECK CONSTRAINT [FK_Fato_001_Dim_Cliente];

ALTER TABLE [dbo].[Fato_002] WITH CHECK CHECK CONSTRAINT [FK_Fato_002_Dim_Cliente];

ALTER TABLE [dbo].[Fato_004] WITH CHECK CHECK CONSTRAINT [FK_Fato_004_Dim_Cliente];

ALTER TABLE [dbo].[Fato_001] WITH CHECK CHECK CONSTRAINT [FK_Fato_001_Dim_Fabrica];

ALTER TABLE [dbo].[Fato_002] WITH CHECK CHECK CONSTRAINT [FK_Fato_002_Dim_Fabrica];

ALTER TABLE [dbo].[Fato_003] WITH CHECK CHECK CONSTRAINT [FK_Fato_003_Dim_Fabrica];

ALTER TABLE [dbo].[Fato_005] WITH CHECK CHECK CONSTRAINT [FK_Fato_005_Dim_Fabrica];

ALTER TABLE [dbo].[Dim_Produto] WITH CHECK CHECK CONSTRAINT [FK_Dim_Produto_Dim_Marca];

ALTER TABLE [dbo].[Dim_Marca] WITH CHECK CHECK CONSTRAINT [FK_Dim_Marca_Dim_Categoria];

ALTER TABLE [dbo].[Dim_Organizacional] WITH CHECK CHECK CONSTRAINT [FK_Dim_Organizacional_Dim_Organizacional];

ALTER TABLE [dbo].[Fato_001] WITH CHECK CHECK CONSTRAINT [FK_Fato_001_Dim_Organizacional];

ALTER TABLE [dbo].[Fato_004] WITH CHECK CHECK CONSTRAINT [FK_Fato_004_Dim_Organizacional];

ALTER TABLE [dbo].[Fato_001] WITH CHECK CHECK CONSTRAINT [FK_Fato_001_Dim_Produto];

ALTER TABLE [dbo].[Fato_002] WITH CHECK CHECK CONSTRAINT [FK_Fato_002_Dim_Produto];

ALTER TABLE [dbo].[Fato_004] WITH CHECK CHECK CONSTRAINT [FK_Fato_004_Dim_Produto];

ALTER TABLE [dbo].[Fato_005] WITH CHECK CHECK CONSTRAINT [FK_Fato_005_Dim_Produto];

ALTER TABLE [dbo].[Fato_001] WITH CHECK CHECK CONSTRAINT [FK_Fato_001_Dim_Tempo];

ALTER TABLE [dbo].[Fato_002] WITH CHECK CHECK CONSTRAINT [FK_Fato_002_Dim_Tempo];

ALTER TABLE [dbo].[Fato_003] WITH CHECK CHECK CONSTRAINT [FK_Fato_003_Dim_Tempo];

ALTER TABLE [dbo].[Fato_004] WITH CHECK CHECK CONSTRAINT [FK_Fato_004_Dim_Tempo];

ALTER TABLE [dbo].[Fato_005] WITH CHECK CHECK CONSTRAINT [FK_Fato_005_Dim_Tempo];


GO
PRINT N'Update complete.';


GO
