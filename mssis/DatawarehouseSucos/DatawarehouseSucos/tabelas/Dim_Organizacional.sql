CREATE TABLE [dbo].[Dim_Organizacional]
(
  [Cod_Filho] NVARCHAR(50) ,
  [Desc_Filho] NVARCHAR(250) NOT NULL,
  [Cod_Pai] NVARCHAR(50) ,
  [Esquerda] INT NOT NULL,
  [Direita] INT NOT NULL,
  [Nivel] INT NOT NULL, 
  CONSTRAINT PK_Dim_Organizacional PRIMARY KEY ([Cod_Filho]),
    CONSTRAINT [FK_Dim_Organizacional_Dim_Organizacional] FOREIGN KEY ([Cod_Pai]) REFERENCES [Dim_Organizacional]([Cod_Filho])
)
