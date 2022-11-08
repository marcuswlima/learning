CREATE TABLE [dbo].[Dim_Produto]
(
	[Cod_Produto] NVARCHAR(50) ,
	[Desc_Produto] NVARCHAR(250) ,
	[Atr_Tamanho] NVARCHAR(250) ,
	[Atr_Sabor] NVARCHAR(250) ,
	[Cod_Marca] NVARCHAR(50) , 
	CONSTRAINT PK_Dim_Produto PRIMARY KEY ([Cod_Produto]),
    CONSTRAINT [FK_Dim_Produto_Dim_Marca] FOREIGN KEY ([Cod_Marca]) REFERENCES [Dim_Marca]([Cod_Marca])
)
