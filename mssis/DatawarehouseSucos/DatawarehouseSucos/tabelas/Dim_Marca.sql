CREATE TABLE [dbo].[Dim_Marca]
(
	[Cod_Marca] NVARCHAR(50),
	[Desc_Marca] NVARCHAR(250),
	[Cod_Categoria] NVARCHAR(50), 
    CONSTRAINT PK_Dim_Marca PRIMARY KEY (Cod_Marca) ,
    CONSTRAINT FK_Dim_Marca_Dim_Categoria FOREIGN KEY (Cod_Categoria) REFERENCES Dim_Categoria
)

GO

CREATE INDEX [IX_Dim_Marca_Cod_Categoria] ON [dbo].[Dim_Marca] (Cod_Categoria)
